/**
* listhelpers.hpp has been provided by the instructor as starter code
* contains the following procedures to work with lists:
* display, append, insert, remove, length
*/
#include "listhelpers.hpp"

#include <cstdlib>   // srand, rand
#include <ctime>     // time
#include <iostream>  // std::cin, std::cout
#include <string>    // std::string, std::getline
#include <vector>    // std::vector

std::vector<int> createSecret() 
{
    return {rand() % 10, rand() % 10, rand() % 10, rand() % 10};   
}

std::vector<std::string> getHint(std::vector<int> secret, std::vector<int> guess) 
{   
    std::vector<std::string> hint = {};
    for (int counter = 0; counter < 4; counter = counter + 1)
    {
        if (secret[counter] == guess[counter])
        {
            hint.push_back("O");
        } else
        {
            hint.push_back("X");
        } 
    }

    return hint;  
}

bool winGame(std::vector<std::string> guess) 
{
    int numCorrect = 0;
    for (int counter = 0; counter < length(guess); counter = counter + 1)
    {
        if (guess[counter] == "O");
        {
            numCorrect = numCorrect + 1;
        }
    } 
    if (numCorrect == 4)
    {
        return true;
    }
    return false;
}

int main()
{
    srand(time(0));
    
    std::vector<int> secret_code = createSecret();
    std::vector<int> user_guess = {};
    std::vector<std::string> hint = {};   

    int secret_code_length = 4;
    int num_guesses = 0;

    display(secret_code);
    std::cout << "Welcome to Number Wordle!\nGuess the 4 digit number one digit at a time!\n";
    
    while (!winGame(hint))   
    {
        num_guesses = num_guesses + 1;
        std::cout << "\nGuess #" << num_guesses << ": ";
        hint = {};
        user_guess = {};
        for (int counter = 0; counter < secret_code_length; counter = counter + 1)
        {
            int input;
            std::cin >> input;
            user_guess.push_back(input);   
        }
        hint = getHint(secret_code, user_guess);
        display(hint);
        // display(secret_code);
        // display(user_guess);
    }

    std::cout << "Congrats!  You guessed the code!  It took you " << num_guesses << " tries.\n";
    return 0;
}
