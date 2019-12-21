/********************************************************************* 
** Program name: Penguin Class
** Author: Pavel Gordeyev
** Date: 10/20/19
** Description: Penguin.hpp is the Penguin class specification file. 
**				The class inherits from the Animal class.  It sets 
**				the cost, payoff, number of babies and food	cost 
**				specific for a penguin. 
*********************************************************************/
#ifndef PENGUIN_HPP
#define PENGUIN_HPP

#include "Animal.hpp"

class Penguin : public Animal{

private:
	double foodCost;

public:
	Penguin();
	Penguin(int);
	double getFoodCost();
	void setFoodCost(double);
};

#endif