/********************************************************************* 
** Program name: Tiger Class
** Author: Pavel Gordeyev
** Date: 10/20/19
** Description: Tiger.cpp is the Tiger class implementation file. 
**				The class inherits from the Animal class.  It sets 
**				the cost, payoff, number of babies and food	cost 
**				specific for a tiger.
*********************************************************************/
#include "Tiger.hpp"

/********************************************************************* 
** Description: Default constructor for the Tiger class. Initializes
**				all member variables to the specifics of a tiger.
**				Default age is set to 1.
*********************************************************************/
Tiger::Tiger() : Animal(){
	
	this->age = 1;
	this->cost = 10000;
	this->numberOfBabies = 1;
	this->payOff = this->cost * 0.2;
	this->foodCost = baseFoodCost * 5;
}

/********************************************************************* 
** Description: Constructor for the Tiger class. Initializes
**				all member variables to the specifics of a tiger.
**				Accepts an age to set the penguin to.
*********************************************************************/
Tiger::Tiger(int age) : Animal(){

	this->age = age;
	this->cost = 10000;
	this->numberOfBabies = 1;
	this->payOff = this->cost * 0.2;
	this->foodCost = baseFoodCost * 5;
}


/********************************************************************* 
** Description: getFoodCost function that returns the food cost
**				of feeding the animal, in dollars.
*********************************************************************/
double Tiger::getFoodCost(){

	return this->foodCost;

}

/********************************************************************* 
** Description: setFoodCost function that sets the food cost for when
**				the feed is of a different type.
*********************************************************************/
void Tiger::setFoodCost(double diff){

	this->foodCost *= diff;

}