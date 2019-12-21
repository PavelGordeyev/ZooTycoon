/********************************************************************* 
** Program name: Turtle Class
** Author: Pavel Gordeyev
** Date: 10/20/19
** Description: Turtle.cpp is the Turtle class implementation file. 
**				The class inherits from the Animal class.  It sets 
**				the cost, payoff, number of babies and food	cost 
**				specific for a turtle.
*********************************************************************/
#include "Turtle.hpp"

/********************************************************************* 
** Description: Default constructor for the Turtle class. Initializes
**				all member variables to the specifics of a turtle.
**				Default age is set to 1.
*********************************************************************/
Turtle::Turtle() : Animal(){
	
	this->age = 1;
	this->cost = 100;
	this->numberOfBabies = 10;
	this->payOff = this->cost * 0.05;
	this->foodCost = baseFoodCost * 0.5;
}

/********************************************************************* 
** Description: Constructor for the Turtle class. Initializes
**				all member variables to the specifics of a turtle.
**				Accepts an age to set the penguin to.
*********************************************************************/
Turtle::Turtle(int age) : Animal(){

	this->age = age;
	this->cost = 100;
	this->numberOfBabies = 10;
	this->payOff = this->cost * 0.05;
	this->foodCost = baseFoodCost * 0.5;
}


/********************************************************************* 
** Description: getFoodCost function that returns the food cost
**				of feeding the animal, in dollars.
*********************************************************************/
double Turtle::getFoodCost(){

	return this->foodCost;

}

/********************************************************************* 
** Description: setFoodCost function that sets the food cost for when
**				the feed is of a different type.
*********************************************************************/
void Turtle::setFoodCost(double diff){

	this->foodCost *= diff;

}