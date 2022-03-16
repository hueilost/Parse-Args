/** 
 * * ParseArgs - Maou Shimazu || Eldad Danladi
 * 
 * * This project is based on python's argparse. If you feel like there is
 * * a feature from argparse that should be implimented, feel free to 
 * * create an issue on github.
 * 
 * * This is the demo program on how to use parse_args.h.
 * * parse_args consists of raw parsing functions and abstracted functions
 * * all shown down below.
 * 
 * * It is being nicely documented and can be used by
 * * Documentation Generators such as Doxygen. All documented code is
 * * attached to their functions for vscode/vs (and other editors) support.
 * 
 * * The functions in here were compiled with c++17 as the standard.
 * * If there are any bugs or errors, please check your compiler first.
 * * If problems still persist, feel free to create an issue at 
 * * https://github.com/Maou-Shimazu/Parse-Args/issues/
 * 
 * * note: C implimentation is not currently available, please do not try
 * * to use it unless you know what you are doing.
 */

#include <iostream>
#include <fmt/core.h>
#include <src/format.cc>

// If you dont have fmt installed globally, please use this and remove the one above.
#ifndef FMT_CORE_H_
#include "../include/fmt/core.h"
#include "../include/src/format.cc"
#endif

#include "../include/parse_args.h"

int main(int argc, char *argv[]){
	// Class ParseArgs has no default constructor, and must be initialized in one of the two below ways. Because its the only way to aquire values from argc and argv. All functions, so far, have support for both . (dot) and -> (arrow) notation.
	ParseArgs *parse_ptr = new ParseArgs(argc, argv);
	ParseArgs parse = ParseArgs(argc, argv);

	// Parse Args contiains raw functions that return bools which you can use to define your own options. todo: give add_argument() overload option for user defined functions.
	if(parse_ptr->DefaultParse("pointer"))
		fmt::print("Pointer");

	// Parse Args also contains less abstracted functions that parse and have output redily made for you.
	parse.add_argument("ptr", "just good ol ptr");
	
	if(parse.DefaultParse("nonp"))
		fmt::print("Non Pointer");

	std::string str = "string";
	if(parse_ptr->DefaultParse(str))
		fmt::print("String Overload");
	
	if(parse_ptr->Parse("parse", 2))
		fmt::print("Parsing at position 2 after program call.");
	
	std::string parsing_place = "parse-string";
	if(parse_ptr->Parse(parsing_place, 2))
		fmt::print("Parseing at position 2 with strings.");

	if(parse_ptr->ParseSelf())
		fmt::print("Self Parsing.");

	if(parse_ptr->ParseDouble("parsing", 1, "double", 2))
		fmt::print("Parsing double arguments.");

	std::string doub = "double", parsin = "parsing";
	if(parse_ptr->ParseDouble(doub, 1, parsin, 2))
		fmt::print("Parsing double string arguments.");

	// std::vector<std::string> words {"double, pointer, nonp, string, parse"};
	// if(parse_ptr->IfNotWords(words))
	// 	fmt::print("Not a keyword. Please use pcpp help for commands.");

	return 0;
}
