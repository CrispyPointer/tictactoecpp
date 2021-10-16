#ifndef PERSON_H
#define PERSON_H
#include <string>

class person{
public:
            person(int x, std::string y);
            std::string get_name(){return name;}
            char get_mark(){return mark;}
            int get_score(){return score;}
            void score_up();
private:
            int pn;
            int score = 0;
            std::string name;
            char mark;
};

#endif