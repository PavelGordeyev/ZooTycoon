/********************************************************************* 
** Program name: Zoo Class
** Author: Pavel Gordeyev
** Date: 10/27/19
** Description: Zoo.cpp is the Zoo class specifcation file.  Zoo 
**				tycoon is a game that allows players to run a zoo 
**				business. Different types of animals cost different 
**				prices, have different maintenance costs, and of 
**				course, return a different profit at the end of each 
**				day. For this game, the player will be the proud owner 
**				of a virtual zoo that has spaces to house tigers, 
**				penguins and turtles. It implements a dynamic array 
**				containing the dynamic arrays of each type of animal,
**				and pointers to animal objects.
*********************************************************************/
#ifndef ZOO_HPP
#define ZOO_HPP

#include "Animal.hpp"
#include "Penguin.hpp"
#include "Tiger.hpp"
#include "Turtle.hpp"
#include "Menu.hpp"

enum FeedType {CHEAP = 1,GENERIC,EXPENSIVE};
enum TransType {DEBIT,CREDIT};
enum AnimalType {PENGUIN,TURTLE,TIGER};
enum EventType {NOEVENT = 1,BOOMATTENDANCE,BABY,SICKNESS};
enum OddsType {EVEN,TWICE,HALF};

class Zoo{

public:
	Zoo(Menu*,Menu*,Menu*,Menu*,Menu*);
	~Zoo();
	void runZoo();	

private:
	int *locs,
		*sizes,
		bonus,
		bankBalance,
	    initSize,
	    animalSize;
	
	Animal ***animals;

	Menu *startPromptMenu,
		 *buyAnimalMenu,
		 *buyAnimalTypeMenu,
		 *feedMenu,
		 *endMenu;

	int randomNumGenerator(OddsType);
	int randomNumGenerator(int,int);
	void executeEvent(int);
	void doubleCapacity(int);
	int payOffCalculator();
	int feedCalculator();
	void changeFeed(double);
	void setBankBalance(int);
	int getBankBalance();
	void ageAnimals();
	void addAnimal(int,int);
	void removeAnimal(int);
	void updateBalance(TransType,double);

};

#endif
