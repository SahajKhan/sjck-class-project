/*************************************************
 Class:			CSCI201-0CC-C1-202030-VI-16R
 Program:		Pokemon The Card Game
 Instructor:	Kristopher Roberts
 *************************************************/
#pragma once
#include <iostream>
#include <string>
#include "Pokemon.h"
#include "Enumerators.h"

class Element {
protected:
	int weaknessMultiplier;
	int resistanceMultiplier;
	ElementType weaknessType;
	ElementType resistanceType;
	ElementType attackType;
public:
	Element(ElementType attackType, ElementType weak, ElementType resistant, bool flyingType = false) {
		this->attackType = attackType;
		this->weaknessType = weak;
		this->resistanceType = resistant;
		this->weaknessMultiplier = 2;		// Pokemon Takes 2 times the damage if weak against attack 
		this->resistanceMultiplier = 20;	// Pokemon takes 20 less damage if resistance to attack
	}


	int getWeaknessMultiplier() { return this->weaknessMultiplier; }
	int getResistanceMultiplier() { return this->resistanceMultiplier; }
	ElementType getWeaknessType() { return this->weaknessType; }
	ElementType getResistanceType() { return this->resistanceType; }
	ElementType getAttackType() { return this->attackType; }
};



/*******************************************************************************************
 Fire Type Pokemon
 Usual Weakness:  WATER
 Resistance: NONE
 ******************************************************************************************/
class Fire : public Element {
public:
	Fire()
		: Element(ElementType::FIRE, ElementType::WATER, ElementType::FIRE) {}
};



/*******************************************************************************************
 Water Type Pokemon
 Usual Weakness:  Lightning
 Resistance: NONE
 ******************************************************************************************/
class Water : public Element {
public:
	Water()
		: Element(ElementType::WATER, ElementType::LIGHTNING, ElementType::WATER) {}

};




/*******************************************************************************************
 PSYCHIC Type Pokemon
 Usual Weakness:  PSYCHIC
 Resistance: NONE
 ******************************************************************************************/
class Psychic : public Element {
public:
	Psychic()
		: Element(ElementType::PSYCHIC, ElementType::COLORLESS, ElementType::PSYCHIC) {}

};


/*******************************************************************************************
 GRASS Type Pokemon
 Usual Weakness:  FIRE
 Resistance: WATER
 ******************************************************************************************/
class Grass : public Element {
public:
	Grass()
		: Element(ElementType::GRASS, ElementType::FIRE, ElementType::GRASS) {}

};



/*******************************************************************************************
 LIGHTNING Type Pokemon
 Usual Weakness:  FIGHTING
 Resistance: NONE
 ******************************************************************************************/
class Lightning : public Element {
public:
	Lightning()
		: Element(ElementType::LIGHTNING, ElementType::GRASS, ElementType::LIGHTNING) {}

};

/*******************************************************************************************
 COLORLESS Type Pokemon
 Usual Weakness:  {FIGHTING, LIGHTNING, NONE}
 Resistance: NONE
 ******************************************************************************************/
class Colorless : public Element {
public:
	Colorless()
		: Element(ElementType::COLORLESS, ElementType::PSYCHIC, ElementType::COLORLESS) {}
};
