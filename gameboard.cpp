#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include "gameboard.hpp"

void tic_tac_toe::display_board()
{
    std::cout << tick[0] << " | " << tick[1] << " | " << tick[2] << std::endl;
    std::cout << "--|---|--" << std::endl;
    std::cout << tick[3] << " | " << tick[4] << " | " << tick[5] << std::endl;
    std::cout << "--|---|--" << std::endl;
    std::cout << tick[6] << " | " << tick[7] << " | " << tick[8] << std::endl;

    std::cout << std::endl;
}

void tic_tac_toe::user_input(int mark)
{
    tick[mark] = 'X';
}

void tic_tac_toe::computer()
{
    int x = time(0);
    srand(x);
    int square = 1 + rand() % 9;

    while(isalpha(tick[square]))
    {
        square = 1 + rand() % 9;
    }

    tick[square] = 'O';
    
}

bool tic_tac_toe::match_fin_check()
{
    bool completion = false;

    for(int i = 0; i < 9; i++)
    {
        int square_check = 0;

        if(isalpha(tick[i]))
        {
            square_check++;
        }
    }

    return completion;
}