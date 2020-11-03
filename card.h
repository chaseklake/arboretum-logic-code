#include <string>
#include <iostream>
using namespace std;

#ifndef CARD
#define CARD

class Card {
private:
    //Species is the type of tree the card represents
    string species;
    //Num is for path finding and getting right-to-count a species
    int num;
public:
    //Constructors
    Card() {};
    Card(string s, int n) {
        species = s;
        num = n;
    };

    bool operator==(Card c) {
        if (species == c.getSpecies() && num == c.getNum()) {
            return true;
        } else {
            return false;
        }
    }

    //Accessor functions;
    string getSpecies() { return species; }
    int getNum() { return num; }
    void printCard() {
        cout << species << num;
    };
};

#endif