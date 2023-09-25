/*************************
*Your name Joel Miller
*CPSC 2310 002, Sp23
*Your email jmill53@clemson.edu
*************************/
#include "ppm_utils.h"



int main(int argc, char* argv[]) {

    assert(argc == 3 && "Must follow format! \
            ./main <average or median> <out.ppm>");

    start(argv[1], argv[2]);

    return 0;
}





