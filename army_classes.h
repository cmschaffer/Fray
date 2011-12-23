/*

	Programer: Chad Schaffer
	Date: 12/18/2011

	the soldier class, supporting structs.

*/

#include<iostream>
#include<vector>

using namespace std;


// an easy way to group x and y values for a 2d grid
struct Location
{
	int x_value;
	int y_value;
	int xMax;
	int yMax;

};

// an easy way to group a set of orders


class Soldier;  // declaration for use in Orders
struct Orders
{
	Location loc_target;
	Soldier * target;  // this caused an issue..  i worked around it but check Soldier::setOrders() for more info
	int action;

};

//both structs will become classes, just wanted to focus on soldier first.


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
	int status;

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
	int getStatus();
	void Wait();   //a soldier action that does nothing
	void TakeDamage(int); // changes soldier body down based on input int...  broken (scope problem, damage won't stick) (help)
	int AdjustMorale(); // useless for now
	Location getPlace(); 
	void setPlace(int, int); 
	void setOrders(Soldier*, int);
	int getBody();
};



//base construtor for Soldier
Soldier::Soldier()
{
	level = 1;
	body = 8;
	armor = 20;
	defense = 7;
	offense = 3;
	atckSpeed = 1;
	damage = 2;
	morale = 3;
	status = 1;

	at_Loc_Flag = 0;
	atckd_Flag = 0;
}

Soldier::Soldier(int nLevel, int nBody, int nArmor, int nDefense, int nOffense, int nAtckSpeed, int nDamage,
											int nMorale,int nTeam, Orders nCurrent, Location nPlace)
{
		level = nLevel;
		body = nBody;
		armor = nArmor;
		defense = nDefense;
		offense = nOffense;
		atckSpeed = nAtckSpeed;
		damage = nDamage;
		morale = nMorale;
		team = nTeam;
		current = nCurrent;
		place = nPlace;

		at_Loc_Flag = 0;
		atckd_Flag = 0;

}


int Soldier::Dice(int type)
{

	int value = rand() % type + 1;

	return value;

}

bool Soldier::Move()
{
	if(place.x_value == current.loc_target.x_value && place.y_value == current.loc_target.y_value) // checks if current place matches destination
		at_Loc_Flag = 1;
	else
	{
		if(place.x_value < current.loc_target.x_value)       // this block moves the soldier
			place.x_value++;
		else if(place.x_value > current.loc_target.x_value)
			place.x_value--;

		if(place.y_value < current.loc_target.y_value)
			place.y_value++;
		else if(place.y_value > current.loc_target.y_value)
			place.y_value--;
	}

	if(place.x_value == current.loc_target.x_value && place.y_value == current.loc_target.y_value) // checks again because action can take place on same round after move
		at_Loc_Flag = 1;



	return at_Loc_Flag;
	
}


void Soldier::Act()
{
	switch(current.action)   // this swtich contains all possible actions
	{
		case 1: Attack(current.target);
				break;
		case 2: Wait();
				break;
		default: cerr<< "error in Soldier::Act() : current.action int not recognized";
	}

}


void Soldier::Attack(Soldier* target)
{

	{
		for(int j = 0; j < atckSpeed; j++)   
		{
			Swing(target);
			cout<< "swing"<< endl;
		}
	}

}

void Soldier::Swing(Soldier* target)
{
	Soldier defender = *target; 
	int atckRoll = offense + Dice(20);
	int defRoll = defender.getDef();

	defender.atckd_Flag = 1;

	if(atckRoll > defRoll)
	{
		cout<< "hit!" << endl;
		defender.TakeDamage(damage);
	}

}

void Soldier::TakeDamage(int hit)   //  broken (think it's a scope issue.  soldier takes damage but it doesn't stick)
{

	body = body - hit;

	if(body >= -1)
		status = 3;
	else if(body == 0)
		status = 2;

}

void Soldier::Wait()  // does nothing
{
	

}

int Soldier::getDef()
{

	return defense;

}

int Soldier::getStatus()
{

	return status;

}

Location Soldier::getPlace()
{

	return place;

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
	current.target = mark;
	current.action = act;
	current.loc_target = waste_of_my_time.getPlace();
}

int Soldier::getBody()
{

	return body;

}




