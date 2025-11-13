import pandas as pd

# -----------------------------
# Step 1: Load dataset
# -----------------------------
movies = pd.read_csv('movies_google.txt', names=['title', 'genre', 'rating'])

# -----------------------------
# Step 2: Define the recommendation function
# -----------------------------
def recommend_by_genre(genre_name, top_n=10):
    """
    Recommend top N movies in a given genre.
    """
    # Filter movies by genre (case-insensitive)
    genre_movies = movies[movies['genre'].str.lower() == genre_name.lower()]
    
    # Sort by rating descending
    top_movies = genre_movies.sort_values(by='rating', ascending=False)
    
    # Return top N movies
    return top_movies[['title', 'rating']].head(top_n)

# -----------------------------
# Step 3: Interactive part
# -----------------------------
user_genre = input("Enter your favorite movie genre: ")
top_n = int(input("How many recommendations do you want? "))

recommendations = recommend_by_genre(user_genre, top_n)

if recommendations.empty:
    print(f"Sorry! No movies found for genre '{user_genre}'.")
else:
    print(f"\nTop {top_n} movies in genre '{user_genre}':")
    print(recommendations)
