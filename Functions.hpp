#include <ctime>
#include <stdlib.h>

bool coinFlip() { //true if heads, false if tails
    srand((unsigned) time(0));
    int result = rand()%1; //returns 0 or 1 randomly
    if (result == 1)
        cout << "The coin toss resulted in Heads\n";
    else
        cout << "The coin toss resulted in Tails\n";
    
    return result;
}


Pokemon createPokemon(string name, string attack1Name, string attack2Name, string attack3Name, ElementType elementType) {
    Element* element_ptr;

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

    return Pokemon (name, attack1Name, attack2Name, attack3Name, element_ptr);
}
