#ifndef RECOMMENDATIONENGINE_H
#define RECOMMENDATIONENGINE_H

#include "HashTable.h"
#include <string>
#include <vector>

class RecommendationEngine {
private:
    HashTable movies;

public:
    void addMovie(const Movie &m);
    Movie* searchMovie(const std::string &title);           // Search by title
    void recommendByGenre(const std::string &genre);       // Recommend by genre
    void displayAllMovies();
};

#endif
