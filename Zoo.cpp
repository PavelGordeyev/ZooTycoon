/********************************************************************* 
** Program name: Zoo Class
** Author: Pavel Gordeyev
** Date: 10/27/19
** Description: Zoo.cpp is the Zoo class implementation file.  Zoo 
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
#include "Zoo.hpp"
#include <iostream>
#include <cstdlib>

/********************************************************************* 
** Description: Constructor for the Zoo class.  Initializes the menus
**				to be used in the running of the zoo, as well as the
**				initial size of the zoo array animals to 3, animals
**				per array are 10, bank balance is $100,000 and bonus
**				is set to 0. Initializes all the elements in the 
**				animal arrays to NULL.  It implements a dynamic array 
**				containing the dynamic arrays of each type of animal,
**				and pointers to animal objects.
*********************************************************************/
Zoo::Zoo(Menu *startPromptMenu,Menu *buyAnimalMenu, Menu *buyAnimalTypeMenu,Menu *feedMenu, Menu *endMenu){
	this->startPromptMenu = startPromptMenu;
	this->buyAnimalMenu = buyAnimalMenu;
	this->buyAnimalTypeMenu = buyAnimalTypeMenu;
	this->feedMenu = feedMenu;
	this->endMenu = endMenu;

	initSize = 3;
	animalSize = 10;
	bankBalance = 100000;
	bonus = 0;

	locs = new int[initSize];
	sizes = new int[initSize];

	animals = new Animal**[initSize];
	
	for(int i=0;i<initSize;i++){
		
		// Initialize each animal to a dynamic array
		animals[i] = new Animal*[animalSize];

		// Initialize all the animal slots with NULL
		for(int j = 0;j<animalSize;j++){
			animals[i][j] = NULL;
		}

		// Initialize locs
		locs[i] = 0;

		// Initialize sizes
		sizes[i] = animalSize;
	}
}

/********************************************************************* 
** Description: runZoo function simulates the Zoo Tycoon with user
**				inputs and running through 1 day of simulation at a 
**				time.
*********************************************************************/
void Zoo::runZoo(){

int payOff,
		*startPromptInputs,
		*feedMenuInputs,
		*buyAnimalInputs,
		*buyAnimalTypeInputs,
		*endMenuInputs;

	FeedType feedType = GENERIC;
	OddsType oddsType;

	bool lowBalance = false;

	srand(time(NULL));

	// Ask the user for how many animals they would like to start out with
	// 1 or 2 for each type of animal is required
	startPromptInputs = startPromptMenu->runMenu();

	// Add the initial penguins
	for(int i = 0;i<startPromptInputs[0];i++){
		addAnimal(PENGUIN,-1);
	}

	// Add the initial turtles
	for(int i = 0;i<startPromptInputs[1];i++){
		addAnimal(TURTLE,-1);
	}

	// Add the initial tigers
	for(int i = 0;i<startPromptInputs[2];i++){
		addAnimal(TIGER,-1);
	}

	// Spacing
	std::cout << "_____________________________________" << std::endl;
	std::cout << std::endl;

	//Loop through a day at the zoo
	do{

		// Age the animals by 1 day
		ageAnimals();

		// Ask user to choose a feed type
		std::cout << "What type of feed you like today?" << std::endl;
		feedMenuInputs = feedMenu->runMenu();

		// Reset food cost of the original value
		if(feedType == CHEAP){ // Double the price
			changeFeed(2);
		}else if(feedType == EXPENSIVE){
			changeFeed(0.5);
		}

		switch(feedMenuInputs[0]){
			case CHEAP:
				// Loop through each animal and cut the feed cost in half
				changeFeed(0.5);

				// Set event type to double for sickness
				oddsType = TWICE;

				break;

			case GENERIC:

				// Set event type to even for all events
				oddsType = EVEN;

				break;

			case EXPENSIVE:

				// Loop through each animal and double feed cost 
				changeFeed(2);

				// Set event type to half for sickness
				oddsType = HALF;

				break;

			default:
				break;
		}

		// Pay feeding cost
		updateBalance(DEBIT,feedCalculator());

		// Random event occurs
		executeEvent(randomNumGenerator(oddsType));

		// Calculate profit for the day
		payOff = payOffCalculator();

		// Update the bank balance
		updateBalance(CREDIT,payOff);

		// Spacing
		std::cout << "_____________________________________" << std::endl;
		std::cout << std::endl;

		// Ask user if they would like to buy another animal
		std::cout << "Would you like to buy an adult animal?" << std::endl;
		buyAnimalInputs = buyAnimalMenu->runMenu();

		if(buyAnimalInputs[0] == 1){
			// Spacing
			std::cout << std::endl;
			std::cout << "What type of animal?" << std::endl;
			
			buyAnimalTypeInputs = buyAnimalTypeMenu->runMenu();
			switch(buyAnimalTypeInputs[0]){
				case 1:
					addAnimal(PENGUIN,3);
					break;
				case 2:
					addAnimal(TURTLE,3);
					break;
				case 3:
					addAnimal(TIGER,3);
					break;
				default:
					break;
			}
		}

		// Spacing
		std::cout << "_____________________________________" << std::endl;
		std::cout << std::endl;

		// Ask user if they would like to continuing playing the game
		endMenuInputs = endMenu->runMenu();


		// Check if user has anymore money left
		if(getBankBalance() <= 0){
			std::cout << "It appears you ran out of money! Game Over!" << std::endl;
			std::cout << "Please come play again soon! Good-Bye!" << std::endl;
			lowBalance = true;
		}
	}while(!lowBalance && endMenuInputs[0] == 1);
}

