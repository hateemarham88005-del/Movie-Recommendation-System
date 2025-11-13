#ifndef NODE_H
#define NODE_H
#include "Movie.h"

class Node {
public:
    Movie data;
    Node* next;

    Node(Movie m) {
        data = m;
        next = nullptr;
    }
};
#endif
