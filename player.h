#include <vector>

#include "card.h"
#include "deck.h"
using namespace std;

#ifndef PLAYER
#define PLAYER

class Player {
private:
    vector<Card> hand;

public:
    Deck discardPile;
    //Arboretum arboretum;

    Player() {};

    void Draw(Deck& d);
    //void Play(position?);
    void Discard(Card c);

    void printHand();
    void printDiscard();
    Card getCard(int i);
    int getHandSize() { return hand.size(); }
};

#endif