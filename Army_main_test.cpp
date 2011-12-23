/*

	Programmer: Chad Schaffer
	Date: 12/23/2011

	A test harness for movement and attack features of the Soldier Class

*/

//#include<iostream>
#include "army_classes.h"

using namespace std;



int main()
{
	Soldier red;
	Soldier dummy;

	Location report;

	red.setPlace(5, 0);
	dummy.setPlace(8, 10);

	red.setOrders(&dummy, 1);

	int done_Flag = dummy.getStatus();
	bool dest_Flag = 0;
	int wounds;
	Location dummy_loc = dummy.getPlace();



	while(done_Flag == 1)
	{

		if(dest_Flag == 0)
		{
			dest_Flag = red.Move();
			report = red.getPlace();
			cout<< "red moves to ("<< report.x_value<< "," << report.y_value<< ")"<< endl;
		}

		if(dest_Flag == 1)
		{
			red.Act();
			cout<< "red attacks dummy"<< endl;
		}


		wounds = dummy.getBody();
		done_Flag = dummy.getStatus();
		cout<< "dummy Location: ("<< dummy_loc.x_value << "," << dummy_loc.y_value << ")  " << "dummy body: "<< wounds << "  dummy status: "<< done_Flag<< endl << endl;
		system("pause");
	}



	system("pause");
	return 0;

}