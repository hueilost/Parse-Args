#include <iostream>
#include <tuple>
#include <array>
#include <fmt/core.h>
#include <src/format.cc>

int main(int argc, char** argv){

    auto tuple = std::make_tuple(1, 'a', 2.3);
    std::array<int, 3> a{1, 2, 3};

    // unpack the tuple into individual variables declared above
    const auto[i, c, d] = tuple;
    // same with an array
    auto[x,y,z] = a; 

}