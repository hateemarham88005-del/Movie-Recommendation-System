import streamlit as st
import pandas as pd

# Load dataset
movies = pd.read_csv('movies_google.txt', names=['title','genre','rating'])

# Function to recommend movies by genre
def recommend_by_genre(genre, top_n):
    filtered = movies[movies['genre'].str.lower() == genre.lower()]
    return filtered.sort_values(by='rating', ascending=False).head(top_n)

# Streamlit GUI
st.title("Movie Recommendation System")

user_genre = st.text_input("Enter your favorite movie genre:")
top_n = st.slider("How many recommendations do you want?", 1, 20, 5)

if st.button("Get Recommendations"):
    if user_genre:
        recommendations = recommend_by_genre(user_genre, top_n)
        if not recommendations.empty:
            st.write(recommendations[['title','rating']])
        else:
            st.write("No movies found for this genre.")
    else:
        st.write("Please enter a genre.")
