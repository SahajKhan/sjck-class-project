/*************************************************
 Class:			CSCI201-0CC-C1-202030-VI-16R
 Program:		Pokemon The Card Game
 Instructor:	Kristopher Roberts
 *************************************************/
#include <iostream>
#include <string>
#include <vector>
// #include "Card.h"
// #include "DerivedPokemon.h"
// #include "Enumerators.h"

#include "SK_Cards.hpp"
#include "SK_Input.hpp"
#include "SK_Functions.hpp"
#include "SK_Player.hpp"

using namespace std;

void initializeDeck(vector<Pokemon*> pokemonDeck);

int main() {	
	string inputString;
	int inputInt;

	// std::vector<Pokemon*>::iterator it;
	// for(it = pokemonDeck.begin(); it != pokemonDeck.end(); it++){
	// 	std::cout << *it << std::endl;
	// }

    cout << "Welcome to the Pokemon Game!\n";
    cout << "Player 1, please enter your name below\n";
	inputString = input();
	Player Player_1(inputString);


	cout << "Player 2, please enter your name below\n";
	inputString = input();
	Player Player_2(inputString);

	cout << "The coin toss will decide who will be going first\n";
	cout << Player_1.getName()  << " goes first if Heads\n";
	cout << Player_2.getName()  << " goes first if Tails\n";
	if (coinFlip()) {
		//if heads, execute this line of code, otherwise skip it.
	}





	return 0;
}

