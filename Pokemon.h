/*************************************************
 Class:			CSCI201-0CC-C1-202030-VI-16R
 Program:		Pokemon The Card Game
 Instructor:	Kristopher Roberts
 *************************************************/
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Card.h"
#include "ElementalType.h"
#include "Enumerators.h"



using namespace std;

/// <summary>
/// Pokemon
/// </summary>
class Pokemon {
private:
	int attack1;
	int attack2;
	int attack3;
	Element* element;	
	int hitPoints;
	int maxHP;
	std::string name;
public:
	Pokemon(std::string name, int maxHP) {
		this->attack1 = 10;
		this->attack2 = 25;
		this->attack3 = 40;
		setName(name);
		setMaxHP(maxHP);
		setHitPoints(0);
	}

	std::string getName() { return name; }

	int getMaxHP() {
		return this->maxHP;
	}

	int getHitPoints() {
		return this->hitPoints;
	}

	void Hit(int hit) {
		this->hitPoints += hit;
	}

	int getAttack1(){return attack1;}
	int getAttack2(){return attack2;}
	int getAttack3(){return attack3;}

	virtual Element* getElement() = 0;
	virtual std::string getAttack1Name() = 0;
	virtual std::string getAttack2Name() = 0;
	virtual std::string getAttack3Name() = 0;

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

