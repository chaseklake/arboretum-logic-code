#include <iostream>
#include <string>
#include <vector>

#include "card.h"
#include "arboretum.h"
using namespace std;


bool Arboretum::add(Card c) {
    Position min(minX, minY);
    trees.insert(make_pair(min, c));
    return true;
}

bool Arboretum::add(Card handCard, string direction, Card targetCard) {
    map<Position, Card>::iterator it = locate(targetCard);
    if (it != trees.end()) {
        Position p;
        switch(direction[0]) {
            case 'a':
            p.x = it->first.x;
            p.y = it->first.y + 1;
            if (trees.find(p) == trees.end()) {
                trees.insert(make_pair(p, handCard));
                updateSize(p);
                return true;
            } else return false;
            break;

            case 'b':
            p.x = it->first.x;
            p.y = it->first.y - 1;
            if (trees.find(p) == trees.end()) {
                trees.insert(make_pair(p, handCard));
                updateSize(p);
                return true;
            } else return false;
            break;

            case 'l':
            p.x = it->first.x - 1;
            p.y = it->first.y;
            if (trees.find(p) == trees.end()) {
                trees.insert(make_pair(p, handCard));
                updateSize(p);
                return true;
            } else return false;
            break;

            case 'r':
            p.x = it->first.x + 1;
            p.y = it->first.y;
            if (trees.find(p) == trees.end()) {
                trees.insert(make_pair(p, handCard));
                updateSize(p);
                return true;
            } else return false;
            break;

            default:
            cout << "invalid direction, enter \'above\', \'below\', \'left\', or \'right\' \n";
            return false;
        }
    }
    return false;    
};

void Arboretum::updateSize(Position p) {
    if (p.x < minX) { minX = p.x; }
    else if (p.x > maxX) { maxX = p.x; }

    if (p.y < minY) { minY = p.y; }
    else if (p.y > maxY) { maxY = p.y; }
}

map<Position, Card>::iterator Arboretum::locate(Card c) {
    map<Position, Card>::iterator it = trees.begin();
    while (it != trees.end()) {
        if (it->second == c) {
            return it;
        }
    }
    return it;
}

/* Artifact from when I tried to make Arboretum a linked-list of Trees -- maps turned out to be easier to implement and faster to search (log(n) vs n^2)
int Arboretum::findNeighbors(Position p) {
    int neighbors = 0;
    Position top(p.x, p.y-1);
    Position bottom(p.x, p.y+1);
    Position left(p.x-1, p.y);
    Position right(p.x+1, p.y);

    if (trees.find(top) != trees.end()) { neighbors++; }
    if (trees.find(bottom) != trees.end()) { neighbors++; }
    if (trees.find(left) != trees.end()) { neighbors++; }
    if (trees.find(right) != trees.end()) { neighbors++; }

    // returns the number of neighbors (0-4)
    return neighbors; 
};
*/

void Arboretum::printArboretum() {
    map<Position, Card>::iterator it = trees.begin();
    while (it != trees.end()) {
        cout << it->first.x << ", " << it->first.y << " | " << it->second.getSpecies() << it->second.getNum() << endl;
        it++;
    }
}

int Arboretum::findPaths() {
    return 0;
}
