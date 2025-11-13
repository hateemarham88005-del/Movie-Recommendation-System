#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <vector>
#include <string>


class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    void insert(Movie m);
    Movie* search(string title);
    void displayAll();
    std::vector<Movie> getAllMovies();  // Returns all movies in this list

};

#endif
