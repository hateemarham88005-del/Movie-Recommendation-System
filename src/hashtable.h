#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <vector>
#include <string>
#include "LinkedList.h"
#define SIZE 10 // can be increased for large datasets

class HashTable {
private:
    LinkedList* table;

    int hashFunction(string key);

public:
    HashTable();
    void insert(Movie m);
    Movie* search(string title);
    std::vector<Movie> getMoviesByGenre(std::string genre);
    void displayAll();
};
#endif
