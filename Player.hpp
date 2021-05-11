#include <ctime>
#include <stdlib.h>
#include <algorithm>
#include <random>
#include <iostream>
#include "SK_Cards.hpp"

class Player {
    string name;

    /*Not sure if cards should be ptr to card, list would be better than vector*/
    vector <Card> pokemonDeck;	 //Deck of cards
	vector <Card> discardPile;	 //Pile of discarded cards
	vector <Card> prizeCards;	 //Prize Card Pile
    vector <Card> handCards;     //Cards on hand
    vector <Pokemon> benchCards; //Pokemon sitting on the bench
    Card activePokemon;          //Active Pokemon


public:
    Player(string name) {
        this->name = name;
        srand((unsigned) time(0)); //seed time for random



        //TODO: Store all Cards in Pokemon Deck//



        /*Shuffle the Deck*/
        shuffleDeck();

        /*Draw 7 cards and store into handCards*/
        for (int i = 0; i < 7; i++) { drawCard(); }

        /*Initialize Prize Cards with 6 cards*/
        for (int i = 0; i < 6; i++) {
            prizeCards.push_back(pokemonDeck.back()); //Last element of vector is copied to prizeCards
            pokemonDeck.pop_back();                   //Delete last element in pokemonDeck
        }

    }

    /*Shuffle @param pokemonDeck*/
    void shuffleDeck() {
        auto rng = std::default_random_engine {};
        std::shuffle(std::begin(pokemonDeck), std::end(pokemonDeck), rng);
    }

    /*If player does not have a Pokemon Card after intial drawing, reshuffle deck and redraw cards
     *The Oppenent will draw another card
     *Return True if mulligan happened
     */
    bool mulligan() {
        for (int i = 0; i < pokemonDeck.size(); i++) {
            if (pokemonDeck[i].getCardType() == CardType::POKEMON)
                return false;
        }

        shuffleDeck();

        /*Draw 7 cards and store into handCards*/
        for (int i = 0; i < 7; i++) {
            handCards.push_back(pokemonDeck.back()); //Last element of vector is copied to handCards
            pokemonDeck.pop_back();                   //Delete last element in pokemonDeck
        
        }
        return true;
    }

    void drawCard() {
        handCards.push_back(pokemonDeck.back()); //Last element of vector is copied to handCards
        pokemonDeck.pop_back();                  //Delete last element in pokemonDeck
    }

    void benchCards_toString() {
        for (int i = 0; i < benchCards.size(); i++) {
            cout << i << ": " << benchCards[i].getName() << endl;
        }
    }

    void handCards_toString() {
        for (int i = 0; i < handCards.size(); i++) {
            cout << i << ": " << handCards[i].getName() << endl;
        }
    }




    string getName() { return name; }
};