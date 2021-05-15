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

/*Checks to see if player has a trainer card on hand, and gives the option to use it, return true if card was used*/
bool useTrainerCard(Player& currentTurnPlayer, Player& nextTurnPlayer);

/*Player's pokemon attack*/
void attack(Player& attackingPlayer, Player& defendingPlayer);

/*Check if active Pokemon is dead*/
bool checkPokemonIsDead(Player& player);

/*Chose new pokemon*/
bool chooseNewPokemon(Player& player);

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

		//if hand deck has energy, give player the option to use it on bench cards or active pokemon, give player chance to not use energy
		checkAndUseEnergy(Player_1);

		//now allow player to use one trainer card if it applies, give player option to skip
		if (!useTrainerCard(Player_1, Player_2))
			cout << "Trainer Card could not be used\n";
		
		attack(Player_1, Player_2);
		if (checkPokemonIsDead(Player_2)) {
			cout << Player_1.getName() << "'s active pokemon won the battle.\n";
			cout << Player_1.getName() << " wins a prize card.\n";
			Player_1.winPrizeCard();
			if (Player_1.getNumofPrizeCards() < 1) {
				cout << Player_1.getName() << " has won the game!\n";
				return 0;
			}

			cout << Player_2.getName() << "'s active pokemon lost the battle.\nChoose a new pokemon\n";
			chooseNewPokemon(Player_2);
		}




		cout << Player_2.getName() << "'s turn\n";

		//if hand deck has energy, give player the option to use it on bench cards or active pokemon, give player chance to not use energy
		checkAndUseEnergy(Player_2);

		//now allow player to use one trainer card if it applies, give player option to skip
		if (!useTrainerCard(Player_2, Player_1))
			cout << "Trainer Card could not be used\n";
		
		attack(Player_2, Player_1);
		if (checkPokemonIsDead(Player_2)) {
			cout << Player_2.getName() << "'s active pokemon won the battle.\n";
			cout << Player_2.getName() << " wins a prize card.\n";
			Player_2.winPrizeCard();
			if (Player_2.getNumofPrizeCards() < 1) {
				cout << Player_2.getName() << " has won the game!\n";
				return 0;
			}

			cout << Player_1.getName() << "'s active pokemon lost the battle.\nChoose a new pokemon\n";
			chooseNewPokemon(Player_1);
		}

	}


	
	
	

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

/*Checks to see if player has a trainer card on hand, and gives the option to use it, return true if card was used*/
bool useTrainerCard(Player& currentTurnPlayer, Player& nextTurnPlayer) {
	if (!currentTurnPlayer.hasTrainerCardInHand())
		return false;

	int inputInt;
	int trainerCardLocation;
	
	cout << "Would you like tochoose a trainer card to use?\n";
	currentTurnPlayer.print_HandCards();
	cout << "1: Yes\n2: No\n";
	inputInt = input(1,2);
	
	if(inputInt == 2)
		return false;

	while (true) {
		cout << "Choose your trainer card\n";
		trainerCardLocation = input(1, currentTurnPlayer.getHandCardsSize());

		if (!currentTurnPlayer.isTrainerCard_inHand(trainerCardLocation-1))
			cout << "That isn't a trainer card.\n";
		else
			break;
	}

	switch (currentTurnPlayer.whichTrainerType(trainerCardLocation-1))
	{
	case TrainerType::POKEMON_CATCHER :
		//current location in programming
		cout << "Pokemon Catcher\n";
		if (!nextTurnPlayer.hasPokemonInBench()) {
			cout << nextTurnPlayer.getName() << " does not have a benched Pokemon to choose.\n";
			return false;
		}
		cout << "Choose a card for "<< nextTurnPlayer.getName() << " to replace active pokemon with.\n";
		nextTurnPlayer.print_BenchCards();
		inputInt = input(1, nextTurnPlayer.getBenchCardsSize());
		nextTurnPlayer.swapCards(inputInt-1);
		currentTurnPlayer.discardFromHand(trainerCardLocation-1);		
		break;
	
	case TrainerType::ENERGY_RETRIEVAL :
		cout << "Energy Retrieval\n";
		if (!currentTurnPlayer.canRetrieveEnergy()) {
			cout << "There isn't an energy card in the discard pile.\n";
			return false;
		}
		currentTurnPlayer.retrieveEnergy();
		break;
	
	case TrainerType::POTION :
		cout << "Potion Heal\n";
		currentTurnPlayer.potionHeal(trainerCardLocation-1);
		break;
	case TrainerType::ACROBIKE :
		cout << "Acro Bike\n";
		cout << "Pick one of the top two cards to put into your hand, discard the other\n";
		currentTurnPlayer.pick1from2(trainerCardLocation-1);
		break;
	case TrainerType::CRUSHING_HAMMER :
		cout << "Crushing Hammer\n";
		cout << "A coin will be flipped, if heads, your opponent will lose one energy from their active Pokemon.\n";
		nextTurnPlayer.crushingHammer();
		currentTurnPlayer.discardFromHand(trainerCardLocation-1);
		break;
	default:
		break;
	}
	return true;

}

/*Player's pokemon attack*/
void attack(Player& attackingPlayer, Player& defendingPlayer) {
	int inputInt;

	cout << attackingPlayer.getName() << " would you like to attack?";
	cout << "1: Yes\n2: No\n";
	inputInt = input(1,2);
	if (inputInt == 2)
		return;

	switch (attackingPlayer.getActivePokemonEnergyLevel()) {
		case 0:
			cout << "Your pokemon does not have energy to attack";
			break;
		case 1:
			defendingPlayer.activePokemonRecieveDamage(attackingPlayer.getActivePokemonAttack1());
			break;
		case 2:
			defendingPlayer.activePokemonRecieveDamage(attackingPlayer.getActivePokemonAttack1());
			break;
		case 3:
			defendingPlayer.activePokemonRecieveDamage(attackingPlayer.getActivePokemonAttack1());
			break;
		default:
			defendingPlayer.activePokemonRecieveDamage(attackingPlayer.getActivePokemonAttack1());
			break;
	}

}


/*Check if active Pokemon is dead*/
bool checkPokemonIsDead(Player& player) {
	if (player.getActivePokemonHP() <= 0)
		return true;
	return false;
}

bool chooseNewPokemon(Player& player) {
	int inputInt;
	int location;
	cout << player.getName() << " choose a new active Pokemon.\n";
	player.print_BenchCards();
	player.print_HandCards();

	cout << "Would you like to choose from the bench(1) or from the hand(2)?\n";
	inputInt = input(1,2);

	if (inputInt == 1) {
		player.print_BenchCards();
		cout << "Please choose which card.\n";
		location = input(1, player.getBenchCardsSize());
		location --;
		player.newActivePokemonfromBench(location);
		return true;		
	}
	if (inputInt == 2) {
		if (!player.hasPokemonInHand()) {
			cout << "No pokemon in hand\n";
			return chooseNewPokemon(player);
		}
		player.print_HandCards();
		cout << "Please choose which card.\n";
		location = input(1, player.getHandCardsSize());
		location --;
		player.newActivePokemonfromHand(location);
	}
	return false;
}