import pandas as pd
import ast

# -----------------------------
# Step 1: Load CSV files
# -----------------------------
movies = pd.read_csv('movies_metadata.csv', low_memory=False)
ratings = pd.read_csv('ratings.csv')

# -----------------------------
# Step 2: Prepare movies DataFrame
# -----------------------------

# If 'id' column doesn't exist, create a unique movieId
movies['movieId'] = movies.index  # unique ID for each movie

# Keep only relevant columns
movies = movies[['movieId', 'title', 'genres']]

# -----------------------------
# Step 3: Extract first genre
# -----------------------------
def first_genre(genres_str):
    try:
        genres_list = ast.literal_eval(genres_str)
        if genres_list:
            return genres_list[0]['name']
    except:
        return ''
    return ''

movies['genre'] = movies['genres'].apply(first_genre)
movies = movies[['movieId', 'title', 'genre']]

# -----------------------------
# Step 4: Prepare ratings DataFrame
# -----------------------------
# Your ratings.csv has 'movieId' and 'rating' columns
ratings = ratings[['movieId', 'rating']]

# Compute average rating per movie
avg_ratings = ratings.groupby('movieId')['rating'].mean().reset_index()

# -----------------------------
# Step 5: Merge movies with ratings
# -----------------------------
merged = movies.merge(avg_ratings, on='movieId', how='inner')

# Keep only title, genre, rating
merged = merged[['title', 'genre', 'rating']]

# -----------------------------
# Step 6: Save to txt
# -----------------------------
merged.to_csv('movies_google.txt', index=False, header=False)

print("Done! 'movies_google.txt' has been created in the same folder.")
