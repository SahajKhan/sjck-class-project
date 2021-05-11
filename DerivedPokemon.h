/*************************************************
 Class:			CSCI201-0CC-C1-202030-VI-16R
 Program:		Pokemon The Card Game
 Instructor:	Kristopher Roberts
 *************************************************/

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Pokemon.h"
#include "ElementalType.h"
#include "Enumerators.h"

/// <summary>
/// <para>Squirtle - BASIC </para>
/// <para>Max HP: 50</para>
/// <para>Element Type: Water</para>
class Squirtle : public Pokemon {
private:
	string attack1Name;
	string attack2Name;
	string attack3Name;
	Element* element;
public:
	/// <param name = "None"> No parameters </param>
	Squirtle() : 
	Pokemon("Squirtle", 50) {
		this->attack1Name = "Tackle";
		this->attack2Name = "Bubble";
		this->attack3Name = "Water Gun";
		this->element = new Water();
	}
	~Squirtle() {
		delete element;
		element = NULL;
	}

	Element* getElement() { return this->element;}
	std::string getAttack1Name() {return this->attack1Name;}
	std::string getAttack2Name() {return this->attack2Name;}
	std::string getAttack3Name() {return this->attack3Name;}
};



/// <summary>
/// <para>Wartortle - STAGE_1 </para>
/// <para>Max HP: 80</para>
/// <para>Element Type: Water</para>
/// <para>Weakness: Lightning</para>
class Wartortle : public Pokemon {
private:
	string attack1Name;
	string attack2Name;
	string attack3Name;
	Element* element;
public:
	Wartortle() : 
	Pokemon("Wartortle", 80) {
		this->attack1Name = "Water Gun";
		this->attack2Name = "Surf";
		this->attack3Name = "Critical Surf";
		this->element = new Water();
	}
	~Wartortle() {
		delete element;
		element = NULL;
	}

	Element* getElement() { return this->element;}
	std::string getAttack1Name() {return this->attack1Name;}
	std::string getAttack2Name() {return this->attack2Name;}
	std::string getAttack3Name() {return this->attack3Name;}
};



/// <summary>
/// <para>Blastoise - STAGE_2 </para>
/// <para>Max HP: 180</para>
/// <para>Element Type: Water</para>
/// <para>Weakness: Lightning</para>
class Blastoise : public Pokemon {
private:
	string attack1Name;
	string attack2Name;
	string attack3Name;
	Element* element;
public:
	Blastoise() : 
	Pokemon("Blastoise", 180) {
		this->attack1Name = "Tackle";
		this->attack2Name = "Water Gun";
		this->attack3Name = "Critical Water Gun";
		this->element = new Water();
	}
	~Blastoise() {
		delete element;
		element = NULL;
	}

	Element* getElement() {return this->element; }
	std::string getAttack1Name() {return this->attack1Name;}
	std::string getAttack2Name() {return this->attack2Name;}
	std::string getAttack3Name() {return this->attack3Name;}
};



/// <summary>
/// <para>Eevee - BASIC </para>
/// <para>Max HP: 80</para>
/// <para>Element Type: Colorless</para>
class Eevee : public Pokemon {
private:
	string attack1Name;
	string attack2Name;
	string attack3Name;
	Element* element;
public:
	Eevee() : 
	Pokemon("Eevee", 80) {
		this->attack1Name = "Wags Tail";
		this->attack2Name = "Tackle";
		this->attack3Name = "Critical Tackle";
		element = new Colorless();
	}
	~Eevee() {
		delete element;
		element = NULL;
	}

	Element* getElement() { return this->element;}
	std::string getAttack1Name() {return this->attack1Name;}
	std::string getAttack2Name() {return this->attack2Name;}
	std::string getAttack3Name() {return this->attack3Name;}
};

/**
 * Jordan's Pokemon 
 * */
