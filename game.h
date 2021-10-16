#ifndef GAME_H
#define GAME_H
#include "person.h"
#include <string>
#include <vector>

class game{
public:
            game();
            void board();
            void clear_screen();
            void clear_board();
            void move(int x, int y, std::string mark);
            bool check_win(std::string mark, bool game_over);
            bool check_move(int x, int y, bool bad_move);    
            bool check_score(int score1, int score2);
            bool check_restart(std::string s, bool restart);
            bool check_escape(bool escape);
private:
            std::vector<std::string> V1 = {" "," "," "};
            std::vector<std::string> V2 = {" "," "," "};
            std::vector<std::string> V3 = {" "," "," "};
            person* player1 = NULL;
            person* player2 = NULL;   
};
#endif