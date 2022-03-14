#include <stdio.h>
#include "../include/parse_cpp.h"


int main(int argc, char *argv[]){
    struct ParseC *parse; 
    set_args(argc, argv);

    if(SelfParse)
        printf("Self Parse");

    return 0;
}
