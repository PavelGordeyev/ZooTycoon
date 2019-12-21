/********************************************************************* 
** Program name: Animal Class
** Author: Pavel Gordeyev
** Date: 10/20/19
** Description: Animal.hpp is the Animal class specification file. 
**				The class creates animals with an age, cost, payoff,
**				number of babies and base food cost.  The base food
**				cost is used to in the children classes to adjust
**				each specific animals food cost based on a factor.
**				Destructor and get/set food cost are the only 
**				virtual functions.  
*********************************************************************/
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal{

protected:
	int age,
		cost,
		numberOfBabies,
		payOff;

	double baseFoodCost;

public:
	Animal();
	virtual ~Animal();
	int getAge();
	void incAge();
	int getCost();
	int getNumBabies();
	virtual double getFoodCost();
	virtual void setFoodCost(double);
	int getPayOff();
	
};

#endif