#include "game.h"
#include <iostream>
using namespace std;

game::game(){
    string n1, n2, mark, ans;
    int score1, score2;
    bool letter = true;
    bool game_over = false;
    bool bad_move = false;
    bool restart = false;
    bool escape = false;
    int x{},y{};
    cout<<"Name of player one: ";
    getline(cin,n1);
    cout<<"Name of player two: ";
    getline(cin,n2);
    player1 = new person(1,n1);
    player2 = new person(2,n2);

    do{
        clear_screen();
        clear_board();
        if (escape == true) break;
        if (score1 == 3){
                board();
                cout<<"Congratulation "<<player1->get_name()<<" you have won !!!"<<endl;
                break;
        }
        if (score2 == 3){
                board();
                cout<<"Congratulation "<<player2->get_name()<<" you have won !!!"<<endl;
                break;
        }
        cout<<"Current score: "<<player1->get_name()<<" : "<<player2->get_name()<<" -- [ "<<player1->get_score()<<" : "<<player2->get_score()<<" ]\n"<<endl;
        for(size_t i =1;i<=9;i++){
            board();
            if(i%2!=0)
            {
                do
                {
                    cout<<player1->get_name()<<"--'"<<player1->get_mark()<<"' Location:   ";
                        do{
                            cin>>x;
                            if(cin.fail()){
                                cout<<"Please enter a valid move: ";
                                cin.clear();
                                cin.ignore();
                                }
                            else break;
                            }while(1);
                    do{
                            cin>>y;
                            if(cin.fail()){
                                cout<<"Please enter a valid move: ";
                                cin.clear();
                                cin.ignore();
                                }
                            else break;
                            }while(1);
                    mark = player1->get_mark();
                    if (check_move(x,y,bad_move)==true) cout<<"Invalid move!! Please enter another move."<<endl;
                }while(check_move(x,y,bad_move)==true);

                move(x,y,mark);
                clear_screen();
                board();
                if (check_win(mark, game_over) == true){
                    cout << player1->get_name() << " has won this round !!!"<<endl;
                    player1->score_up();
                    score1 = player1->get_score();
                    cout << "Do you want to continue? (Y/N) ";
                    cin>>ans;
                    if (check_restart(ans, restart)==true) break;
                    else{
                        cout<<"Do you want to escape? (Y/N)"<<endl;
                        cin>>ans;
                        if(ans=="Y"){
                            escape = check_escape(true);
                            break;
                        }
                    }
                }
                clear_screen(); 
            }
            else
            {
                do{
                    cout<<player2->get_name()<<"--'"<<player2->get_mark()<<"' Location:   ";
                    do{
                            cin>>x;
                            if(cin.fail()){
                                cout<<"Please enter a valid move:  ";
                                cin.clear();
                                cin.ignore();
                                }
                            else break;
                            }while(1);
                    do{
                            cin>>y;
                            if(cin.fail()){
                                cout<<"Please enter a valid move: ";
                                cin.clear();
                                cin.ignore();
                                }
                            else break;
                            }while(1);
                    mark = player2->get_mark();
                    if (check_move(x,y,bad_move)==true) cout<<"Invalid move!! Please enter another move."<<endl;
                }while(check_move(x,y,bad_move)==true);

                move(x,y,mark);
                clear_screen();
                board();
                if (check_win(mark, game_over) == true){
                    cout << player2->get_name() << " has won this round !!!"<<endl;
                    player2->score_up();
                    score2 = player2->get_score();
                    cout << "\nDo you want to continue? (Y/N)";
                    cin>>ans;
                    if (check_restart(ans, restart)==true) break;
                    else{
                        cout<<"Do you want to escape? (Y/N)"<<endl;
                        cin>>ans;
                        if(ans=="Y"){
                            escape = check_escape(true);
                            break;
                        } 
                    }
                }
                clear_screen();
            }

            if (i==9) {
                board();
                cout << "It's a draw!!!"<<endl;
                cout << "Do you want to continue? (Y/N)";
                cin>>ans;
                if (check_restart(ans, restart)==true) break;
            }
        }
        }while(restart==false);
    delete player1;
    delete player2;
}

