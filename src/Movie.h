#ifndef MOVIE_H
#define MOVIE_H
#include <string>
using namespace std;

class Movie {
public:
    string title;
    string genre;
    float rating;

    Movie() {}
    Movie(string t, string g, float r) {
        title = t;
        genre = g;
        rating = r;
    }

    void display() const;
};
#endif
