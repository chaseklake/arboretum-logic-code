#include <deque>
#include <algorithm> // shuffle
#include <random> // default_random_engine
#include <stdlib.h> // rand
#include <time.h> // time(NULL)
#include <string>
#include <iostream>

#include "deck.h"
using namespace std;

void Deck::Generate() {
    for (int s=0; s<SPECIES; s++) {
        for (int n=1; n<=NUMBERS; n++) {
            //for now let the species be 'a', 'b', 'c', ..., for logic tests
            string letter;
            letter = static_cast<char>(97+s);
            Card newCard = Card(letter, n);
            cards.push_back(newCard);
        }
    }
}

void Deck::Shuffle() {
    shuffle(cards.begin(), cards.end(), default_random_engine(time(NULL)));
}

void Deck::PrintDeck() {
    deque<Card>::iterator i;
    for (i = cards.begin(); i != cards.end(); i++) {
        (*i).printCard();
        cout << " ";
    }
    cout << endl;
}