/********************************************************************* 
** Description: executeEvent function that does a different action
**				depending on what random event was chosen.
*********************************************************************/
void Zoo::executeEvent(int event){

	int randInt,
		*randInts,
		low = 250,
		high = 500,
		count = initSize;

	const int ADULT_AGE = 3;

	AnimalType animal;
	bool adult;

	switch(event){
		case NOEVENT:
			// No impact
			break;

		case BOOMATTENDANCE: // Bonus of $250-500 for each tiger owned

			// Reset the bonus
			bonus = 0;

			// Get bonus amount
			randInt = randomNumGenerator(low,high);

			// Add it up for each tiger
			for(int i=0;i<sizes[2];i++){	
				bonus += randInt;
			}

			// Add in the bonus, if there was one, for each tiger
			updateBalance(CREDIT,bonus);

			break;

		case BABY: // Random animal will have a baby

			// Create an array of randInts
			randInts = new int[initSize];
			for(int i=0;i<initSize;i++){
				randInts[i] = i;
			}

			randInt = randomNumGenerator(0,initSize);

			adult = false;

			do{
				// Try animal selected to have a baby
				if(locs[randInt] > 0){ // At least 1 animal exists
					for(int i=0;i<locs[randInt];i++){ // At least 1 adult
						if(animals[randInt][i]->getAge() >= ADULT_AGE){
							adult = true;
						}
					}
				}

				// Remove animal from possible choices
				randInts[randInt] = -1;

				if(!adult){ // Get a different animal to have a baby
					do{
						randInt = randomNumGenerator(0,initSize);
					}while(randInts[randInt]>=0);
				}				
				
				count--;
			}while(!adult && count > 0);

			if(adult){ // Create the number of babies for the respective animal
				
				for(int i=0;i<animals[randInt][0]->getNumBabies();i++){
					addAnimal(randInt,0);
				}

			}

			// Free memory
			delete [] randInts;

			break;

		case SICKNESS: // Random animal dies

			randInt = randomNumGenerator(0,initSize);

			if(randInt == 0){
				animal = PENGUIN;
			}else if(randInt == 1){
				animal = TURTLE;
			}else{
				animal = TIGER;
			}

			removeAnimal(animal);

			break;

		default:
			break;
	}
}

/********************************************************************* 
** Description: randomNumGenerator function outputs a random number
**				between specified low and high integers >= 0.
*********************************************************************/
int Zoo::randomNumGenerator(int low, int high){

	static int randInt;

	if(low < 0 || high < 0){
		randInt = -1;
	}else if(low == 0){
		randInt = rand() % high;
	}else if(low == 1){
		randInt = rand() % high + 1;
	}else{
		randInt = low + rand() % (high-low + 1);
	}

	return randInt;
}

/********************************************************************* 
** Description: randomNumGenerator function outputs a random number
**				based on the odds specified.
*********************************************************************/
int Zoo::randomNumGenerator(OddsType odds){
  
	int randInt;

	switch(odds){
		case EVEN:
			
			// Use modulus of 4 to generate random values from 1-4
			randInt = randomNumGenerator(1,4);
			break;

		case TWICE:

			// Use modulus of 10 to simulate double the odds with
			// allocating 40% of odds for 4 and 20% for each other
			// number. 4 is the sickness.
			randInt = randomNumGenerator(1,10);

			if(randInt <= 2){
				randInt = 1;
			}else if(randInt <= 4){
				randInt = 2;
			}else if(randInt <= 6){
				randInt = 3;
			}else{
				randInt = 4;
			}
			break;

		case HALF:
			// Use modulus of 100 to simulate double the odds with
			// allocating 14.2858% of odds for 4 and 28.5714% for each 
			// other number. 4 is the sickness.
			randInt = randomNumGenerator(1,98);

			if(randInt <= 28){
				randInt = 1;
			}else if(randInt <= 56){
				randInt = 2;
			}else if(randInt <= 84){
				randInt = 3;
			}else{
				randInt = 4;
			}

			break;

		default:
			break;
	}	
  	
	return randInt;
}

/********************************************************************* 
** Description: changeFeed function that changes the feed cost for
**				every existing animal.
*********************************************************************/
void Zoo::changeFeed(double diff){

	// Loop through each animal array
	for(int i=0;i<initSize;i++){
		for(int j=0;j<locs[i];j++){
			animals[i][j]->setFoodCost(diff);
		}
	}

}

