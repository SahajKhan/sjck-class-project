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

/*Choose new active Pokemon*/
bool chooseNewActivePokemon(Player &player);

/*Display information about the active pokemon*/
void displayActivePokemonStats(Player& player);

/*Checks to see if player has energy on hand, if so give player the option to use it*/
void checkAndUseEnergy(Player& player);

/*Checks to see if player has a trainer card on hand, and gives the option to use it, return true if card was used*/
bool useTrainerCard(Player& currentTurnPlayer, Player& nextTurnPlayer);

/*Player's pokemon attack*/
void attack(Player& attackingPlayer, Player& defendingPlayer);

/*Check if active Pokemon is dead*/
bool checkPokemonIsDead(Player& player);

/*Move a pokemon to the bench from hand*/
void choosePokemonToBench(Player& player);

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
			cout << "You lose your turn, your deck will be shuffled. Pick a pokemon, but you cannot use energy or trainer cards this turn.\n" << endl; 
			chooseNewActivePokemon(Player_1);
		} else {
			chooseNewActivePokemon(Player_1);
			checkAndUseEnergy(Player_1);
		}

		cout << Player_2.getName() << " gets to go.\n";
		if (Player_2.mulligan()) {
			cout << "You do not have a Pokemon to choose from.\n";
			cout << "You lose your turn, your deck will be shuffled. Pick a pokemon, but you cannot use energy or trainer cards this turn.\n" << endl;
			Player_2.shuffleDeck();
			chooseNewActivePokemon(Player_2);
		} else {
			chooseNewActivePokemon(Player_2);
			checkAndUseEnergy(Player_2);
		}
	}

	else {
	
		cout << Player_2.getName() << " gets to go.\n";
		if (Player_2.mulligan()) {
			cout << "You do not have a Pokemon to choose from.\n";
			cout << "You lose your turn, your deck will be shuffled. Pick a pokemon, but you cannot use energy or trainer cards this turn.\n" << endl;
			Player_2.shuffleDeck();
			chooseNewActivePokemon(Player_2);
		} else {
			chooseNewActivePokemon(Player_2);
			checkAndUseEnergy(Player_2);
		}

		cout << Player_1.getName() << " gets to go.\n";
		if (Player_1.mulligan()) {
			cout << "You do not have a Pokemon to choose from.\n";
			cout << "You lose your turn, your deck will be shuffled. Pick a pokemon, but you cannot use energy or trainer cards this turn.\n" << endl;
			Player_1.shuffleDeck();
			chooseNewActivePokemon(Player_1);
			
		} else {
			chooseNewActivePokemon(Player_1);
			checkAndUseEnergy(Player_1);
		}
	}


	/*Now the game starts*/
	while (true) {
		cout << Player_1.getName() << "'s turn\n";

		displayActivePokemonStats(Player_1);
		//if hand deck has energy, give player the option to use it on bench cards or active pokemon, give player chance to not use energy
		checkAndUseEnergy(Player_1);

		//now allow player to use one trainer card if it applies, give player option to skip
		if (!useTrainerCard(Player_1, Player_2))
			cout << "Trainer Card could not be used\n";

		choosePokemonToBench(Player_1);
		
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
			Player_2.discardActivePokemon();
			chooseNewActivePokemon(Player_2);
		}
		Player_1.drawCard();




		cout << Player_2.getName() << "'s turn\n";
		displayActivePokemonStats(Player_2);
		//if hand deck has energy, give player the option to use it on bench cards or active pokemon, give player chance to not use energy
		checkAndUseEnergy(Player_2);

		//now allow player to use one trainer card if it applies, give player option to skip
		if (!useTrainerCard(Player_2, Player_1))
			cout << "Trainer Card could not be used\n";
		
		choosePokemonToBench(Player_2);

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
			Player_2.discardActivePokemon();
			chooseNewActivePokemon(Player_1);
		}
		Player_2.drawCard();
	}


	return 0;
}


