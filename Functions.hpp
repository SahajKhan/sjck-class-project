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
