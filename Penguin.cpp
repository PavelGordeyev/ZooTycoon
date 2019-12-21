/********************************************************************* 
** Program name: Penguin Class
** Author: Pavel Gordeyev
** Date: 10/20/19
** Description: Penguin.cpp is the Penguin class implementation file.
**				The class inherits from the Animal class.  It sets 
**				the cost, payoff, number of babies and food	cost 
**				specific for a penguin. 
*********************************************************************/
#include "Penguin.hpp"

/********************************************************************* 
** Description: Default constructor for the Penguin class. Initializes
**				all member variables to the specifics of a penguin.
**				Default age is set to 1.
*********************************************************************/
Penguin::Penguin() : Animal(){
	
	this->age = 1;
	this->cost = 1000;
	this->numberOfBabies = 5;
	this->payOff = this->cost * 0.1;
	this->foodCost = baseFoodCost;
}

/********************************************************************* 
** Description: Constructor for the Penguin class. Initializes
**				all member variables to the specifics of a penguin.
**				Accepts an age to set the penguin to.
*********************************************************************/
Penguin::Penguin(int age) : Animal(){

	this->age = age;
	this->cost = 1000;
	this->numberOfBabies = 5;
	this->payOff = this->cost * 0.1;
	this->foodCost = baseFoodCost;
}


/********************************************************************* 
** Description: getFoodCost function that returns the food cost
**				of feeding the animal, in dollars.
*********************************************************************/
double Penguin::getFoodCost(){

	return this->foodCost;

}

/********************************************************************* 
** Description: setFoodCost function that sets the food cost for when
**				the feed is of a different type.
*********************************************************************/
void Penguin::setFoodCost(double diff){

	this->foodCost *= diff;

}