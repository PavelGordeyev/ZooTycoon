/********************************************************************* 
** Program name: Project 2 - Zoo Tycoon
** Author: Pavel Gordeyev
** Date: 10/20/19
** Description: main.cpp is the main function implementation file for
**              Project 2 - Zoo Tycoon. Zoo tycoon is a game that 
**				allows players to run a zoo business. Different types
**				of animals cost different prices, have different 
**				maintenance costs, and of course, return a different 
**				profit at the end of each day. For this game, the 
**				player will be the proud owner of a virtual zoo that 
**				has spaces to house tigers, penguins and turtles.
*********************************************************************/
#include "Menu.hpp"
#include "Zoo.hpp"
#include <string>
#include <iostream>

using std::string;

int main(){

	int startMenuSize = 3,
	buyAnimalMenuSize = 2,
	buyAnimalTypeSize = 3,
	feedMenuSize = 3,
	endMenuSize = 2,
	validOption1 = 1,
	validOption2 = 2,
	validOption3 = 3;

	//**********************//
	//  START PROMPT MENU   //
	//**********************//

	// Start prompt menu items
	string *startPromptMenuItems = new string[startMenuSize];
	startPromptMenuItems[0] = "How many penguins would you like to buy? (1 or 2): ";
	startPromptMenuItems[1] = "How many turtles would you like to buy? (1 or 2): ";
	startPromptMenuItems[2] = "How many tigers would you like to buy? (1 or 2): ";

	// Prompt menu valid user option selections
	int *vInputsPrompts = new int[startMenuSize];
	vInputsPrompts[0] = validOption2;
	vInputsPrompts[1] = validOption2;
	vInputsPrompts[2] = validOption2;

	// Start prompt menu error messages
	string *startPromptMenuErrorItems = new string[startMenuSize];
	startPromptMenuErrorItems[0] = "Can only be 1 or 2 penguins!";
	startPromptMenuErrorItems[1] = "Can only be 1 or 2 turtles!";
	startPromptMenuErrorItems[2] = "Can only be 1 or 2 tigers!";

	//**********************//
	//  BUY ANIMALS MENU    //
	//**********************//

	// Buy adult animal options menu
	string *buyAnimalMenuItems = new string[buyAnimalMenuSize];
	buyAnimalMenuItems[0] = "1 - Buy an adult animal";
	buyAnimalMenuItems[1] = "2 - No, don't buy an adult animal";

	// Buy adult animal options menu valid user selections
	int *vInputsBuy = new int[buyAnimalMenuSize];
	vInputsBuy[0] = validOption1;
	vInputsBuy[1] = validOption2;

	//**********************//
	// BUY ANIMALS TYPE MENU//
	//**********************//

	// Buy adult animal options menu
	string *buyAnimalTypeItems = new string[buyAnimalTypeSize];
	buyAnimalTypeItems[0] = "1 - PENGUIN";
	buyAnimalTypeItems[1] = "2 - TURTLE";
	buyAnimalTypeItems[2] = "3 - TIGER";

	// Buy adult animal options menu valid user selections
	int *vInputsBuyType = new int[buyAnimalTypeSize];
	vInputsBuyType[0] = validOption1;
	vInputsBuyType[1] = validOption2;
	vInputsBuyType[2] = validOption3;

	//**********************//
	//  FEED TYPES MENU     //
	//**********************//

	// Type of feed options menu
	string *feedMenuItems = new string[feedMenuSize];
	feedMenuItems[0] = "1 - CHEAP";
	feedMenuItems[1] = "2 - GENERIC";
	feedMenuItems[2] = "3 - EXPENSIVE";

	// Buy adult animal options menu valid user selections
	int *vInputsFeed = new int[feedMenuSize];
	vInputsFeed[0] = validOption1;
	vInputsFeed[1] = validOption2;
	vInputsFeed[2] = validOption3;

	//**********************//
	//      END MENU        //
	//**********************//

	// End of day options menu
	string *endMenuItems = new string[endMenuSize];
	endMenuItems[0] = "1 - Keep playing?";
	endMenuItems[1] = "2 - Exit Zoo Tycoon";

	// End of day options menu valid user selections
	int *vInputsEnd = new int[endMenuSize];
	vInputsEnd[0] = validOption1;
	vInputsEnd[1] = validOption2;

	// Create the menus
	Menu *startPromptMenu = new Menu(startPromptMenuItems,startPromptMenuErrorItems,vInputsPrompts,startMenuSize,PROMPTS);
	Menu *buyAnimalMenu = new Menu(buyAnimalMenuItems,nullptr,vInputsBuy,buyAnimalMenuSize,OPTIONS);
	Menu *buyAnimalTypeMenu = new Menu(buyAnimalTypeItems,nullptr,vInputsBuyType,buyAnimalTypeSize,OPTIONS);
	Menu *feedMenu = new Menu(feedMenuItems,nullptr,vInputsFeed,feedMenuSize,OPTIONS);
	Menu *endMenu = new Menu(endMenuItems,nullptr,vInputsEnd,endMenuSize,OPTIONS);

	// Welcome message
	string welcomeMessage = "Welcome to Zoo Tycoon! We hope you enjoy the zoo experience!\n";


	Zoo *myZoo = new Zoo(startPromptMenu,buyAnimalMenu,buyAnimalTypeMenu,feedMenu,endMenu);

	myZoo->runZoo();

	// Free memory
	delete myZoo;
	delete startPromptMenu;
	delete buyAnimalMenu;
	delete buyAnimalTypeMenu;
	delete feedMenu;
	delete endMenu;
	delete [] vInputsPrompts;
	delete [] startPromptMenuItems;
	delete [] startPromptMenuErrorItems;
	delete [] buyAnimalMenuItems;
	delete [] buyAnimalTypeItems;
	delete [] vInputsBuy;
	delete [] vInputsBuyType;
	delete [] feedMenuItems;
	delete [] vInputsFeed;
	delete [] endMenuItems;
	delete [] vInputsEnd;

	return 0;
}