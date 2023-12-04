#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include "gameboard.hpp"

void tic_tac_toe::display_board()
{
    std::cout << board[0] << " | " << board[1] << " | " << board[2] << std::endl;
    std::cout << "--|---|--" << std::endl;
    std::cout << board[3] << " | " << board[4] << " | " << board[5] << std::endl;
    std::cout << "--|---|--" << std::endl;
    std::cout << board[6] << " | " << board[7] << " | " << board[8] << std::endl;

    std::cout << std::endl;
}

void tic_tac_toe::user_input()
{
    //variable to the position the user would like to mark
    int mark;
    std::cout << "Your Move: ";
    std::cin >> mark;

    //input validation to make sure the user enters an INTEGER 1-9
    while(std::cin.fail() || mark < 1 || mark > 9)
    {
        std::cin.clear();
        std::cin.ignore(80, '\n');
        std::cout << "invalid input. Please input the number of the quadrant you would like to mark: ";
        std::cin >> mark;
    }

    //input validation to make sure the user doesnt try to mark a quadrant that has already been played
    while(isalpha(board[mark-1])) //'-1' is needed to make sure we dont pick up the null character
    {
        std::cin.clear();
        std::cin.ignore(80, '\n');
        std::cout << "This space is already taken. Please input a different quadrant: ";
        std::cin >> mark;
    }

    //'-1' is here bc we display index 0 as 1 in our game board. If we displayed index 0 as 0 ',-1' would not be needed.
    board[mark-1] = 'X';
}

void tic_tac_toe::computer()
{
    //random number generator
    int x = time(0);
    srand(x);
    //this specifies that a random integer 1-9 will be generated
    int square = 1 + rand() % 9;

    //while loop that will kick in if the quadrant that is equal to the number generated has already been played
    while(isalpha(board[square-1])) // '-1' needed here to account for the nulll character
    {
        //another number will keep being generated until we get one that is equal to a free quadrant
        square = 1 + rand() % 9;
    }

    // '-1' is here bc we display index 0 as 1 in our game board. If we displayed index 0 as 0 ',-1' would not be needed.
    board[square-1] = 'O';
    
}

int tic_tac_toe::winner_check()
{
    //return value that is always defaulted to 3
    int winner = 3;
    
    //if statement that scans for a user win
    if((board[0] == 'X' && board[1] == 'X' && board[2] == 'X') || (board[0] == 'X' && board[3] == 'X' && board[6] == 'X') || (board[0] == 'X' && board[4] == 'X' && board[8] == 'X') ||
       (board[3] == 'X' && board[4] == 'X' && board[5] == 'X') || (board[1] == 'X' && board[4] == 'X' && board[7] == 'X') || (board[2] == 'X' && board[4] == 'X' && board[6] == 'X') ||
       (board[6] == 'X' && board[7] == 'X' && board[8] == 'X') || (board[2] == 'X' && board[5] == 'X' && board[8] == 'X') 
       )
    {
        //if the user wins, 'winner' is set to 1
        winner = 1;
    }

    //if that scans for a computer win
    if((board[0] == 'O' && board[1] == 'O' && board[2] == 'O') || (board[0] == 'O' && board[3] == 'O' && board[6] == 'O') || (board[0] == 'O' && board[4] == 'O' && board[8] == 'O') ||
       (board[3] == 'O' && board[4] == 'O' && board[5] == 'O') || (board[1] == 'O' && board[4] == 'O' && board[7] == 'O') || (board[2] == 'O' && board[4] == 'O' && board[6] == 'O') ||
       (board[6] == 'O' && board[7] == 'O' && board[8] == 'O') || (board[2] == 'O' && board[5] == 'O' && board[8] == 'O') 
       )
    {
        //if the computer wins, 'winner' is set to -1
        winner = -1;
    }

    //if a win is not detected, this function will return 3
    return winner;
}

void tic_tac_toe::record_score(int winner)
{
    
    //if 'winner' = 1 then a win for the user is recorded
    if(winner == 1)
    {
        user_wins++;
    }

    //if 'winner' = -1 then a win for the computer is recorded
    else if(winner == -1)
    {
        computer_wins++;
    }
}   

void tic_tac_toe::display_score(int matches)
{
    //'matches' variable will always be equal to the number of rounds the user wants to play

    std::cout << std::endl;
    //output for endgame stats of the user
    std::cout << "You won " << user_wins << " out of " << matches << " matches" << std::endl;
    //output for endgame states of the computer
    std::cout << "The computer won " << computer_wins << " out of " << matches << " matches" << std::endl;
    //output of the number of ties
    std::cout << "There were " << matches - (user_wins + computer_wins) << " ties" << std::endl;
    std::cout << "Thank you for playing!" << std::endl;
    std::cout << std::endl;

}

void tic_tac_toe::reset_board()
{
    for(int i = 0; i < 9; i++)
    {
        board[i] = '1' + i;
    }

}
