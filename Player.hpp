#pragma once
#include <ctime>
#include <stdlib.h>
#include <algorithm>
#include <random>
#include <iostream>
#include "Cards.hpp"
#include "Pokemon_list.hpp"




class Player {
    string name;

    /*Not sure if cards should be ptr to card, list would be better than vector*/
    vector <Card*> pokemonDeck;	  //Deck of cards
	vector <Card*> discardPile;	  //Pile of discarded cards
	vector <Card*> prizeCards;	  //Prize Card Pile
    vector <Card*> handCards;     //Cards on hand
    vector <Pokemon*> benchCards; //Pokemon sitting on the bench
    Pokemon * activePokemon;      //Active Pokemon


public:
    /*Constructor*/
    Player(string name) {
        this->name = name;
        Card* card_ptr;

        /*Store 20 Pokemon Cards in Deck of Cards*/
        for (int i = 0; i < 20; i++) {
            pokemonDeck.push_back(pokemonList.back());  //store pointer from back of list into vector
            pokemonList.pop_back();                     //remove stored point from list so it can't be re-used
            pokemonDeck.push_back(new EnergyCard);      //store new Energy cards
        }

        /*Store the 5 Trainer Cards 4 times each*/
        for (int i = 0; i < 4; i++) {
            pokemonDeck.push_back(new PokemonCatcher);
            pokemonDeck.push_back(new EnergyRetrieval);
            pokemonDeck.push_back(new Potion);
            pokemonDeck.push_back(new AcroBike);
            pokemonDeck.push_back(new CrushingHammer);
        }

        /*Shuffle the Deck*/
        shuffleDeck();  //not sure if function will actually work

        /*Draw 7 cards and store into handCards*/
        for (int i = 0; i < 7; i++) { drawCard(); }

        /*Initialize Prize Cards with 6 cards*/
        for (int i = 0; i < 6; i++) {
            prizeCards.push_back(pokemonDeck.back()); //Last element of vector is copied to prizeCards
            pokemonDeck.pop_back();                   //Delete last element in pokemonDeck
        }

    }

    /*Getters*/
    int getHandCardsSize()  { return handCards.size(); }
    int getBenchCardsSize() { return benchCards.size(); }
    string getName() { return name; }
    string getActivePokemonName() { return activePokemon->getName(); }

    /*Shuffle @param pokemonDeck*/
    void shuffleDeck() {
        // auto rng = std::default_random_engine {};
        // std::shuffle(std::begin(pokemonDeck), std::end(pokemonDeck), rng);

        Card*temp;
        int location;
        for (int i = 0; i < 200; i++) {
            location = rand()%pokemonDeck.size();
            temp = pokemonDeck[0];
            pokemonDeck[0] = pokemonDeck[location];
            pokemonDeck[location] = temp;
        }
    }

    /*If player does not have a Pokemon Card after intial drawing, reshuffle deck and redraw cards
     *The Oppenent will draw another card
     *Return True if mulligan happened
     */
    bool mulligan() {
        for (int i = 0; i < pokemonDeck.size(); i++) {
            if (pokemonDeck[i]->getCardType() == CardType::POKEMON)
                return false;
        }

        shuffleDeck();

        /*Draw 7 cards and store into handCards*/
        for (int i = 0; i < 7; i++) {
            drawCard();
        }
        return true;
    }

    /*Draw a card from pokemonDeck and place into players hand*/
    void drawCard() {
        if (handCards.size() < 1) {
            cout << "You don't have any cards left";
            return;
        }
        handCards.push_back(pokemonDeck.back()); //Last element of vector is copied to handCards
        pokemonDeck.pop_back();                  //Delete last element in pokemonDeck
    }

    /*Set active Pokemon, if the card chosen is not a Pokemon, return false*/
    bool setActivePokemon(int vectorLocation) {
        if (handCards[vectorLocation]->getCardType() != CardType::POKEMON)
            return false;

        activePokemon = (Pokemon*)handCards[vectorLocation]; //Cast Card* into Pokemon* and set it as activePokemon
        handCards.erase(handCards.begin() + vectorLocation); //Remove ptr from vector
        return true;
    }

    /*Displays all bench cards*/
    void print_BenchCards() {
        cout << "Bench Cards:\n";
        for (int i = 0; i < benchCards.size(); i++) {
            cout << i+1 << ": " << benchCards[i]->getName() << endl;
        }
    }

    /*Displays all cards on hand*/
    void print_HandCards() {
        cout << "Cards on Hand:\n";
        for (int i = 0; i < handCards.size(); i++) {
            cout << i+1 << ": " << handCards[i]->getName() << endl;
        }
    }

