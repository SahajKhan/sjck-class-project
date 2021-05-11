/*************************************************
 Class:			CSCI201-0CC-C1-202030-VI-16R
 Program:		Pokemon The Card Game
 Instructor:	Kristopher Roberts
 *************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
#include "DerivedPokemon.h"
#include "Enumerators.h"


int main() {
	std::vector<Pokemon*> pokemonDeck;
	pokemonDeck.push_back(new Geodude());
	pokemonDeck.push_back(new Squirtle());
	pokemonDeck.push_back(new Mew());

	std::vector<Pokemon*>::iterator it;
	for(it = pokemonDeck.begin(); it != pokemonDeck.end(); it++){
		std::cout << *it << std::endl;
	}

	return 0;
}
