#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void displayWord(const string& word, const vector<bool>& guessed) 
{
    for (size_t i = 0; i < word.size(); ++i) 
    {
        if (guessed[i]) 
        {
            cout << word[i] << " ";
        } else 
        {
            cout << "_ ";
        }
    }
    cout << endl;
}

bool isWordGuessed(const vector<bool>& guessed) 
{
    for (bool letterGuessed : guessed) 
    {
        if (!letterGuessed) 
        {
            return false;
        }
    }
    return true;
}

int main() 
{
    vector<string> words = {"programming", "hangman", "computer", "game", "developer"};
    srand(static_cast<unsigned>(time(0)));
    string word = words[rand() % words.size()];

    vector<bool> guessed(word.size(), false);
    int attempts = 6;

    cout << "Welcome to Hangman!" << endl;

    while (attempts > 0) 
    {
        cout << "\nAttempts left: " << attempts << endl;
        displayWord(word, guessed);

        cout << "Guess a letter: ";
        char guess;
        cin >> guess;

        bool correctGuess = false;
        for (size_t i = 0; i < word.size(); ++i) 
        {
            if (word[i] == guess && !guessed[i]) 
            {
                guessed[i] = true;
                correctGuess = true;
            }
        }

        if (!correctGuess) 
        {
            --attempts;
            cout << "Wrong guess!" << endl;
        }

        if (isWordGuessed(guessed)) 
        {
            cout << "\nCongratulations! You guessed the word: " << word << endl;
            return 0;
        }
    }

    cout << "\nGame over! The word was: " << word << endl;
    return 0;
}