void displayActivePokemonStats(Player& player) {
	cout << "Active Pokemon: " << player.getActivePokemonName() << endl;
	cout << player.getActivePokemonName() << " HP: " << player.getActivePokemonHP() << endl;
	cout << player.getActivePokemonName() << " Attack 1: " << player.getActivePokemonAttack1() << endl;
	cout << player.getActivePokemonName() << " Attack 2: " << player.getActivePokemonAttack2() << endl;
	cout << player.getActivePokemonName() << " Attack 3: " << player.getActivePokemonAttack3() << endl;
	cout << player.getActivePokemonName() << " Energy Level: " << player.getActivePokemonEnergyLevel() << endl;
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

	cout << "Select a card to use energy for\n";
	player.print_BenchCards();
	cout << endl;
	cout << player.getBenchCardsSize()+1 << ": Active Pokemon: " << player.getActivePokemonName() << endl;
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
	
	cout << "Would you like to choose a trainer card to use?\n";
	currentTurnPlayer.print_HandCards();
	cout << endl;
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

	switch (currentTurnPlayer.whichTrainerType(trainerCardLocation-1)) {
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
		cout << "Move up to two Energy Cards from discard pile to then hand\n";
		if (!currentTurnPlayer.canRetrieveEnergy()) {
			cout << "There isn't an energy card in the discard pile.\n";
			return false;
		}
		currentTurnPlayer.retrieveEnergy();
		break;
	
	case TrainerType::POTION :
		cout << "Potion Heal\n";
		cout << "Heal 30 health\n";
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

void choosePokemonToBench (Player& player) {
	int inputInt, location;

	if(!player.hasPokemonInHand())
		return;

	cout << "Would you like to choose a Pokemon from hand to bench?\n";
	cout << "1: Yes\n2: No\n";
	inputInt = input(1,2);
	
	if (inputInt == 2)
		return;

	while (true) {
			cout << "Choose Pokemon,\n";
			location = input(1, player.getHandCardsSize());

			if (!player.isPokemonCard_inHand(location - 1)) {
				cout << "You did not choose a Pokemon\n Try again.";
			} 
			else 
				break;	
		}
}

/*Player's pokemon attack*/
void attack(Player& attackingPlayer, Player& defendingPlayer) {
	int inputInt;

	cout << attackingPlayer.getName() << " would you like to attack?\n";
	cout << "1: Yes\n2: No\n";
	inputInt = input(1,2);
	if (inputInt == 2)
		return;

	cout << attackingPlayer.getActivePokemonName() << " has done ";

	switch (attackingPlayer.getActivePokemonEnergyLevel()) {
		case 0:
			cout << "Your pokemon does not have energy to attack";
			break;
		case 1:
			defendingPlayer.activePokemonRecieveDamage(attackingPlayer.getActivePokemonAttack1());
			cout << attackingPlayer.getActivePokemonAttack1() << " damage to ";
			break;
		case 2:
			defendingPlayer.activePokemonRecieveDamage(attackingPlayer.getActivePokemonAttack1());
			cout << attackingPlayer.getActivePokemonAttack2() << " damage to ";
			break;
		case 3:
			defendingPlayer.activePokemonRecieveDamage(attackingPlayer.getActivePokemonAttack1());
			cout << attackingPlayer.getActivePokemonAttack3() << " damage to ";
			break;
		default:
			defendingPlayer.activePokemonRecieveDamage(attackingPlayer.getActivePokemonAttack1());
			cout << attackingPlayer.getActivePokemonAttack1() << " damage to ";
			break;
	}

	cout << defendingPlayer.getActivePokemonName() << endl;
	cout << defendingPlayer.getActivePokemonName() << " HP Remaining: " << defendingPlayer.getActivePokemonHP() << endl;

}


/*Check if active Pokemon is dead*/
bool checkPokemonIsDead(Player& player) {
	if (player.getActivePokemonHP() <= 0)
		return true;
	return false;
}

/*Choose a new Pokemon*/
bool chooseNewActivePokemon(Player& player) {
	int inputInt;
	int location;
	cout << player.getName() << " choose a new active Pokemon.\n";
	player.print_BenchCards();
	player.print_HandCards();

	cout << "Would you like to choose from the bench(1) or from the hand(2)?\n";
	inputInt = input(1,2);

	if (inputInt == 1) {
		player.print_BenchCards();
		if (!player.hasPokemonInBench()) {
			cout << "There isn't a Pokemon in your Bench\nTry Again\n";
			return chooseNewActivePokemon(player);
		}

		while (true) {
			cout << "Choose your active Pokemon,\n";
			location = input(1, player.getBenchCardsSize());

			if (!player.newActivePokemonfromBench(location - 1)) {
				cout << "You did not choose a Pokemon\n Try again.";
			} 
			else 
				break;	
		}
	}


	if (inputInt == 2) {
		if (!player.hasPokemonInHand()) {
			cout << "No pokemon in hand\n";
			return chooseNewActivePokemon(player);
		}

		while (true) {
			cout << "Choose your active Pokemon,\n";
			location = input(1, player.getHandCardsSize());

			if (!player.newActivePokemonfromHand(location - 1)) {
				cout << "You did not choose a Pokemon\n Try again.";
			} 
			else 
				break;	
		}
	}

	cout << "Your active Pokemon is: " << player.getActivePokemonName() << endl;
	return true;
}