/********************************************************************* 
** Description: doubleCapacity function doubles the capacity of 
**				a specific animal.
*********************************************************************/
void Zoo::doubleCapacity(int animalType){

	// Create a new animal array
	Animal **temp;

	temp = new Animal*[locs[animalType]*2];

	// Copy over the animals into the new array & delete the value in
	// the old array
	for(int i = 0;i<sizes[animalType]*2;i++){
		if(i<sizes[animalType]){
			temp[i] = animals[animalType][i];		
		}else{
			temp[i] = NULL;
		}
	}

	delete [] animals[animalType];

	animals[animalType] = temp;

	sizes[animalType] *= 2;

}

/********************************************************************* 
** Description: ageAnimals function that ages the animals by 1 day.
*********************************************************************/
void Zoo::ageAnimals(){

	// Loop through each animal array
	for(int i=0;i<initSize;i++){
		for(int j=0;j<locs[i];j++){
			animals[i][j]->incAge();
		}
	}
}

/********************************************************************* 
** Description: payOffCalculator function that determines the total
**				pay off for the day from all the owned animals.
*********************************************************************/
int Zoo::payOffCalculator(){

	int totalPayOff = 0;

	// Loop through each animal array
	for(int i=0;i<initSize;i++){
		for(int j=0;j<locs[i];j++){
			totalPayOff += animals[i][j]->getPayOff();
		}
	}

	return totalPayOff;
}

/********************************************************************* 
** Description: feedCalculator calculates the cost of the feed for
**				all the owned animals.
*********************************************************************/
int Zoo::feedCalculator(){
	
	int totalFoodCost = 0;

	// Loop through each animal array
	for(int i=0;i<initSize;i++){
		for(int j=0;j<locs[i];j++){
			totalFoodCost += animals[i][j]->getFoodCost();
		}
	}

	return totalFoodCost;
}

/********************************************************************* 
** Description: setBankBalnce sets the bank balance to specified
**				amount.  Used after updateBalance calculates all the
**				necessary credits and debits.
*********************************************************************/
void Zoo::setBankBalance(int newBalance){
	bankBalance = newBalance;
}

/********************************************************************* 
** Description: getBankBalance returns the current bank balance.
*********************************************************************/
int Zoo::getBankBalance(){
	return bankBalance;
}

/********************************************************************* 
** Description: updateBalance calculates the new balance from either
**				a payOff or feed type transaction.
*********************************************************************/
void Zoo::updateBalance(TransType trans, double val){

	// Get the current bank balance
	double bal = getBankBalance();

	// Update the balance depending on debit or credit transaction
	switch(trans){
		case DEBIT:
			bal -= val;
			setBankBalance(bal);
			break;
		case CREDIT:
			bal += val;
			setBankBalance(bal);
			break;
		default:
			break;
	}
}

/********************************************************************* 
** Description: addAnimal adds a specified animal to its respective
**				array and subtracts its cost from the bank balance.
*********************************************************************/
void Zoo::addAnimal(int animalType,int val){

	// Check that the respective animal array isn't full
	// Create an array double of its size otherwise
	if(locs[animalType] == sizes[animalType]){
		doubleCapacity(animalType);
	}

	// Creates a default animal
	if(val == -1){
		switch(animalType){
			case PENGUIN:
				animals[animalType][locs[animalType]] = new Penguin();
				break;
			case TURTLE:
				animals[animalType][locs[animalType]] = new Turtle();
				break;
			case TIGER:
				animals[animalType][locs[animalType]] = new Tiger();
				break;
			default:
				break;
		}
		
	}else{ // Creates an animal with a specific age
		switch(animalType){
			case PENGUIN:
				animals[animalType][locs[animalType]] = new Penguin(val);
				break;
			case TURTLE:
				animals[animalType][locs[animalType]] = new Turtle(val);
				break;
			case TIGER:
				animals[animalType][locs[animalType]] = new Tiger(val);
				break;
			default:
				break;
		}	
	}

	// Update the balance
	updateBalance(DEBIT,animals[animalType][locs[animalType]]->getCost());

	// Update array position for the respective array
	++locs[animalType];
	
}

/********************************************************************* 
** Description: removeAnimal removes a specified animal from its
**				respective array.  Does not go below 0 location in
**				the array.
*********************************************************************/
void Zoo::removeAnimal(int animalType){

	if(locs[animalType]!=0){
		// Delete last animal in the respective array
		delete animals[animalType][locs[animalType]-1];

		// Reset the value at the position to null
		animals[animalType][locs[animalType]-1] = NULL;

		// Update array position
		--locs[animalType];
	}

}

/********************************************************************* 
** Description: Destructor for the Zoo class.
*********************************************************************/
Zoo::~Zoo() {
	
	for(int i=0;i<initSize;i++){
		
		for(int j=0;j<sizes[i];j++){
			delete animals[i][j];
		}
		delete [] animals[i];
	}

	delete [] animals;
	delete [] locs;
	delete [] sizes;
}
