#include <vector>
#include <iostream>
#include "player.h"
#include "card.h"
#include "deck.h"

using namespace std;

void Player::Draw(Deck& d) {
    // Make sure you can draw from the deck
    if (d.cards.empty()) {
        cout << "That deck is empty!\n";
        return;
    }

    // Add the card to the hand
    hand.push_back(d.cards.front());

    // Take the card out of the deck
    d.cards.pop_front();
}

void Player::Discard(Card c) {
    // add the card to the discard pile
    discardPile.cards.push_front(c);

    // find the card and erase it from the hand
    vector<Card>::iterator i;
    for (i = hand.begin(); i != hand.end(); i++) {
        if (*i == c) {
            hand.erase(i);
        }
    }
}

void Player::printHand() {
    vector<Card>::iterator i;
    for (i = hand.begin(); i != hand.end(); i++) {
        (*i).printCard();
        cout << " ";
    }
    cout << endl;
}

void Player::printDiscard() {
    discardPile.PrintDeck();
}

Card Player::getCard(int i) {
    return hand[i];
}