#pragma once
#include <optional>
#include <string>
#include <vector>

struct ActionOperations {
    std::string operation;
    std::optional<std::string> key;
    std::optional<std::string> target;
};

class ActionLoader {
public:
    ActionLoader();
    void init_file(const std::string& file);
    std::vector<ActionOperations> retriveActions();

private:
    std::vector<ActionOperations> bind_ops;
};