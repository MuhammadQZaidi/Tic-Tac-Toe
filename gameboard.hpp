#ifndef gameboard_HPP
#define gameboard_HPP

class tic_tac_toe
{
    private:
        char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        int user_wins = 0;
        int computer_wins = 0;
    
    public:
        void display_board();
        void user_input();
        void computer();
        int winner_check();
        void record_score(int);
        void display_score(int);
        void reset_board();

};


#endif