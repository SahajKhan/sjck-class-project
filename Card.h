/*************************************************
 Class:			CSCI201-0CC-C1-202030-VI-16R
 Program:		Pokemon The Card Game
 Instructor:	Kristopher Roberts
 *************************************************/
#pragma once
#include <string>
#include <vector>
#include "Pokemon.h"
#include "Enumerators.h"
class Card {
protected:
	bool isDiscarded;	
	bool isPrizeCard;
public:
	Card() {
		isDiscarded = false;
		isPrizeCard = false;
	}
	~Card() {

	}

	void Discard() {
		this->isDiscarded = true;
	}

};

