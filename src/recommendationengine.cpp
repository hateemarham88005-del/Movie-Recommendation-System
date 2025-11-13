#include "RecommendationEngine.h"
#include <iostream>
using namespace std;

void RecommendationEngine::addMovie(const Movie &m) {
    movies.insert(m);
}

Movie* RecommendationEngine::searchMovie(const string &title) {
    return movies.search(title);
}

void RecommendationEngine::displayAllMovies() {
    movies.displayAll();
}

void RecommendationEngine::recommendByGenre(const string &genre) {
    vector<Movie> recommended = movies.getMoviesByGenre(genre);

    if (recommended.empty()) {
        cout << "No movies found in genre: " << genre << endl;
        return;
    }

    cout << "Recommended movies in genre \"" << genre << "\":" << endl;
    for (Movie &m : recommended) {
        m.display();
    }
}
