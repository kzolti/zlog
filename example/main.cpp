#include <iostream>
#include "../src/log.h"
using namespace std;

int main()
{
    ___success("Program started.");
    for (int i = 0; i < 10; i++){
        ___info("Processing iteration %d.");
        if (i == 5){
            ___warning("An issue occurred on iteration %d.");
        }
        if (i == 7){
            ___error("An error occurred on iteration %d.");
        }
        ___debug("Debug information for iteration %d.");
    }
    ___debug("ddddddddddddddddddddddddddddd");
    ___fatal("Program terminated abnormally.");
    return 0;
}
