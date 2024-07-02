#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(nullptr)));

    // Generate a random number between 1 and 100
    int targetNumber = rand() % 100 + 1;
    int playerGuess = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 100. Can you guess it?" << endl;

    while (true) {
        cout << "Please enter your guess: ";
        cin >> playerGuess;

        if (playerGuess > targetNumber) {
            cout << "Oops! Your guess is too high. Try again." << endl;
        } else if (playerGuess < targetNumber) {
            cout << "Oops! Your guess is too low. Try again." << endl;
        } else {
            cout << "Hooray! You've guessed the correct number!" << endl;
            break;
        }
    }

    return 0;
}
