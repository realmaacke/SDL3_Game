#include "Output/Output.hpp"
#include "Output/OutputCodes.hpp"
#include <iostream>

void Output::error(OutputCode code) {
    std::cout << "Error: " << code_to_msg(code) << std::endl;
}

void Output::print(const std::string_view msg) {
    std::cout << msg << std::endl;
}