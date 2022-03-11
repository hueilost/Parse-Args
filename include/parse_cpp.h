#ifndef PARSE_CPP_H
#define PARSE_CPP_H

#include <iostream>

class ParseCpp{
    int argc;
    char *argv[];
public:
    ParseCpp(int argc, char *argv[]) : argc(argc){
        argv = this->argv;
    };
    /**
     * @brief  Checks for the word after the program call.
     * @note   
     * @param  word: std::string that gets turned into a c string.
     * @retval bool
     */
    bool DefaultParse(std::string word){
        word.c_str();
        if(argc == 2 && argv[1] == word)
            return true;
        else return false;
    }
};

/*bool argCheck(const char* word="", int argc={NULL}, char* argv[]=nullptr, int arguments = 2, int argvParameter = 1){
    if ( (argc == arguments) && _stricmp( argv[argvParameter], word) == 0)
        return true;
    else return false;
}*/


#endif