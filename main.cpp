#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include "gameboard.hpp"
#include "gameboard.cpp"


int main()
{
    //creation of object for tic-tac-toe
    tic_tac_toe game;
    //variable to keep track of the number of rounds the user wants to play
    int round;

    //Intro message and instructions for the user
    std::cout << "Welcome to Tic-Tac-Toe, user vs computer edition" << std::endl;
    std::cout << "You will be the 'X' and the computer will be the 'O'" << std::endl;
    std::cout << "You will go first.To mark the board, enter the number of the square you would like to play" << std::endl;
    std::cout << std::endl;
    game.display_board();
    std::cout << std::endl;

    std::cout << "How many rounds would you like to play? Input an integer 1-10 and hit ENTER: ";
    std::cin >> round;
    
    //input validation to make sure the user enters an INTEGER 1-10 
    while(std::cin.fail() || round > 10 || round < 1)
    {
        std::cin.clear();
        std::cin.ignore(80, '\n');
        std::cout << "invalid input. Please input an integer 1-10: ";
        std::cin >> round;
    }

    //for loop that runs as many rounds as the user wants to play
    for(int i = 1; i <= round; i++)
    {
        //displays the current round aswell as a fresh board
        std::cout << "round " << i << std::endl;
        std::cout << std::endl;
        game.display_board();
        int turns = 0;
        
        //while loop that will conclude once a player has won, or there has been a tie
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

        
        //message displayed if the user wins
        if(game.winner_check() == 1)
        {
            std::cout << "congrats! you won this match :)" << std::endl;
            //function to record win in the scoreboard
            game.record_score(1);
        }
        //messsage displayed if the computer wins
        else if(game.winner_check() == -1)
        {
            std::cout << "aw, computer won this match :(" << std::endl;
            //function to record win in the scoreboard
            game.record_score(-1);
        } 
        //message displayed if the game ends in a tie
        else if(turns == 9)
        {
            std::cout << "this match has ended in a tie" << std::endl;
        }   
        
        //function to reset the game board so the next round can be played
        game.reset_board();
    }

    
    std::cout << std::endl;
    std::cout << "The game has conclude" << std::endl;
    //function to display game stats
    game.display_score(round);

    

    
   return 0;
    
}