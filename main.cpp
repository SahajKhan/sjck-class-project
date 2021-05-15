/*************************************************
 Class:			CSCI201-0CC-C1-202030-VI-16R
 Program:		Pokemon The Card Game
 Instructor:	Kristopher Roberts
 *************************************************/
#include <iostream>
#include <string>
#include <vector>
// #include "Enumerators.h"
#include "Cards.hpp"
#include "Input.hpp"
#include "Functions.hpp"
#include "Player.hpp"

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

	/*Decide the first player and check for mulligan*/
	cout << "The coin toss will decide who will be going first\n";
	cout << Player_1.getName()  << " goes first if Heads\n";
	cout << Player_2.getName()  << " goes first if Tails\n";
	if (coinFlip()) { //if heads
		cout << Player_1.getName() << " gets to go first.\n";
		Player_1.handCards_toString();
		if (Player_1.mulligan()) {
			cout << "You do not have a Pokemon to choose from.\n";
			cout << "You lose your turn, your deck will be shuffled. Try again after " << Player_2.getName() << endl;
		} else {
			chooseActivePokemon(Player_1);
		}
	}
	else { //if tails
		cout << Player_2.getName() << " gets to go first.\n";
		Player_2.handCards_toString();
		if (Player_2.mulligan()) {
			cout << "You do not have a Pokemon to choose from.\n";
			cout << "You lose your turn, your deck will be shuffled. Try again after " << Player_1.getName() << endl;
		} else {
			chooseActivePokemon(Player_2);
		}
	}

	//check if hand deck has energy
	//if hand deck has energy, give player the option to use it on bench cards or active pokemon, give player chance to not use energy
	
	//now allow player to use one trainer card if it applies, give player option to skip

	//now allow players active pokemon to attack opponents pokemom(only if pokemon has enough energy, and only if the opponent has an active pokemon), allow player to skip
		//if attack is chosen, check the opponents card to see if dead
			//if dead allow player to pick prize card and move into hand
				//check to see if all 6 prize cards are in hand, if so, player has won the game
				//if player has not won the game move opponents active pokemon to the discard pile and add energy to discard pile, allow opponent to select pokemon from bench or hand
			


	return 0;
}

void chooseActivePokemon(Player &player) {
	int inputInt;
	player.handCards_toString();
	/*Loop until a pokemon card is chosen from the handCards*/
			while (true) {
				cout << "Choose your active Pokemon,\n";
				inputInt = input(1,7);
				if (!player.setActivePokemon(inputInt - 1)) {
					cout << "You did not choose a Pokemon\n Try again.";
				} else 
					break;
			}
}



