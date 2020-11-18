/*
    This is the crux of the project - the arboretum each player has. I don't know how it works, but I will soon enough.
*/

#include <map>
#include <string>

#include "card.h"
using namespace std;

#ifndef ARBORETUM
#define ARBORETUM

struct Position {
    int x, y;

    Position() {};
    Position(int a, int b) {
        x = a, y = b;
    };

    //operator overload necessary for using Position as map key for Arboretum
    bool operator<(Position p) {
        return (x < p.x || y < p.y);
    }
};

/*
struct Tree {
    Card card;
    Tree* up = NULL;
    Tree* down = NULL;
    Tree* left = NULL;
    Tree* right = NULL;

    Tree(Card c) {
        card = c;
    };
};
*/

class Arboretum {
    map<Position, Card> trees;
    int minX = 0;
    int minY = 0;
    int maxX = 0;
    int maxY = 0;
    public:

    bool add(Card); // called when adding first card to arboretum
    bool add(Card, string, Card); // add(newCard, direction, targetCard), eg: add(c2, "left", b4); NOTE: need to add parsing of input -> card

    //int findNeighbors(Position); // no longer necessary
    map<Position, Card>::iterator locate(Card); // returns an iterator to Card, or trees.end() if Card isn't found
    void updateSize(Position); // keeps min and max X and Y up to date when adding new cards to arboretum

    void printArboretum(); // prints as a list of positions and card values

    int findPaths(); //TODO: implement DFS on a map??
};

#endif