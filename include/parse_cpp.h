#ifndef PARSE_CPP_H
#define PARSE_CPP_H

#ifdef __cplusplus

#include <iostream>
#include <string.h>
#include <array>

class ParseCpp {
    int argc;
    char **argv;
public:
    /**
     * @brief Parse Cpp constructor, takes argc and argv.  
     * @note   
     * @param  argc: main argc
     * @param  *argv[]: main argv
     */
    ParseCpp(int argc, char *argv[]){
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
     * @brief  
     * @note   
     * @param  word: 
     * @param  position: 
     * @param  secondary_word: 
     * @param  secondary_position: 
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

    //note: parse multiple implimentation needed to complete this function. 
    // bool IfNotWords(uint8_t position, std::string words[], uint8_t len){
    //     bool t;
    //     for (uint16_t i = 0; i <= len; ++i){
    //         if ( argv[position] != words[i]){
    //             t = true;
    //         } else t = false;
    //     }
    //     return t;
    // };
};
#endif

//#ifndef __cplusplus
#include <stdbool.h>
#include <string.h>

typedef struct ParseC {
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
//#endif

#endif