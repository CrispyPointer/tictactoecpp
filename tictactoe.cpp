#include "person.h"
#include "game.h"
#include <iostream>
#include <unistd.h>

using namespace std;
void clear();

int main(){

string ans;
    while(true)
    {
        cout<<"\t---WELCOME TO MY TIC TAC TOE GAME!---"<<endl;
        cout<<"\nInstruction:\n\t Type in 2 number to coordinate your move"<<endl;
        cout<<"\n\tFor example: [Player] 'X' Location: 1 2 (row 1 colum 2)"<<endl;
        cout<<"\n\tENJOY YOUR GAME!!!\n\n";
        game();
        cout<<"Do you want to start a new game? (Y/N)"<<endl;
        cin>>ans;
        if (ans != "Y"){
            cout<<"Thank you for playing!! GOODBYE";
            usleep(2000000);
            break;
        }
        clear();
    }
    return 0;
}
void clear()
{
    int n;
    for (n = 0; n < 10; n++)
        printf( "\n\n\n\n\n\n\n\n\n\n" );
}