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
#include "Enumerators.hpp"
#include "ElementalType.hpp"
using namespace std;

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
	Element* element;			//Element Type
public:
	Pokemon(std::string name, string attack1Name, string attack2Name, string attack3Name, Element* element) {
		srand((unsigned) time(0));

		attack1 = (rand()%19) + 1;		//attack1 will be an int from 1 - 20
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
		if (energyLevel = 0)
			return;
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
			hitPoints = maxHP;
		else
			hitPoints += healingAmount;
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
	TrainerCard() {
		cardType = CardType::TRAINER;
	}

	string toString() {
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

class PokemonCatcher : TrainerCard{
public:
	PokemonCatcher() { 
		name = "Pokemon Catcher";
		cardFunction = "Trade your opponents active card with one on bench";
	}

	void swapCards(Pokemon& activeCard, Pokemon& benchCard) {
		Pokemon * temp;
		temp = &activeCard;
		activeCard = benchCard;
		benchCard = *temp;
	}
};

class EnergyRetrieval : TrainerCard{
public:
	EnergyRetrieval() {
		name = "Energy Retrieval";
		cardFunction = "Put up to 2 basic Energy Cards from your discard pile into your hands";
	}

	/*Check if the discard pile contains at least one energy type*/
	bool energyRetrieval(vector<Card>& discardPile) {
		for (int i =0; i < discardPile.size(); i++) {
			if (discardPile[i].getCardType() == CardType::ENERGY)
				return true;
		}
		return false;
	}

	/*Retrieve at least one energy type card from the discard pile and push into handCards*/
	void energyretrieve(vector<Card>& handCards, vector<Card>& discardPile) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < discardPile.size(); j++) {
				if (discardPile[j].getCardType() == CardType::ENERGY) {
					handCards.push_back(discardPile[j]);
					discardPile.erase(discardPile.begin() + j);//erase the element in vector
					break;
				}
			}
		}
	}
};

class Potion : TrainerCard {
public:
	Potion() {
		name = "Potion";
		cardFunction = "Heal 30 damage from your active Pokemon";
	}
	void potionHeal(Pokemon& pokemon) {
		pokemon.Heal(30);
	}
};

class AcroBike: TrainerCard {
public:
	AcroBike() {
		name = "Acrobike";
		cardFunction = "Look at the top 2 cards of your deck and put 1 of them into your hand.\nDiscard the other card";
	}
	void pick1from2(vector <Card>& pokemonDeck) {
		Card choice1, choice2;
		
		choice1 = pokemonDeck.back();
		pokemonDeck.pop_back();

		choice2 = pokemonDeck.back();
		pokemonDeck.pop_back();

		cout << "1:\n";
		choice1.toString();
		cout << "\n2:\n";
		choice2.toString();
		cout << endl;		
	}
};

class CrushingHammer: TrainerCard {
public:
	CrushingHammer() {
		name = "Crushing Hammer";
		cardFunction = "Flip a coin. If heads, discard an Energy from 1 of your Openents Active Pokemon";
	}
	void crushingHammer(Pokemon& activePokemon, vector<Card>& discardPile) {
		cout << "A coin has been tossed\n";
		if (!coinFlip()) //if coin toss is tails
			cout << "Your opponent keeps energy\n";
		else {
			activePokemon.decrementEnergy();
			Card * newEnergyCard = new EnergyCard;

			asdf //keeping this here to mark error to look at this code later
			discardPile.push_back(*newEnergyCard); //not sure if this will work, also potential memory leak
		}

	}

}

/*Energy Card Type*/
class EnergyCard : public Card{
public:
	EnergyCard() {
		name = "Energy";
		cardType = CardType::ENERGY;
	}

	void useEnergy(Pokemon& card, vector <Card>& handCards) {
		for (int i = 0; i < handCards.size(); i++) {
			if (handCards[i].getCardType() == CardType::ENERGY ) {
				handCards.erase(handCards.begin() + i);
				card.incrementEnergy();
				break;
			}
				
		}

	}
	
};