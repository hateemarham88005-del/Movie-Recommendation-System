#include <iostream>
#include "RecommendationEngine.h"
using namespace std;

int main() {
    RecommendationEngine engine;
    int choice;
    string title, genre;
    float rating;
do {
    cout << "\n--- Movie Recommendation System ---\n";
    cout << "1. Add Movie\n";
    cout << "2. Search Movie\n";
    cout << "3. Show All Movies\n";
    cout << "4. Recommend by Genre\n";
    cout << "5. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter title: "; cin >> ws; getline(cin, title);
            cout << "Enter genre: "; getline(cin, genre);
            cout << "Enter rating: "; cin >> rating;
            engine.addMovie(Movie(title, genre, rating));
            break;
        case 2:
            cout << "Enter title to search: "; cin >> ws; getline(cin, title);
            {
                Movie* found = engine.searchMovie(title);
                if (found) found->display();
                else cout << "Movie not found!\n";
            }
            break;
        case 3:
            engine.displayAllMovies();
            break;
        case 4:
            cout << "Enter genre for recommendation: "; cin >> ws; getline(cin, genre);
            engine.recommendByGenre(genre);
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
    }
} while(choice != 5);
    
    return 0;
}
