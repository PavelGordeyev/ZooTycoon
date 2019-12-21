/********************************************************************* 
** Program name: Animal Class
** Author: Pavel Gordeyev
** Date: 10/20/19
** Description: Animal.cpp is the Animal class implementation file. 
**				The class creates animals with an age, cost, payoff,
**				number of babies and base food cost.  The base food
**				cost is used to in the children classes to adjust
**				each specific animals food cost based on a factor.
**				Get/set food cost are the only virtual functions.
*********************************************************************/
#include "Animal.hpp"

/********************************************************************* 
** Description: Default constructor for the Animal class. Initializes
**				all member variables to -1 except for the base food
**				cost, which is set to $10.
*********************************************************************/
Animal::Animal(){
	age = -1;
	cost = -1;
	numberOfBabies = -1;
	payOff = -1;
	baseFoodCost = 10;
}

/********************************************************************* 
** Description: getAge function that returns the age of the animal,
**				in days.
*********************************************************************/
int Animal::getAge(){
	return this->age;
}

/********************************************************************* 
** Description: incAge function that increments the age of the animal,
**				by 1 day.
*********************************************************************/
void Animal::incAge(){
	this->age++;
}

/********************************************************************* 
** Description: getCost function that returns the purchase cost of the 
**				animal, in dollars.
*********************************************************************/
int Animal::getCost(){
	return this->cost;
}

/********************************************************************* 
** Description: getNumBabies function that returns the number of 
**				babies that the animal can have at one time.
*********************************************************************/
int Animal::getNumBabies(){
	return this->numberOfBabies;
}

/********************************************************************* 
** Description: getFoodCost function that returns the food cost
**				of feeding the animal, in dollars.
*********************************************************************/
double Animal::getFoodCost(){
	return this->baseFoodCost;
}

/********************************************************************* 
** Description: setFoodCost function that sets the food cost for when
**				the feed is of a different type.
*********************************************************************/
void Animal::setFoodCost(double diff){
	baseFoodCost *= diff;
}

/********************************************************************* 
** Description: getPayoff function that returns the payoff for the 
**				animal at the end of the zoo day, in dollars.
*********************************************************************/
int Animal::getPayOff(){
	return this->payOff;
}

/********************************************************************* 
** Description: Virtual destructor for the Animal class.
*********************************************************************/
Animal::~Animal() {}
