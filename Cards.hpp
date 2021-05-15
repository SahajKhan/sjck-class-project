/*************************************************
 Class:			CSCI201-0CC-C1-202030-VI-16R
 Program:		Pokemon The Card Game
 Instructor:	Kristopher Roberts
 *************************************************/
#pragma once
#include <string>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include "ElementalType.hpp"
#include "Functions.hpp"
using namespace std;

enum class CardType {POKEMON, TRAINER, ENERGY};
enum class TrainerType {POKEMON_CATCHER, ENERGY_RETRIEVAL, POTION, ACROBIKE, CRUSHING_HAMMER};

/*Base Card Type*/
class Card {
protected:
	string name;	//Name of Card or Pokemon
	CardType cardType;
public:
	string getName() { return name; }
	CardType getCardType() { return cardType; }
	string toString();
};

/*Pokemon Card Type*/
class Pokemon: public Card {
protected:
	unsigned int attack1;		//Damage the first attack makes
	unsigned int attack2;		//Damage the second attack makes
	unsigned int attack3;		//Damage the third attack makes
	unsigned int hitPoints;		//Current Health
	unsigned int maxHP;			//Max Health
	unsigned int energyLevel;	//Energy points on the card
	string attack1Name;			//Name of the first attack
	string attack2Name; 		//Name of the second attack
	string attack3Name; 		//Name of the third attack
	Element* element = nullptr;			//Element Type
public:
	Pokemon(std::string name, string attack1Name, string attack2Name, string attack3Name, Element* element) {
		srand((unsigned) time(0));
		this->name = name;

		attack1 = (rand()%20) + 1;		//attack1 will be an int from 1 - 20  ** would we need to change it to the %21 since I think it starts the rand starts at 0?
		attack2 = (rand()%49) + 21;		//attack2 will be an int from 21 - 70
		attack3 = (rand()%69) + 71;		//attack3 will be an int from 71 - 140

		this->attack1Name = attack1Name;
		this->attack2Name = attack2Name;
		this->attack3Name = attack3Name;

		this->element = element;

		maxHP = (rand()%120) + 30; 		//hitPoints will be an int from 30 to 150
		hitPoints = maxHP;				//Current hitpoint are max
		energyLevel = 0;
		cardType = CardType::POKEMON;
	}

	~Pokemon() {
		delete element;
		element = NULL;
	}

	/*Getters*/
	int getAttack1() { return attack1; }
	int getAttack2() { return attack2; }
	int getAttack3() { return attack3; }
	int getMaxHP()   { return maxHP; }
	int getHitPoints() { return hitPoints; }
	int getEnergyLevel() { return energyLevel; }
	Element* getElement() { return element; }
	string getAttack1Name() { return attack1Name; }
	string getAttack2Name() { return attack2Name; }
	string getAttack3Name() { return attack3Name; }

	/*Increase energyLevel by 1*/
	void incrementEnergy() { energyLevel++; }
	void decrementEnergy() { 
		if (energyLevel != 0)
			energyLevel--;
	}

	/*Damage Pokemon*/
	void recieveDamage(const int damage) { 
		if (damage > hitPoints)
			hitPoints = 0;
		else
			hitPoints -= damage;
	}

	/*Heal Pokemon*/
	void Heal(const int healingAmount) {
		/* So that the Pokemon does not heal less than 0 hitpoints */
		if (healingAmount > hitPoints)
			hitPoints = maxHP; // do we need to destroy/discard the healing card? wasnt sure how you had that programmed
		else
			hitPoints += healingAmount;

		/*TODO:
				Move potion card to discard pile*/
	}

	bool containsEnergy() {
		if (energyLevel > 0)
			return true;
		return false;
	}

	void toString() {
		cout << name << "\tHP: " << getHitPoints() << endl;
		cout << "Attack 1: " << getAttack1Name() << " " << getAttack1() << endl;
		cout << "Attack 2: " << getAttack2Name() << " " << getAttack2() << endl;
		cout << "Attack 3: " << getAttack3Name() << " " << getAttack3() << endl;
		cout << "Element: "  << element->getElementType_String() << endl;
		cout << "Energy Level: " << energyLevel << endl;
	}

	/*Overload << operator to output name*/
	friend ostream &operator<<(ostream &out, Pokemon *p){
		out << p->getName();
		return out;
	}
};



/*Trainer Card Type*/
class TrainerCard : public Card{
public:
	string cardFunction;
	TrainerType trainerType;
	TrainerCard() {
		cardType = CardType::TRAINER;
	}

	void toString() {
		cout << "Name: " << name << endl;
		cout << "Card Function: " << cardFunction;
	}
	
	//Card Type one: trade opponents active card on hand with one on bench
	//Pokemon Catcher

	//Card type two: pick two energy cards from discard pile and move to hand
	//Energy Retrieval

	//Card type three: heal your active pokemon by 30 HP
	//Potion

	//Card type four: look at the top 2 cards in your deck and put 1 of them into your hand. Discard the other card
	//AcroBike

	//type 5:
	//flip a coin, if heads, discard an energy attached to your opponents pokemon
	//crushing hammer
};




/*Energy Card Type*/
class EnergyCard : public Card{
public:
	EnergyCard() {
		name = "Energy";
		cardType = CardType::ENERGY;
	}	
};





// Trainer that card swaps opponents active pokemon with one on the bench
class PokemonCatcher :public TrainerCard{
public:
	PokemonCatcher() { 
		name = "Pokemon Catcher";
		cardFunction = "Trade your opponents active card with one on bench";
		trainerType = TrainerType::POKEMON_CATCHER;
	}
};

//Trainer Card that retrieves 2 discarded energy cards
class EnergyRetrieval :public TrainerCard{
public:
	EnergyRetrieval() {
		name = "Energy Retrieval";
		cardFunction = "Put up to 2 basic Energy Cards from your discard pile into your hands";
		trainerType = TrainerType::ENERGY_RETRIEVAL;
	}
};

//Trainer card that heal only the active pokemon
class Potion :public TrainerCard {
public:
	Potion() {
		name = "Potion";
		cardFunction = "Heal 30 damage from your active Pokemon";
		trainerType = TrainerType::POTION;
	}
	
};
// Trainer card that allows player to peek at two cards on top of the deck and allows player to choose one card and discard another
class AcroBike: public TrainerCard {
public:
	AcroBike() {
		name = "Acrobike";
		cardFunction = "Look at the top 2 cards of your deck and put 1 of them into your hand.\nDiscard the other card";
		trainerType = TrainerType::ACROBIKE;
	}
	
};

//Trainer card that decrements an energy from opponent if it lands on heads
class CrushingHammer :public TrainerCard {
public:
	CrushingHammer() {
		name = "Crushing Hammer";
		cardFunction = "Flip a coin. If heads, discard an Energy from 1 of your Openents Active Pokemon";
		trainerType = TrainerType::CRUSHING_HAMMER;
	}
};
