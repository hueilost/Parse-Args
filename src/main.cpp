#include <iostream>
#include <fmt/core.h>
#include <src/format.cc>

#include "../include/parse_cpp.h"

int main(int argc, char *argv[]){
	ParseCpp *parse_ptr = new ParseCpp(argc, argv);
	ParseCpp parse_nonptr = ParseCpp(argc, argv);

	if(parse_ptr->DefaultParse("pointer"))
		fmt::print("Pointer");
	
	if(parse_nonptr.DefaultParse("nonp"))
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

	return 0;
}