/********************************************************************* 
** Program name: Tiger Class
** Author: Pavel Gordeyev
** Date: 10/20/19
** Description: Tiger.hpp is the Tiger class specification file. 
**				The class inherits from the Animal class.  It sets 
**				the cost, payoff, number of babies and food	cost 
**				specific for a tiger.
*********************************************************************/
#ifndef TIGER_HPP
#define TIGER_HPP

#include "Animal.hpp"

class Tiger : public Animal{

private:
	double foodCost;

public:
	Tiger();
	Tiger(int);
	double getFoodCost();
	void setFoodCost(double);
};

#endif