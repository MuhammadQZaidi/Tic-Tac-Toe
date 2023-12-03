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


    game.user_input(1);
    game.display_board();
    game.computer();
    game.display_board(); 
    game.computer();
    game.display_board(); 
    game.computer();
    game.display_board(); 

    
    
   
    
}