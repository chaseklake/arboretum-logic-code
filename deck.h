/*
    The deck from which cards are generated and drawn.
*/

#include <deque>
#include "card.h"
using namespace std;

#ifndef DECK
#define DECK

class Deck {
private:
    // 6 species for 2 players, numbered 1-8 => 6*8 = 48 cards
    const int SPECIES = 6;
    const int NUMBERS = 8;

public:
    deque<Card> cards;

    Deck() {};

    void Generate();
    void Shuffle();
    void PrintDeck();
};

#endif