void game::clear_board(){
    for(size_t i =0;i<3;i++)
    {
        V1[i]=" ";
        V2[i]=" ";
        V3[i]=" ";
    }
}

void game::board(){
    cout<<"\t1\t\t2\t\t3"<< endl;
    cout<<"\t\t|\t\t|\t\t"<<endl;
    cout << "1      "<<V1[0]<<"\t|"<<"\t"<<V1[1]<<"\t|\t"<<V1[2]<<endl;
    cout<<"----------------|---------------|-------------"<<endl;
    cout<<"\t\t|\t\t|\t\t"<<endl;
    cout << "2      "<<V2[0]<<"\t|"<<"\t"<<V2[1]<<"\t|\t"<<V2[2]<<endl;
    cout<<"----------------|---------------|-------------"<<endl;
    cout<<"\t\t|\t\t|\t\t"<<endl;
    cout << "3      "<<V3[0]<<"\t|"<<"\t"<<V3[1]<<"\t|\t"<<V3[2]<<endl;
    cout<<"----------------|---------------|-------------"<<endl;
}

void game::clear_screen(){
    int n;
    for (n = 0; n < 10; n++)
    printf( "\n\n\n\n\n\n\n\n\n\n" );
}

void game::move(int x, int y, string mark){
    if(x == 1)
        {
            if        (y==1)                V1[0] = mark;
            else if (y==2)                V1[1] = mark;
            else if (y==3)                V1[2] = mark;
        }

    else if(x == 2)
        {
            if        (y==1)                V2[0] = mark;
            else if (y==2)                V2[1] = mark;
            else if (y==3)                V2[2] = mark;
        }

    else if(x == 3)
        {
            if        (y==1)                V3[0] = mark;
            else if (y==2)                V3[1] = mark;
            else if (y==3)                V3[2] = mark;
        }
}

bool game::check_win (string mark, bool game_over){
    if                      (((V1[0]==V1[1])&&(V1[1]==V1[2]))&&(V1[0]!=" ")) game_over = true;
    else if               (((V2[0]==V2[1])&&(V2[1]==V2[2]))&&(V2[0]!=" ")) game_over = true;
    else if               (((V3[0]==V3[1])&&(V3[1]==V3[2]))&&(V3[0]!=" ")) game_over = true;
    else if               (((V1[0]==V2[0])&&(V2[0]==V3[0]))&&(V1[0]!=" ")) game_over = true;
    else if               (((V1[1]==V2[1])&&(V2[1]==V3[1]))&&(V1[1]!=" ")) game_over = true;
    else if               (((V1[2]==V2[2])&&(V2[2]==V3[2]))&&(V2[2]!=" ")) game_over = true;
    else if               (((V1[0]==V2[1])&&(V2[1]==V3[2]))&&(V3[2]!=" ")) game_over = true;
    else if               (((V1[2]==V2[1])&&(V2[1]==V3[0]))&&(V1[2]!=" ")) game_over = true;

    return game_over;
}

bool game::check_move(int x,int y, bool bad_move){
    if (((!(x>=1&&x<=3)))&&((!(y>=1&&y<=3)))) bad_move = true; // check for x and y in range (1,3)

    //Check for already marked coordinates.
    else if (x==1){
        if (V1[y-1]!=" ") bad_move = true;                                                      
    }
    else if (x==2){
        if (V2[y-1]!=" ") bad_move = true;
    }
    else if (x==3){
        if (V3[y-1]!=" ") bad_move = true;
    }
    return bad_move;
}

bool game::check_score(int score1, int score2){
    if(score1 == 3)             return true;
    else if (score2 == 3)     return true;
    else                               return false;
}

bool game::check_restart(string s, bool restart){
    if (s=="Y") restart = true;
    else if (s=="N") restart = false;
    else restart = false;
    return restart; 
}

bool game::check_escape(bool escape){
    return escape;
}