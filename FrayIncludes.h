//
//  FrayIncludes.h
//  ArmySystem
//
//  Created by Christopher Ingebrigtsen on 12/27/11.
//  Copyright (c) 2011 Bellyflop. All rights reserved.
//

#ifndef FRAY_INCLUDES_H
#define FRAY_INCLUDES_H

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


#endif
