#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void inputRatings(int ratings [][4], int users);

double averageMovieRating(const int ratings [][4], int users, int movieIndex);

void displayRatings(const int ratings [][4], int users){
    //put a nested for loop here
    //iterate thru users and then their rating array relative
    //ppt 7 page 15
    for (int i = 1; i< users; i++){
        cout << "User " << i << " ratings: " << ratings [i][4] << endl;
    }
}


void showResult(int rating){
    cout << rating;
}

void showResult(double avg);




int main(){
    int movieRating;
    const int ROWS = 3, COLS = 4;
    //Store ratings from 3 users for 4 movies into a 2D array.
    //Then move to appropriate function
    int ratings [ROWS][COLS] = {};

    //Iterate through users
    for (int i = 0; i < ROWS; i++){

        cout << setw(5) << "User " << i+1 << endl;
        cout << "--------------\n" << endl;

        for(int j = 0; j < COLS; j++){
            
            cout << "Movie " << j+1 << " rating: ";
            cin >> movieRating;

            ratings[i][j] = movieRating;

            if (movieRating < 1 || movieRating > 5) {
                exit(0);
            }

        }
    }

    for (int i = 0; i < ROWS; i++){
         cout << "User " << i+1 << endl;

        for(int j = 0; j < COLS; j++){
            cout << "Movie " << j+1 << ": ";
            cout << ratings[i][j] << endl;

        }
    }
    // end of program
    return 0;
}