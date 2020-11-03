/*
Arboretum Logic Program
Created by Chase Lake on November 1st, 2020

Disclaimer: I did not create and do not own Arboretum, the card game. 
  This is merely a fan project to program a working copy on android 
  10 to play for no profit on my phone. Arboretum is owned by Dan 
  Cassar and affiliates.

Purpose: This program is a prototype to implement a working logic for
  the card game Arboretum. The goal of this program is to create a 
  working simulation of the card game to use as a launching point for
  the actual simulation in Java for Android 10 devices.

*/

#include <iostream>
#include <stdlib.h> // srand, rand
#include <time.h> // time(NULL)

#include "deck.h"
#include "card.h"
#include "player.h"

using namespace std;

int main() {
  srand(time(NULL)); //Initialize randomizer

  Deck d;
  d.Generate();

  cout << "Deck:\n";
  d.PrintDeck();

  d.Shuffle();

  cout << "shuffled deck:\n";
  d.PrintDeck();

  Player p1;

  // stock the hand with the first 7 cards
  for (int i=0; i<7; i++) {
    p1.Draw(d);
  }

  while (true) {
    cout << "Hand: ";
    p1.printHand();
    cout << "Discard Pile: ";
    p1.printDiscard();

    int input;
    cout << "Draw a card: \n1. From the deck \n2. From your discard pile \n";
    cin >> input;

    switch(input) {
      case 1: p1.Draw(d);
      break;

      case 2: p1.Draw(p1.discardPile);
      break;

      default: cout << "invalid input\n";
    }
  }

}