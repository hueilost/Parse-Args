#ifndef PARSE_ARGS_H
#define PARSE_ARGS_H

#define PARSE_ARGS_VERSION "1.0"
#define MAJOR_VERSION "1"
#define MINOR_VERSION "0"

#ifdef __cplusplus

#include <iostream>
#include <string.h>
#include <array>
#include <iterator>
#include <vector>

class ParseArgs {
    int argc;
    char **argv;
    std::vector<std::string> arguments;
    std::vector<std::string> description;
public:
    /**
     * @brief Parse Cpp constructor, takes argc and argv.  
     * @note   
     * @param  argc: main argc
     * @param  *argv[]: main argv
     */
    ParseArgs(int argc, char *argv[]){
        this->argc = argc;
        this->argv = argv;
    };

    // Parse's current program.
    bool ParseSelf(){
        if (argc == 1)
            return true;
        else return false;
    };

    /**
     * @brief  Checks for the word after the program call.
     * @param  word: const char* - word to check for.
     * @retval bool
     */
    bool DefaultParse(const char* word){
        if ( (argc == 2) && _stricmp( argv[1], word) == 0)
            return true;
        else return false;
    }
    /**
     * @brief  Checks for the word after the program call.
     * @param  word: T - word to check for.
     * @retval bool
     */
    template<class T>
    bool DefaultParse(T word){
        word.c_str();
        if ( argc == 2 &&  argv[1] == word)
            return true;
        else return false;
    }
    /**
     * @brief  Parse, takes word and position of word.
     * @note   
     * @param  word: 
     * @param  position: 
     * @retval 
     */
    template<class T>
    bool Parse(T word, uint8_t position){
        uint8_t argPos = position + 1;
        if ( argc == argPos &&  argv[position] == word)
            return true;
        else return false;
    };

    /**
     * @brief  Parse word at set position.
     * @note   
     * @param  word: 
     * @param  position: 
     * @retval 
     */
    bool Parse(const char* word, uint8_t position){
        uint8_t argPos = position + 1;
        if ( (argc == argPos) && _stricmp( argv[position], word) == 0)
            return true;
        else return false;
    };

    bool ParseDouble(const char* word, uint8_t position, const char* secondary_word, uint8_t secondary_position){
        bool word1, word2;
        uint8_t argPos1 = position + 1;
        if ( (argc >= argPos1) && _stricmp( argv[position], word) == 0)
            word1 = true;
        else word1 = false;

        uint8_t argPos2 = secondary_position + 1;
        if ( (argc >= argPos2) && _stricmp( argv[secondary_position], secondary_word) == 0)
            word2 = true;
        else word2 = false;

        if (word1 == true && word2 == true){
            return true;
        } else return false;

    };
    /**
     * @brief  Parsing Double arguments.
     * @note   
     * @param  word: word to check for
     * @param  position: position of the word starting from 1 after program name
     * @param  secondary_word: second word
     * @param  secondary_position: second position
     * @retval 
     */
    template<class T>
    bool ParseDouble(T word, uint8_t position, T secondary_word, uint8_t secondary_position){
        bool word1, word2;
        uint8_t argPos1 = position + 1;
        if ( argc >= argPos1 && argv[position] == word)  
            word1 = true;
        else word1 = false;

        uint8_t argPos2 = secondary_position + 1;
        if ( argc >= argPos2 && argv[secondary_position] == secondary_word)
            word2 = true;
        else word2 = false;

        if (word1 == true && word2 == true){
            return true;
        } else return false; int8_t signed_integer;
    };
    //todo: add a way to parse all the values in an array.
    bool ParseMultiple();

    //warning: terminate called after throwing an instance of 'std::logic_error' what():  basic_string::_M_construct null not valid
    bool IfNotWords(const std::vector<std::string> words){
        std::string value = argv[1];
        if ( std::find(words.begin(), words.end(), value) != words.end()){
            return true;
        } else return false;
    }

    void add_argument(const char* command, const char* desc){
        arguments.push_back(command);
        description.push_back(desc);

        if(DefaultParse(command)){
            for(uint8_t i = 0; i < arguments.size(); ++i){
                std::cout << "usage: " << arguments[i] << std::endl;
            }
            for(uint8_t i = 0; i < description.size(); ++i){
                std::cout << "options: \n" << 
                arguments[i] << " " << description[i] << std::endl;
            }
        }
    }
    template<class T>
    void add_argument(T command, T description){
        if(DefaultParse(command)){

        }
    }

    // import argparse
    // parser = argparse.ArgumentParser()
    // parser.add_argument('--foo', help='foo help')
    // args = parser.parse_args()
};
#endif

#ifndef __cplusplus
#include <stdbool.h>
#include <string.h>

typedef struct parse_c {
    int argc;
    char **argv;
} parse;
parse p;

void set_args(int argc, char **argv){
    p.argc = argc;
    p.argv = argv;
};

bool SelfParse() {
    if (p.argc == 1)
        return true;
    else return false;
}

bool DefaultParse(const char* word) {
    if ( (p.argc >= 2) && _stricmp( p.argv[1], word) == 0)
            return true;
        else return false;
}
#endif

#endif