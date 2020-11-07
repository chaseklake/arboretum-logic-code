/*
    This is the crux of the project - the arboretum each player has. It's a kind of 2D linked list using DFS to determine paths.
*/

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
};

struct Tree {
    Position pos;
    Tree* right;
    Tree* left;

    Tree(Tree* r, Tree* l, Position p) {
        pos = p;
        right = r;
        left = l;
    };
};

class Arboretum {
    Tree* head;
    Position min;
    Position max;

    public:
    bool addTree(Card, Position) {}; //TODO
    Tree* findTree(Position) {}; //TODO
    int findPaths() {}; //TODO
};

#endif