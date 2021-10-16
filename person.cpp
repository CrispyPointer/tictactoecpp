#include "person.h"
#include<iostream>
using namespace std;

person::person(int x, string y){
    if(x==1) mark = 'O';
    else mark = 'X';
    name = y;
}

void person::score_up(){
    score++;
 }

