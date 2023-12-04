#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include "gameboard.hpp"
#include "gameboard.cpp"


int main()
{
    tic_tac_toe game;
    int matches;

    std::cout << "Welcome to Tic-Tac-Toe, user vs computer edition" << std::endl;
    std::cout << "You will be the 'X' and the computer will be the 'O'" << std::endl;
    std::cout << "You will go first.To mark the board, enter the number of the square you would like to play" << std::endl;
    std::cout << std::endl;
    game.display_board();
    std::cout << std::endl;

    std::cout << "How many matches would you like to play? Input an integer 1-10 and hit ENTER: ";
    std::cin >> matches;
    
    while(std::cin.fail() || matches > 10 || matches < 1)
    {
        std::cin.clear();
        std::cin.ignore(80, '\n');
        std::cout << "invalid input. Please input an integer 1-10: ";
        std::cin >> matches;
    }

    for(int i = 1; i <= matches; i++)
    {
        std::cout << "match " << i << std::endl;
        std::cout << std::endl;
        game.display_board();
        int turns = 0;
        
        while(game.winner_check() == 3 && turns < 9)
        {
            game.user_input();
            turns++;
            std::cout << "Your Play: " << std::endl;
            game.display_board();
            if(game.winner_check() == 3 && turns < 9)
            {
                game.computer();
                turns++;
                game.display_board();
            }
            
            
        }

        
        if(game.winner_check() == 1)
        {
            std::cout << "congrats! you won this match :)" << std::endl;
            game.record_score(1);
        }
        else if(game.winner_check() == -1)
        {
            std::cout << "aw, computer won this match :(" << std::endl;
            game.record_score(-1);
        } 
        else if(turns == 9)
        {
            std::cout << "this match has ended in a tie" << std::endl;
        }   
        
        game.reset_board();
    }

    std::cout << std::endl;
    std::cout << "The game has conclude" << std::endl;
    game.display_score(matches);

    
    
    

    
    
   return 0;
    
}