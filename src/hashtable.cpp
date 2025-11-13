#include "HashTable.h"
#include <iostream>
using namespace std;
#include "HashTable.h"
#include <vector>
using namespace std;

vector<Movie> HashTable::getMoviesByGenre(string genre) {
    vector<Movie> results;

    for (int i = 0; i < SIZE; i++) {
        vector<Movie> bucketMovies = table[i].getAllMovies();
        for (Movie &m : bucketMovies) {
            if (m.genre == genre)
                results.push_back(m);
        }
    }
    return results;
}

HashTable::HashTable() {
    table = new LinkedList[SIZE];
}

int HashTable::hashFunction(string key) {
    int sum = 0;
    for (char c : key)
        sum += c;
    return sum % SIZE;
}

void HashTable::insert(Movie m) {
    int index = hashFunction(m.title);
    table[index].insert(m);
}

Movie* HashTable::search(string title) {
    int index = hashFunction(title);
    return table[index].search(title);
}

void HashTable::displayAll() {
    for (int i = 0; i < SIZE; i++) {
        cout << "Bucket " << i << ":\n";
        table[i].displayAll();
    }
}
