//maybe create a list<pokemon> and randomly select 20 and store into players vector pile
#pragma once
#include <list>
#include "ElementalType.hpp"
#include "Cards.hpp"

list <Card*> pokemonList; //global

class creatingPokemon {
public:
    /*Function will create the pokemon and return the pointer*/
    Card* createPokemon(string name, string attack1Name, string attack2Name, string attack3Name, ElementType elementType) {
        Element* element_ptr;
        Card* card_ptr;

        switch(elementType) {
            case ElementType::COLORLESS:
                element_ptr = new Colorless;
                break;
            case ElementType::FIRE:
                element_ptr = new Fire;
                break;
            case ElementType::GRASS:
                element_ptr = new Grass;
                break;
            case ElementType::LIGHTNING:
                element_ptr = new Lightning;
                break;
            case ElementType::PSYCHIC:
                element_ptr = new Psychic;
                break;
            case ElementType::WATER:
                element_ptr = new Water;
                break;
            default:
                break;
        }

        card_ptr = new Pokemon (name, attack1Name, attack2Name, attack3Name, element_ptr);
        return card_ptr;

        // return new Pokemon (name, attack1Name, attack2Name, attack3Name, element_ptr);
    }

    /*Initialize global list that will be used by all players*/
    void createPokemonList() {
        pokemonList.push_back(createPokemon("Geodude", "Tackle", "Fire Punch", "Earthquake", ElementType::COLORLESS));
        pokemonList.push_back(createPokemon("Mew", "Pound", "Psychic", "Aura Sphere", ElementType::PSYCHIC));
        pokemonList.push_back(createPokemon("Mewtwo", "Confusion", "Psychic", "Psystrike", ElementType::PSYCHIC));
        pokemonList.push_back(createPokemon("Gengar", "Shadow Punch", "Night Shade", "Shadow Ball", ElementType::PSYCHIC));
        pokemonList.push_back(createPokemon("Butterfree", "Gust", "Psybeam", "Psychic", ElementType::PSYCHIC));
        pokemonList.push_back(createPokemon("Pikachu", "Nuzzle", "Discharge", "Thunder", ElementType::LIGHTNING));
        pokemonList.push_back(createPokemon("Pichu", "Charge", "Thunder Shock", "Thunder Punch", ElementType::LIGHTNING));
        pokemonList.push_back(createPokemon("Charizard", "Tackle", "Rock Throw", "Landslide", ElementType::FIRE));
        pokemonList.push_back(createPokemon("Vulpix", "Ember", "Flamethrower", "Fire Blast", ElementType::FIRE));
        pokemonList.push_back(createPokemon("Jolteon", "Thunder Shock", "Pin Missile", "Thunder Fang", ElementType::LIGHTNING));
        pokemonList.push_back(createPokemon("Parichirisu", "Spake", "Electro Ball", "Discharge", ElementType::LIGHTNING));
        pokemonList.push_back(createPokemon("Chimchar", "Ember", "Fire Spin", "Flamethrower", ElementType::FIRE));
        pokemonList.push_back(createPokemon("Charmander", "Scratch", "Flamethrower", "Flare Blitz", ElementType::FIRE));
        pokemonList.push_back(createPokemon("Magmar", "Ember", "Flame Wheel", "Fire Blast", ElementType::FIRE));
        pokemonList.push_back(createPokemon("Bulbasaur", "Razor Leaf", "Seed Bomb", "Solar Beam", ElementType::GRASS));
        pokemonList.push_back(createPokemon("Alakazam", "Confusion", "Psybeam", "Psychic", ElementType::PSYCHIC));
        pokemonList.push_back(createPokemon("Staryu", "Water Gun", "Surf", "Brine", ElementType::WATER));
        pokemonList.push_back(createPokemon("Dragonite", "Water Gun", "Aqua Tail", "Dive", ElementType::WATER));
        pokemonList.push_back(createPokemon("Psyduck", "Water Gun", "Water Pulse", "Aqua Tail", ElementType::WATER));
        pokemonList.push_back(createPokemon("Arcanine", "Bite", "Fire Fang", "Reversal", ElementType::FIRE));
        pokemonList.push_back(createPokemon("Snorlax", "Flail", "Bite", "Giga Impact", ElementType::COLORLESS));
        pokemonList.push_back(createPokemon("Cresselia", "Confusion", "Psybeam", "Moonblast", ElementType::PSYCHIC));
        pokemonList.push_back(createPokemon("Darkrai", "Ominous Wind", "Quick Attack", "Dream Eater", ElementType::COLORLESS));
        pokemonList.push_back(createPokemon("Entei", "Ember", "Sacred Fire", "Fire Blast", ElementType::FIRE));
        pokemonList.push_back(createPokemon("Arceus", "Earth Power", "Extreme Speed", "Judgement", ElementType::COLORLESS));
        pokemonList.push_back(createPokemon("Lapras", "Surf", "Ice Beam", "Water Pulse", ElementType::COLORLESS));
        pokemonList.push_back(createPokemon("Suicune", "Water Gun", "Surf", "Blizzard", ElementType::WATER));
        pokemonList.push_back(createPokemon("Zapdos", "Peck", "Thunder Shock", "Zap Cannon", ElementType::LIGHTNING));
        pokemonList.push_back(createPokemon("Turtwig", "Tackle", "Razor Leaf", "Leaf Storm", ElementType::GRASS));
        pokemonList.push_back(createPokemon("Wobbuffet", "Tackle", "Counter", "Splash", ElementType::COLORLESS));
        pokemonList.push_back(createPokemon("Registeel", "Bulldoze", "Stomp", "Hyper Beam", ElementType::COLORLESS));
        pokemonList.push_back(createPokemon("Diglett", "Scratch", "Mud-Slap", "Earth Power", ElementType::GRASS));
        pokemonList.push_back(createPokemon("Squirtle", "Tackle", "Water Gun", "Aqua Tail", ElementType::WATER));
        pokemonList.push_back(createPokemon("Wartortle", "Water Gun", "Aqua Tail", "Whirlpool", ElementType::WATER));
        pokemonList.push_back(createPokemon("Blastoise", "Headbutt", "Aqua Tail", "Hydro Pump", ElementType::WATER));
        pokemonList.push_back(createPokemon("Eevee", "Tackle", "Swift", "Takedown", ElementType::COLORLESS));
        pokemonList.push_back(createPokemon("Scyther", "Quick Attack", "Double Hit", "X-Scissor", ElementType::GRASS));
        pokemonList.push_back(createPokemon("Gyrados", "Whirlpool", "Aqua Tail", "Hydropump", ElementType::WATER));
        pokemonList.push_back(createPokemon("Tauros", "Horn Attack", "Thrash", "Giga Impact", ElementType::COLORLESS));
        pokemonList.push_back(createPokemon("Dodrio", "Quick Attack", "Thrash", "Hyper Beam", ElementType::COLORLESS));
        pokemonList.push_back(createPokemon("Pidgeot", "Gust", "Wing Attack", "Air Slash", ElementType::COLORLESS));
        pokemonList.push_back(createPokemon("Rattata", "Tackle", "Super Fang", "Hyper Fang", ElementType::COLORLESS));
        pokemonList.push_back(createPokemon("Ninetales", "Ember", "Fire Blast", "Flamethrower", ElementType::FIRE));
        pokemonList.push_back(createPokemon("Machop", "Strength", "Double-edge", "Low Kick", ElementType::COLORLESS));
        pokemonList.push_back(createPokemon("Meowth", "Fury Swipes", "Scratch", "Fake Out", ElementType::COLORLESS));
        pokemonList.push_back(createPokemon("Golduck", "Aqua Jet", "Hydro Pump", "Aqua Tail", ElementType::WATER));
        pokemonList.push_back(createPokemon("Mankey", "Tackle", "Headbutt", "Thrash", ElementType::COLORLESS));
        pokemonList.push_back(createPokemon("Magicarp", "Splash", "Tackle", "Flail", ElementType::WATER));// make splash 0 since it's a useless move
        pokemonList.push_back(createPokemon("Zubat", "Astonish", "Air Slash", "Quick Attack", ElementType::COLORLESS));
        pokemonList.push_back(createPokemon("Jynx", "Lick", "Ice Punch", "Psychic", ElementType::PSYCHIC));
        pokemonList.push_back(createPokemon("Stunfisk", "Charge", "Discharge", "Spark", ElementType::LIGHTNING));
        pokemonList.push_back(createPokemon("Gastly", "Shadowball", "Smog", "Lick", ElementType::PSYCHIC));
        pokemonList.push_back(createPokemon("Omanyte", "Surf", "Water Gun", "Bubble", ElementType::WATER));
        pokemonList.push_back(createPokemon("Raikou", "Thunderbolt", "Thunder", "Shock", ElementType::LIGHTNING));
        pokemonList.push_back(createPokemon("Deino", "Headbutt", "Rock Throw", "Bite", ElementType::COLORLESS));
    }
};