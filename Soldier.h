/*

	Programer: Chad Schaffer
	Date: 12/18/2011

	the soldier class, supporting structs.

*/

#include<iostream>
#include<vector>
#include "FrayIncludes.h"

#ifndef SOLDIER_H
#define SOLIDER_H

enum SOLIDER_STATUS {
    SOLDIER_OK,//enums defualt to 0. So SOLDIER_OK == 0
    SOLDIER_UNCONSCIOUS,//The next one is 1. So SOLDIER_UNCONSCIOUS == 1
    SOLDIER_DYING //You guessed, it this is 2
    /*,SOLIDER_PERMANENTLY_DEAD = 1000 */ // This is valid too. You can set an enum to a specific number. The next enum will be 1001
    };
// primary Soldier class
class Soldier
{
	
	int level;
	int body;
	int armor;
	int defense;
	int offense;
	int atckSpeed;
	int damage;
	int morale;
	int team;
	Orders current;
	Location place;
	bool at_Loc_Flag;
	SOLIDER_STATUS status;

public:

	Soldier();    // base constructor, makes a first level guy
	Soldier(int, int, int, int, int, int, int, int, int, Orders, Location); // custom constructor
	
	bool atckd_Flag; // trips if soldier is attacked

	int Dice(int);  // basic dice simulation
	bool Move();  //changes coordinate location on x,y grid
	void Act(); // determines action for soldier
	void Attack(Soldier*); //one soldier action
	void Swing(Soldier*); //a sub action within Attack()
	int getAtckSpeed(); 
	int getDef();
	SOLIDER_STATUS getStatus();
	void Wait();   //a soldier action that does nothing
	void TakeDamage(unsigned int); // changes soldier body down based on input int...  broken (scope problem, damage won't stick) (help)
	int AdjustMorale(); // useless for now
	Location getPlace(); 
	void setPlace(int, int); 
	void setOrders(Soldier*, int);
	int getBody();
};

#endif


