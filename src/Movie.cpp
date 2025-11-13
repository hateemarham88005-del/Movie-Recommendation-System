#include "Movie.h"
#include <iostream>
using namespace std;

void Movie::display() const {
    cout << "Title: " << title << ", Genre: " << genre << ", Rating: " << rating << endl;
}
