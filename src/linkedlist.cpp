#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
}

void LinkedList::insert(Movie m) {
    Node* newNode = new Node(m);
    newNode->next = head;
    head = newNode;
}

Movie* LinkedList::search(string title) {
    Node* temp = head;
    while (temp) {
        if (temp->data.title == title)
            return &temp->data;
        temp = temp->next;
    }
    return nullptr;
}

void LinkedList::displayAll() {
    Node* temp = head;
    while (temp) {
        temp->data.display();
        temp = temp->next;
    }
}

std::vector<Movie> LinkedList::getAllMovies() {
    std::vector<Movie> movies;
    Node* temp = head;
    while (temp) {
        movies.push_back(temp->data);
        temp = temp->next;
    }
    return movies;
}