class Geodude : public Pokemon {		
private:
	string attack1Name;
	string attack2Name;
	string attack3Name;
	Element* element;
public:
	Geodude() : 					
		Pokemon("Geodude", 70) {
		this->attack1Name = "Rock Throw";
		this->attack2Name = "Stone Barrage";
		this->attack3Name = "Critical Rock Throw";
		this->element = new Grass();
	}
	~Geodude() {
		delete element;
		element = NULL;
	}

	Element* getElement() { return this->element; }
	std::string getAttack1Name() { return this->attack1Name; }
	std::string getAttack2Name() { return this->attack2Name; }
	std::string getAttack3Name() { return this->attack3Name; }

};

class Mew : public Pokemon {		
private:
	string attack1Name;
	string attack2Name;
	string attack3Name;
	Element* element;
public:
	Mew() : 					
		Pokemon("Mew", 50) {
		this->attack1Name = "Psywave";
		this->attack2Name = "Devolution Beam";	
		this->attack3Name = "Critical PsyWave";
		this->element = new Psychic();		
								
	}
	~Mew() {
		delete element;
		element = NULL;
	}

	Element* getElement() { return this->element; }
	std::string getAttack1Name() { return this->attack1Name; }
	std::string getAttack2Name() { return this->attack2Name; }
	std::string getAttack3Name() { return this->attack3Name; }

};

class Mewtwo : public Pokemon {		
private:
	string attack1Name;
	string attack2Name;
	string attack3Name;
	Element* element;
public:
	Mewtwo() : 					
		Pokemon("Mewtwo", 130) {
		this->attack1Name = "Psyjack";
		this->attack2Name = "Break Burn";
		this->attack3Name = "Critical Psyjack";
		this->element = new Psychic();
	}
	~Mewtwo() {
		delete element;
		element = NULL;
	}

	Element* getElement() { return this->element; }
	std::string getAttack1Name() { return this->attack1Name; }
	std::string getAttack2Name() { return this->attack2Name; }
	std::string getAttack3Name() { return this->attack3Name; }

};

class Gengar : public Pokemon {
private:
	string attack1Name;
	string attack2Name;
	string attack3Name;
	Element* element;
public:
	Gengar() : 				
		Pokemon("Gengar", 100) {
		this->attack1Name = "Cursed Reasction";
		this->attack2Name = "Super Psy Bolt";
		this->attack3Name = "Critical Super Psy Bolt";
		this->element = new Psychic();
	}
	~Gengar() {
		delete element;
		element = NULL;
	}

	Element* getElement() { return this->element; }
	std::string getAttack1Name() { return this->attack1Name; }
	std::string getAttack2Name() { return this->attack2Name; }
	std::string getAttack3Name() { return this->attack3Name; }

};

/**
 * End of Jordan's Pokémon
 * */


/**
 * Pokemon Template
 * */
/*
class __________ : public Pokemon {		// <-- Name your pokemon
private:
	string attack1Name;
	string attack2Name;
	string attack3Name;
	Element* element;
public:
	_____________() : 							// <-- Add the name of your pokemon to the constructor
	Pokemon("_________", __) {					// input name of pokemon as first parameter(string), total HP in second parameter (int)
		this->attack1Name = "___________";		// <-- input the name of first attack; string type (string )
		this->attack2Name = "___________";		// <-- input the name of second attack; string type (string )
		this->attack3Name = "___________";		// <-- input the name of third attack or name it critical second attack; (string )
		this->element = new ___________();		// <--- input your pokemon's element TYPE
								// elements to choose from: Psychic, Colorless, Fire, Grass, Water, Lightning 
	}
	~__________() {						// <-- add name of Pokemon to the destructor
		delete element;
		element = NULL;
	}

	Element* getElement() { return this->element;}
	std::string getAttack1Name() {return this->attack1Name;}
	std::string getAttack2Name() {return this->attack2Name;}
	std::string getAttack3Name() {return this->attack3Name;}

};
*/
