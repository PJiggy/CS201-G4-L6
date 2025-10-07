#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void inputRatings(int ratings[][4], int users);
double averageMovieRating(const int ratings[][4], int users, int movieIndex);
void displayRatings(const int ratings[][4], int users);
void showResult(int rating);
void showResult(double avg);

int main() {
    const int users = 3, movies = 4;
    int ratings[users][movies];
    vector<int> highestRatings;

    inputRatings(ratings, users);
    displayRatings(ratings, users);

    double avg = averageMovieRating(ratings, users, 0);
    showResult(avg);

    for (int i = 0; i < users; i++) {
        int highest = ratings[i][0];
        for (int j = 1; j < movies; j++)
            if (ratings[i][j] > highest)
                highest = ratings[i][j];
        highestRatings.push_back(highest);
    }

    cout << "Highest ratings per user = [";
    for (size_t i = 0; i < highestRatings.size(); i++) {
        cout << highestRatings[i];
        if (i != highestRatings.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}

void inputRatings(int ratings[][4], int users) {
    for (int i = 0; i < users; i++) {
        cout << "User " << i + 1 << " ratings (4 movies, 1–5): ";
        for (int j = 0; j < 4; j++) {
            cin >> ratings[i][j];
            if (ratings[i][j] < 1 || ratings[i][j] > 5) {
                cout << "Invalid rating! Exiting...\n";
                exit(0);
            }
        }
    }
}

void displayRatings(const int ratings[][4], int users) {
    cout << "\nRatings table:\n";
    for (int i = 0; i < users; i++) {
        for (int j = 0; j < 4; j++)
            cout << ratings[i][j] << " ";
        cout << endl;
    }
}

double averageMovieRating(const int ratings[][4], int users, int movieIndex) {
    double sum = 0;
    for (int i = 0; i < users; i++)
        sum += ratings[i][movieIndex];
    return sum / users;
}

void showResult(int rating) {
    cout << "Rating = " << rating << endl;
}

void showResult(double avg) {
    cout << "Average rating for Movie 0 = " << avg << endl;
}
