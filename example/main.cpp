#include <iostream>
#include "../src/log.h"
using namespace std;

int main()
{
    ___success<<"Program started :"<<16;
    for (int i = 0; i < 10; i++){
        ___info<<"Processing iteration "<<i;
        if (i == 5){
            ___warning<<"An issue occurred on iteration " <<i<<".";
        }
        if (i == 7){
            ___error<<"An error occurred on iteration "<<i<<".";
        }
        ___debug<<"Debug information for iteration "<<i<<".";
    }
    ___debug<<"ddddddddddddddddddddddddddddd";
    ___fatal<<"Program terminated abnormally.";
    return 0;
}
