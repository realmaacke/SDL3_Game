#pragma once

#include "Output/OutputCodes.hpp"
#include <string_view>
class Output{
public:
    static void error(OutputCode code);
    static void print(const std::string_view msg);
};