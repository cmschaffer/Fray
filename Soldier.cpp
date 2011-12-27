//
//  Soldier.cpp
//  ArmySystem
//
//  Created by Christopher Ingebrigtsen on 12/27/11.
//  Copyright (c) 2011 Bellyflop. All rights reserved.
//

#include "Soldier.h"
using namespace std;

//base construtor for Soldier
Soldier::Soldier()
{
	this->level = 1;
	this->body = 8;
	this->armor = 20;
	this->defense = 7;
	this->offense = 3;
	this->atckSpeed = 1;
	this->damage = 2;
	this->morale = 3;
	this->status = SOLDIER_OK;
    
	this->at_Loc_Flag = 0;
	this->atckd_Flag = 0;
}

Soldier::Soldier(int nLevel, int nBody, int nArmor, int nDefense, int nOffense, int nAtckSpeed, int nDamage,
                 int nMorale,int nTeam, Orders nCurrent, Location nPlace)
{
    this->level = nLevel;
    this->body = nBody;
    this->armor = nArmor;
    this->defense = nDefense;
    this->offense = nOffense;
    this->atckSpeed = nAtckSpeed;
    this->damage = nDamage;
    this->morale = nMorale;
    this->team = nTeam;
    this->current = nCurrent;
    this-> place = nPlace;
    
    this->at_Loc_Flag = 0;
    this->atckd_Flag = 0;
    
}


int Soldier::Dice(int type)
{
    
	int value = rand() % type + 1;
    
	return value;
    
}

bool Soldier::Move()
{
	if(this->place.x_value == current.loc_target.x_value && this->place.y_value == this->current.loc_target.y_value) // checks if current place matches destination
		this->at_Loc_Flag = 1;
	else
        {
		if(this->place.x_value < this->current.loc_target.x_value)       // this block moves the soldier
			this->place.x_value++;
		else if(this->place.x_value > this->current.loc_target.x_value)
			this->place.x_value--;
        
		if(this->place.y_value < this->current.loc_target.y_value)
			this->place.y_value++;
		else if(this->place.y_value > this->current.loc_target.y_value)
			this->place.y_value--;
        }
    
	if(this->place.x_value == this->current.loc_target.x_value && this->place.y_value == this->current.loc_target.y_value) // checks again because action can take place on same round after move
		this->at_Loc_Flag = 1;
    
    
    
	return this->at_Loc_Flag;
	
}


void Soldier::Act()
{
	switch(current.action)   // this swtich contains all possible actions
	{
		case 1: this->Attack(current.target);
        break;
		case 2: this->Wait();
        break;
		default: cerr<< "error in Soldier::Act() : current.action int not recognized";
	}
    
}


void Soldier::Attack(Soldier* target)
{
    
	{
    for(int j = 0; j < this->atckSpeed; j++)   
		{
        this->Swing(target);
        cout<< "swing"<< endl;
		}
	}
    
}

void Soldier::Swing(Soldier* defender)
{ 
    
    if(!defender)//Always null check, so you don't call functions on a null pointer
        return;
    
	int atckRoll = offense + Dice(20);
	int defRoll = defender->getDef();
    
	defender->atckd_Flag = 1;
    
	if(atckRoll > defRoll)
        {
		cout<< "hit!" << endl;
		defender->TakeDamage(this->damage);
        }
    
}

//Soldeer should take damage
//This is an unsigned in because a soldier shouldn't ever get "healed" from damage
void Soldier::TakeDamage(unsigned int hit) 
{
    
	this->body -= hit;//Take damage
    
	if(this->body <= -1)
		this->status = SOLDIER_DYING;
	else if(body == 0)
		this->status = SOLDIER_UNCONSCIOUS;
    
}

void Soldier::Wait()  // does nothing
{
	
    
}

int Soldier::getDef()
{
    
	return this->defense;
    
}

SOLIDER_STATUS Soldier::getStatus()
{
    
	return this->status;
    
}

Location Soldier::getPlace()
{
    
	return this->place;
    
}

void Soldier::setPlace(int x, int y)
{
    
	place.x_value = x;
	place.y_value = y;
    
}

void Soldier::setOrders(Soldier* mark, int act)  
// had a problem with declaring the class in the struct before the class def..  worked around it but got frustrated hence "waste _of_my_time"
{
	Soldier waste_of_my_time = *mark;    // i'd love some suggestions on why it works like this but not straight.
	this->current.target = mark;
	this->current.action = act;
	this->current.loc_target = waste_of_my_time.getPlace();
}

int Soldier::getBody()
{
    
	return this->body;
    
}