    /*Add energy to the Active Pokemon*/
    void addEnergy() {
        for (int i = 0; i < handCards.size(); i++) {
			if (handCards[i]->getCardType() == CardType::ENERGY ) {
				handCards.erase(handCards.begin() + i);
				activePokemon->incrementEnergy();
				return;
			} else {
                cout << "No energy card available.\n"; //throw exception here
            }
		}
    }

    /*Add energy to a pokemon on the bench*/
    void addEnergy(int benchCardLocation) {
        for (int i = 0; i < handCards.size(); i++) {
			if (handCards[i]->getCardType() == CardType::ENERGY ) {
				handCards.erase(handCards.begin() + i);
				benchCards.at(benchCardLocation)->incrementEnergy();
				return;
			} else {
                cout << "No energy card available.\n"; //throw exception here
            }
		}
    }

    /*Check to see if there is at leat one energy card in hand*/
    bool hasEnergyCardInHand() {
        for (int i = 0; i < handCards.size(); i++) {
            if (handCards.at(i)->getCardType() == CardType::ENERGY)
                return true;
        }
        return false;
    }

    /*Check to see if there is at least one trainer card on hand*/
    bool hasTrainerCardInHand() {
        for (int i = 0; i < handCards.size(); i++) {
            if (handCards.at(i)->getCardType() == CardType::TRAINER)
                return true;
        }
        return false;
    }


    /*Use the trainer card in the deck, if the location given doesn't work, return false*/
    bool isTrainerCard(int location) {
        if (handCards.at(location)->getCardType() != CardType::TRAINER) {
            return false; //throw
        }
        return true;
    }

    TrainerType whichTrainerType(int location) {
        if (isTrainerCard(location)) {
            TrainerCard* trainerCard = (TrainerCard*)handCards.at(location); //cast card as trainer ptr
            return trainerCard->trainerType;
        }
        //throw here
    }

    
    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////
                    /*Functions that use Trainer Cards functionality*/
    ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////

    /*Pokemon Catcher*/

    /*Swap opponents active pokemon with one on the bench*/
    void swapCards(Pokemon*& activeCard, Pokemon*& benchCard) {
		Pokemon * temp;
		temp = activeCard;
		activeCard = benchCard;
		benchCard = temp; //not sure if these changes will be out of scope
	}



    /*Energy Retrieval*/

    /*Check if the discard pile contains at least one energy type*/
	bool canRetrieveEnergy(vector<Card*>& discardPile) {
		for (int i =0; i < discardPile.size(); i++) {
			if (discardPile[i]->getCardType() == CardType::ENERGY)
				return true;
		}
		return false;
	}

	/*Retrieve at least one energy type card from the discard pile and push into handCards*/
	void retrieveEnergy(vector<Card*>& handCards, vector<Card*>& discardPile) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < discardPile.size(); j++) {
				if (discardPile[j]->getCardType() == CardType::ENERGY) {
					handCards.push_back(discardPile[j]);
					discardPile.erase(discardPile.begin() + j);//erase the element in vector
					break;
				}
			}
		}
	}



    /*Potion*/

    /*Heals by 30 HP*/
    void potionHeal(Pokemon* pokemon) {
		pokemon->Heal(30);
	}



    /*AcroBike*/

    /*allows player to peek at two cards on top of the deck and allows player to choose one card and discard another*/
    void pick1from2(vector <Card*>& pokemonDeck, vector <Card*>& handCards, vector <Card*>& discardPile) {
		Card *choice1, *choice2;
		int choiceSelection;
		choice1 = pokemonDeck.back();
		pokemonDeck.pop_back();

		choice2 = pokemonDeck.back();
		pokemonDeck.pop_back();

		cout << "1:\n";
		choice1->toString();
		cout << "\n2:\n";
		choice2->toString();
		cout << endl;		

		choiceSelection = input(1,2);

		if (choiceSelection == 1) {
			handCards.push_back(choice1);
			discardPile.push_back(choice2);
		} 
		else if(choiceSelection == 2) {
			handCards.push_back(choice2);
			discardPile.push_back(choice1);	
		}
		else {
			//TODO: Throw
		}
	}



    /*CrushingHammer*/

    /*decrements an energy from opponent if it lands on heads*/
    void crushingHammer(Pokemon*& activePokemon, vector<Card*>& discardPile) {
		cout << "A coin has been tossed\n";
		if (!coinFlip()) //if coin toss is tails
			cout << "Your opponent keeps energy\n";
		else {
			activePokemon->decrementEnergy(); //Decrement energy for the given activePokemon
			
			//keeping this here to mark error to look at this code later__________________________________________ put lines here to make it easier to spot
			discardPile.push_back(new EnergyCard); //not sure if this will work, also potential memory leak
		}

	}


};