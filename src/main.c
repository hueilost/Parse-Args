#include <stdio.h>
#include "../include/parse_cpp.h"


int main(int argc, char *argv[]){
    set_args(argc, argv);

    if(SelfParse)
        printf("Self Parse");
    
    if(DefaultParse("default"))
        printf("Default Parse");

    return 0;
}
