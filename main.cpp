/*************************************************
 Class:			CSCI201-0CC-C1-202030-VI-16R
 Program:		Pokemon The Card Game
 Instructor:	Kristopher Roberts
 *************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "Pokemon_list.hpp"
#include "Cards.hpp"
#include "Functions.hpp"
#include "Player.hpp"

using namespace std;

void initializeDeck(vector<Pokemon*> pokemonDeck);
void chooseActivePokemon(Player &player);

/*Checks to see if player has energy on hand, if so give player the option to use it*/
void checkAndUseEnergy(Player& player);

int main() {
	creatingPokemon cp;
	cp.createPokemonList();


	
	string inputString;
	int inputInt;

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

	/*This is the first move, decided by the coin toss*/
	if (coinFlip()) { //if heads
		cout << Player_1.getName() << " gets to go.\n";
		if (Player_1.mulligan()) {
			cout << "You do not have a Pokemon to choose from.\n";
			cout << "You lose your turn, your deck will be shuffled. Try again after " << Player_2.getName() << endl;
			Player_1.shuffleDeck();
		} else {
			chooseActivePokemon(Player_1);
			checkAndUseEnergy(Player_1);
		}
	}
	
	cout << Player_2.getName() << " gets to go.\n";
	if (Player_2.mulligan()) {
		cout << "You do not have a Pokemon to choose from.\n";
		cout << "You lose your turn, your deck will be shuffled. Try again after " << Player_1.getName() << endl;
		Player_2.shuffleDeck();
	} else {
		chooseActivePokemon(Player_2);
		checkAndUseEnergy(Player_2);
	}


	/*Now the game starts*/
	while (true) {
		cout << Player_1.getName() << "'s turn\n";
		checkAndUseEnergy(Player_1);

	}


	//if hand deck has energy, give player the option to use it on bench cards or active pokemon, give player chance to not use energy
	
	//now allow player to use one trainer card if it applies, give player option to skip

	//now allow players active pokemon to attack opponents pokemom(only if pokemon has enough energy, and only if the opponent has an active pokemon), allow player to skip
		//if attack is chosen, check the opponents card to see if dead
			//if dead allow player to pick prize card and move into hand
				//check to see if all 6 prize cards are in hand, if so, player has won the game
				//if player has not won the game move opponents active pokemon to the discard pile and add energy to discard pile, allow opponent to select pokemon from bench or hand
			


	return 0;
}

void chooseActivePokemon(Player& player) {
	int inputInt;
	player.print_HandCards();
	/*Loop until a pokemon card is chosen from the handCards*/
			while (true) {
				cout << "Choose your active Pokemon,\n";
				inputInt = input(1,7);
				if (!player.setActivePokemon(inputInt - 1)) {
					cout << "You did not choose a Pokemon\n Try again.";
				} else 
					break;
			}
	cout << "Your active Pokemon is: " << player.getActivePokemonName() << endl;
}

/*Checks to see if player has energy on hand, if so give player the option to use it*/
void checkAndUseEnergy(Player& player) {
	if (!player.hasEnergyCardInHand())
		return;

	unsigned int inputInt;

	cout << "You may pick an energy card to use for an active or benched Pokemon.\n";
	cout << "1: Use Energy Card\n";
	cout << "2: Don't use Energy Card\n";
	inputInt = input(1,2);

	if (inputInt == 2)
		return;

	cout << "Select a card\n";
	player.print_BenchCards();
	cout << "Active Pokemon: " << player.getActivePokemonName() << endl;
	inputInt = input(1, player.getBenchCardsSize()+1);

	if (inputInt == player.getBenchCardsSize()+1)
		player.addEnergy();	//add energy to active pokemon
	else 
		player.addEnergy(inputInt-1); //add energy to benchCard pokemon // not sure if inputInt will match correctly
}

/*Checks to see if player has a trainer card on hand, and gives the option to use it*/
void userTrainerCard(Player& currentTurnPlayer, Player& nextTurnPlayer) {
	int inputInt;

	if (!currentTurnPlayer.hasTrainerCardInHand())
		return;
	
	cout << "Would you like tochoose a trainer card to use?\n";
	currentTurnPlayer.print_HandCards();
	cout << "1: Yes\n2: No\n";
	inputInt = input(1,2);
	
	if(inputInt == 2)
		return;

	while (true) {
		cout << "Choose your trainer card\n";
		inputInt = input(1, currentTurnPlayer.getHandCardsSize());

		if (!currentTurnPlayer.isTrainerCard(inputInt-1))
			cout << "That isn't a trainer card.\n";
		else
			break;
	}

	switch (currentTurnPlayer.whichTrainerType(inputInt))
	{
	case TrainerType::POKEMON_CATCHER :
		//current location in programming
		break;
	
	default:
		break;
	}

}