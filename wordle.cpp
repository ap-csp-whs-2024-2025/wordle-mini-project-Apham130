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

std::vector<int> createSecret(int diff) 
{
    if (diff == 0)
    {
        return {rand() % 10, rand() % 10, rand() % 10, rand() % 10};   
    } else if (diff == 1)
    {
        return {rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 10};   
    } else if (diff == 2)
    {
        return {rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 10};
    } else if (diff == 3)
    {
        return {rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 10 , rand() % 10, rand() % 10};
    }
    return {404};
}

std::vector<std::string> getHint(std::vector<int> secret, std::vector<int> guess, int diff) // code, guess, length of code
{   
    std::vector<std::string> hint = {};
    std::vector<int> tempSecret = secret; 
    std::vector<int> tempGuess = guess;
    hint.assign(diff, "X");
    for (int counter = 0; counter < diff; counter = counter + 1)
    {
        if (secret[counter] == guess[counter])
        {
            hint[counter] = "O";
            remove(tempSecret, counter);
            tempGuess[counter] = 999;
        }
    }
    // tempSecret gives a number
    // if tempGuess has the number from tempSecret, replace index of hint with + and move on
    for (int index = 0; index < length(tempSecret); index = index + 1)
    {
        int currEx = tempSecret[index];
        for (int counter = 0; counter < diff; counter = counter + 1)
        { 
            if (currEx == tempGuess[counter])
            {
                hint[counter] = "+";
                tempGuess[counter] = 999;
                counter = 999;
            }
        }
    }
    display(hint);
    // std::vector<std::string> hint = {};
    // for (int counter = 0; counter < diff; counter = counter + 1)
    // {
    //     if (secret[counter] == guess[counter])
    //     {
    //         hint.push_back("O");
    //     } else
    //     {
    //         hint.push_back("X");
    //     } 
    // }

    return hint;  
}

bool endGame(std::vector<std::string> guess, int codeSize, int preNumG, int numG) 
{
    int numCorrect = 0;
    for (int counter = 0; counter < length(guess); counter = counter + 1)
    {
        if (guess[counter] == "O")
        {
            numCorrect = numCorrect + 1;
        }
    } 
    if (numCorrect == codeSize)
    {
        return true;
    }
    if (numG == preNumG)
    {
        return true;
    }
    return false;
}

bool wonGame (std::vector<std::string> guess, int size)
{
    
    int numCorrect = 0;
    for (int counter = 0; counter < length(guess); counter = counter + 1)
    {
        if (guess[counter] == "O")
        {
            numCorrect = numCorrect + 1;
        }
    } 
    if (numCorrect == size)
    {
        return true;
    }
    return false;
}

int main()
{
    srand(time(0));
    
    std::vector<std::string> hint = {};  
    int secret_code_length = 4;

    
    std::cout << "Welcome to Number Wordle!\nGuess a large number one digit at a time!\n";

    std::cout << "\nWhat difficulty would you like your game to be?\n(easy = 0, medium = 1, hard = 2, masochist = 3): ";
    
    int difficulty;
    std::cin >> difficulty;
    
    if (difficulty == 0)
    {
        secret_code_length = 4;
        std::cout << "\nHow many guesses would you like? (Recommended 10): ";
    } else if (difficulty == 1)
    {
        secret_code_length = 6;
        std::cout << "\nHow many guesses would you like? (Recommended 20): ";
    } else if (difficulty == 2)
    {
        secret_code_length = 8;
        std::cout << "\nHow many guesses would you like? (Recommended 30): ";
    } else if (difficulty == 3)
    {
        secret_code_length = 10;
        std::cout << "\nHow many guesses would you like? (Recommended 40): ";
    }
    
    int num_guesses_set;
    std::cin >> num_guesses_set;
    std::vector<int> secret_code = createSecret(difficulty);
    display(secret_code);
    int num_guesses = 0;

    int user_guess;
    std::vector<int> user_guess_list = {};
    user_guess_list.assign(secret_code_length, 0);

    std::cout << "\nPlease enter numbers in a " << secret_code_length << " digit number form.";
    while (!endGame(hint, secret_code_length, num_guesses_set, num_guesses))   
    {
        num_guesses = num_guesses + 1;
        std::cout << "\nGuess #" << num_guesses << ": ";
        hint = {};
        
        // new input method

        std::cin >> user_guess;
        int index = secret_code_length - 1;
        while (user_guess > 0)
        {
            int digit = user_guess % 10;
            user_guess_list[index] = digit;
            // std::cout << user_guess;
            // display(user_guess_list);
            user_guess = user_guess / 10;
            index = index - 1;
        }

        // old input method
        
        // for (int counter = 0; counter < secret_code_length; counter = counter + 1)  
        // {
        //     int input;
        //     std::cin >> input;
        //     user_guess.push_back(input);   
        // }
    
        hint = getHint(secret_code, user_guess_list, secret_code_length);
        display(hint);

        // display(secret_code);
        // std::cout << user_guess << std::endl;
        // display(user_guess_list);
    }

    bool won = wonGame(hint, secret_code_length);
    if (won == true && num_guesses == 1)
    {
        std::cout << "\nCheater\n";
    } else if (won == true && num_guesses > 1)
    {   
        std::cout << "\nCongrats!  You guessed the code!  It took you " << num_guesses << " tries.\n";
    } else if (won == false)
    {
        std::cout << "\nSorry, you lost!\n";
    }
   
    return 0;
}
