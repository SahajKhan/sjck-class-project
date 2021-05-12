#pragma once
#include <map>
#include <string>
/* Enumerations and string maps for Element Types */
enum class ElementType { PSYCHIC, COLORLESS, FIRE, GRASS, WATER, LIGHTNING };

const std::map<ElementType, std::string> elementTypeNames = {
	{ElementType::PSYCHIC, "PSYCHIC"},
	{ElementType::COLORLESS,"COLORLESS"},
	{ElementType::FIRE,"FIRE"},
	{ElementType::GRASS,"GRASS"},
	{ElementType::WATER,"WATER"},
	{ElementType::LIGHTNING,"LIGHTNING"},
};

enum class CardType {POKEMON, TRAINER, ENERGY};

enum class Evolution {LEVEL1 =1, LEVEL2, LEVEL3};