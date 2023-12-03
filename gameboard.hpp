#ifndef gameboard_HPP
#define gameboard_HPP

class tic_tac_toe
{
    private:
        char tick[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    public:
        void display_board();
        void user_input(int);
        void computer();
        bool match_fin_check();
        bool winner_check();

};


#endif