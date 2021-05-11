/*************************************************
 Class:			CSCI201-0CC-C1-202030-VI-16R
 Program:		Pokemon The Card Game
 Instructor:	Kristopher Roberts
 *************************************************/
#pragma once
#include <string>
#include "SK_Enumerators.hpp"
#include "ElementalType.h"
using namespace std;

class Card {
protected:
	string name;	//Name of Card or Pokemon
	CardType cardType;
public:
	string getName() { return name; }
	CardType getCardType() { return cardType; }

};


/*Pokemon Card Type*/
class Pokemon: public Card {
protected:
	int attack1;		//Damage the first attack makes
	int attack2;		//Damage the second attack makes
	int attack3;		//Damage the third attack makes
	string attack1Name;	//Name of the first attack
	string attack2Name; //Name of the second attack
	string attack3Name; //Name of the third attack
	Element* element;	//Element Type
	int hitPoints;		//Current Health
	int maxHP;			//Max Health
public:
	Pokemon(std::string name, int maxHP) {
		this->attack1 = 10;
		this->attack2 = 25;
		this->attack3 = 40;
		setName(name);
		setMaxHP(maxHP);
		setHitPoints(0);
		cardType = CardType::POKEMON;
	}

	~Pokemon() {
		delete element;
		element = NULL;
	}

	int getMaxHP() { return this->maxHP; }

	int getHitPoints() { return this->hitPoints; }

	void recieveDamage(int damage) { hitPoints -= damage; }

	int getAttack1(){return attack1;}
	int getAttack2(){return attack2;}
	int getAttack3(){return attack3;}

	// virtual Element* getElement() = 0;
	// virtual std::string getAttack1Name() = 0;
	// virtual std::string getAttack2Name() = 0;
	// virtual std::string getAttack3Name() = 0;

	Element* getElement() { return this->element;}
	std::string getAttack1Name() {return this->attack1Name;}
	std::string getAttack2Name() {return this->attack2Name;}
	std::string getAttack3Name() {return this->attack3Name;}

	friend ostream &operator<<(ostream &out, Pokemon *p){
		out << p->getName();
		return out;
	}
private:
	void setHitPoints(int hitPoints) {
		if (hitPoints < 0)
			throw std::underflow_error("Hit points can not be less than 0.");
		this->hitPoints = hitPoints;
	}
	void Heal(int healingItem) {
		/* So that the Pokemon does not heal less than 0 hitpoints */
		if (healingItem > getHitPoints())
			this->hitPoints -= (healingItem - getHitPoints());
		else
			this->hitPoints -= healingItem;
	}
	void setMaxHP(int newHP) {
		if (newHP <= 0)
			throw std::underflow_error("Pokemon can not have 0 max HP.");
		this->maxHP = newHP;
	}
	void setName(std::string s) {
		this->name = s;
	}
};

/*Trainer Card Type*/
class TrainerCard : public Card{
public:
	string cardFunction;
	TrainerCard() {
		cardType = CardType::TRAINER;
	}

	//Card Type one: trade card on hand with one on bench
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