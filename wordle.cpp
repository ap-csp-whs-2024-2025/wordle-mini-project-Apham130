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
    for (int counter = 1; counter < 5; counter = counter + 1)
    {
        if (secret[couter] == guess[counter])
        {
            append(hint, O)
        } else
        {
            append(hint, X)
        } 
    }

    return {bool1, bool2, bool3, bool4};  
}

bool winGame(std::vector<int> secret, std::vector<int> guess) 
{

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
    std::cout << "Welcome to Number Wordle!\n";
    
    while (!winGame(secret_code, user_guess))   
    {
        std::cout << "\nGuess #" << num_guesses << ": ";
        hint = {};
        for (int counter = 0; counter < secret_code_length; counter = counter + 1)
        {
            int input;
            std::cin >> input;
            user_guess.push_back(input);   
        }

        hint = getHint(secret_code, user_guess);
        display(hint);
        num_guesses = num_guesses + 1;
    }

    // std::cout << "Congrats!  You guessed the code!  It took you " << num_guesses << " tries.\n";
    return 0;
}
