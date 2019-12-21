/********************************************************************* 
** Program name: Turtle Class
** Author: Pavel Gordeyev
** Date: 10/20/19
** Description: Turtle.hpp is the Turtle class specification file. 
**				The class inherits from the Animal class.  It sets 
**				the cost, payoff, number of babies and food	cost 
**				specific for a turtle.
*********************************************************************/
#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "Animal.hpp"

class Turtle : public Animal{

private:
	double foodCost;

public:
	Turtle();
	Turtle(int);
	double getFoodCost();
	void setFoodCost(double);
};

#endif