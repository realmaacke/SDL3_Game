#pragma once
#include <string_view>


enum class OutputCode {
    DEFAULT_BIND_MISSING,
    BIND_FILE_MISSING,
    FILE_ACCESS_ERROR,
    BIND_KEY_INVALID,
};

struct OutputEntry {
    OutputCode type;
    std::string_view msg;
};

constexpr OutputEntry output_codes[] = {
{
    .type = OutputCode::DEFAULT_BIND_MISSING,
    .msg = "Could not find default binds (keybinds.binds missing)"
},
{
    .type = OutputCode::BIND_FILE_MISSING,
    .msg = "Could not locate provided binds file"
},
{
    .type = OutputCode::FILE_ACCESS_ERROR,
    .msg = "Could not open file"
},
{
    .type = OutputCode::BIND_KEY_INVALID,
    .msg = "Bind file contains invalid key"
},
};

constexpr std::string_view code_to_msg(OutputCode code) {
    for (const OutputEntry& entry : output_codes) {
        if (entry.type == code) return entry.msg;
    }
    return "Internal error.";
}