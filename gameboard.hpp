#ifndef gameboard_HPP
#define gameboard_HPP

class tic_tac_toe
{
    private:
        //our actual grid, each quadrant is numbered
        char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        //variable to hold the number of user wins
        int user_wins = 0;
        //variable to hold the number of computer wins
        int computer_wins = 0;
    
    public:
        //function to display the game grid
        void display_board();
        //function to record the user's move and mark it on the board
        void user_input();
        //function for the computer to play its move and mark it on the board
        void computer();
        //function to check for either a user win or a computer win
        int winner_check();
        //function to record each win
        void record_score(int);
        //function to display the endgame states
        void display_score(int);
        //function to reset the board back to its original state after each round has concluded
        void reset_board();

};


#endif