// WarGames.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Tells the preproccessor what to include
#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
// Gives me access to the std namespace
using namespace std;


int main()
{
	srand(static_cast<unsigned int>(time(0)));	//Seed the random number generator

	//Declare variables
	int randomNumber;
	int enemyLocation;
	int binaryPrediction;
	int humanPrediction;
	int linearPrediction;
	int randomPrediction;
	int highNumberBinary;
	int lowNumberBinary;
	int highNumberRandom;
	int lowNumberRandom;
	int numberOfSearchesBinary;
	int numberOfSearchesHuman;
	int numberOfSearchesLinear;
	int numberOfSearchesRandom;
	int playAgainMenu;
	bool playAgain;
	bool validOption;

	//Set initial variable values
	binaryPrediction = 0;
	highNumberBinary = 64;
	lowNumberBinary = 1;
	numberOfSearchesBinary = 0;
	humanPrediction = 0;
	numberOfSearchesHuman = 0;
	linearPrediction = 0;
	numberOfSearchesLinear = 0;
	randomPrediction = 0;
	highNumberRandom = 64;
	lowNumberRandom = 1;
	numberOfSearchesRandom = 0;
	playAgainMenu = 0;
	playAgain = false;
	validOption = false;

	cout << "Generating random enemy location" << endl;
	cout << "==========================================================================" << endl;

	do
	{

		//Set random enemy location
		randomNumber = rand();
		enemyLocation = (randomNumber % 64) + 1;

		cout << "Your job operator is to locate the enemy that is hiding in an 8x8 grid" << endl;
		cout << "You will be tested against several top of the line search robots in order to test their search capabilities" << endl;
		cout << "Good luck operator" << endl;
		cout << "==========================================================================" << endl;

		do	//Begin human guessing loop
		{
			numberOfSearchesHuman++;	//Track how many times the human guesses
			cout << "Enter a location to search" << endl;
			cin >> humanPrediction;		//Get human input

			//Check guess against enemy location
			if (humanPrediction > enemyLocation)	//Guess is too high
			{
				cout << "The enemy's position is lower than what you searched" << endl;
				cout << "==========================================================================" << endl;
			}
			else if (humanPrediction < enemyLocation)	//Guess is too low
			{
				cout << "The enemy's position is higher than what you searched" << endl;
				cout << "==========================================================================" << endl;
			}
			else	//Guess is correct
			{
				cout << "Enemy located in sector " << humanPrediction << endl;
				cout << "==========================================================================" << endl;
			}

		} while (humanPrediction != enemyLocation);		//Loop if the guess is wrong

		cout << "\nInitializing binary search drone" << endl;
		cout << "==========================================================================" << endl;

		while (binaryPrediction != enemyLocation)	//Loops while the sky nets prediction does not equal the enemies location
		{
			numberOfSearchesBinary++;		//Track how many predictions are made
			binaryPrediction = ((highNumberBinary - lowNumberBinary) / 2) + lowNumberBinary;	//Binary search algorithm

			//Checks the computers prediction against actual enemy location 
			if (binaryPrediction > enemyLocation)	//Prediction is too high
			{
				highNumberBinary = binaryPrediction - 1;	//Change perameters for next search
				cout << "Prediction of " << binaryPrediction << " higher than enemy location" << endl;
				cout << "Setting new high end search perameters to " << highNumberBinary << endl;
				cout << "==========================================================================" << endl;
			}
			else if (binaryPrediction < enemyLocation)	//Prediction is too low
			{
				lowNumberBinary = binaryPrediction + 1;		//Change perameteers for next search
				cout << "Prediction of " << binaryPrediction << " lower than enemy location" << endl;
				cout << "Setting new low end search perameters to " << lowNumberBinary << endl;
				cout << "==========================================================================" << endl;
			}
			else	//Prediction is correct
			{
				cout << "Enemy located in sector " << binaryPrediction << endl;
				cout << "==========================================================================" << endl;
			}

		}

		cout << "\nInitializing linear search drone" << endl;
		cout << "==========================================================================" << endl;

		//Linear search loop
		//Did not cout this loop because it would flood the console too much 
		for (int i = 1; i < 65; i++)
		{
			numberOfSearchesLinear++;	//Track how many predictions are made
			linearPrediction = i;	//Set the prediction equal to how many times the loop has run
			if (linearPrediction == enemyLocation)	//Checks to see if the prediction is correct
			{
				cout << "Enemy located in sector " << linearPrediction << endl;
				cout << "==========================================================================" << endl;
				break;	//Exit the loop once the enemy is located
			}
		}

		cout << "\nInitializing random search drone" << endl;
		cout << "==========================================================================" << endl;

		while (randomPrediction != enemyLocation)	//Loops while the random guess is not equal to the enemy location
		{
			numberOfSearchesRandom++;	//Track many guesses have been made

			do
			{
				randomPrediction = (rand() % highNumberRandom) + 1;		//Generate random guess
			} while (randomPrediction < lowNumberRandom);	//Ensures that the guess is not lower than what has already been established as too low

			if (randomPrediction > enemyLocation)	//Guess is too high
			{
				highNumberRandom = randomPrediction - 1;	//Change parameters for next guess
				cout << "Prediction of " << randomPrediction << " higher than enemy location" << endl;
				cout << "Setting new high end search perameters to " << highNumberRandom << endl;
				cout << "==========================================================================" << endl;
			}
			else if (randomPrediction < enemyLocation)	//Guess is too low
			{
				lowNumberRandom = randomPrediction + 1;		//Change parameters for next guess
				cout << "Prediction of " << randomPrediction << " lower than enemy location" << endl;
				cout << "Setting new low end search perameters to " << lowNumberRandom << endl;
				cout << "==========================================================================" << endl;
			}
			else	//Guess is correct
			{
				cout << "Enemy located in sector " << randomPrediction << endl;
				cout << "==========================================================================" << endl;
			}
		}

		cout << "\n\nHere are the results" << endl;
		cout << "It took the operator " << numberOfSearchesHuman << " tries to locate the enemy" << endl;
		cout << "It took the binary search drone " << numberOfSearchesBinary << " tries to locate the enemy" << endl;
		cout << "It took the linear search drone " << numberOfSearchesLinear << " tries to locate the enemy" << endl;
		cout << "It took the random search drone " << numberOfSearchesRandom << " tries to locate the enemey" << endl;

		//Play again loop, runs until a valid option is chosen
		do
		{
			cout << "Would you like to play again?" << endl;
			cout << "1. Yes" << endl;
			cout << "2. No" << endl;
			cin >> playAgainMenu;

			if (playAgainMenu == 1)
			{
				playAgain = true;
				validOption = true;
			}
			else if (playAgainMenu == 2)
			{
				playAgain = false;
				validOption = true;
			}
			else
			{
				cout << "Please enter a valid option" << endl;
				validOption = false;
			}
		} while (!validOption);


	} while (playAgain);	//Loops program if the player has chosen to play again

	 

	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
