/*
** EPITECH PROJECT, 2024
** B-SYN-400-MAR-4-1-abstractVM-thomas.vidal-savelli
** File description:
** Parser.cpp
*/

#include "../include/VM.hpp"

Parser::~Parser() {}

Parser::Parser() {}

int Parser::parseFile(const std::string &filename) {
    VM vm;
    std::ifstream file(filename);
    std::string line;
    std::regex regex("(\\w+)\\s*(\\w*)\\s*\\((-?[\\d.]+)\\)?|^(\\w+)$");
    std::smatch match;

    if (!file.is_open()) {
        throw std::runtime_error("Error: unable to open file: " + filename + ".");
    }
    while (std::getline(file, line)) {
        if (std::regex_search(line, match, regex)) {
            // add command
            _commands.push_back(match[1].matched ? match[1] : match[4]);
            // add operand if present
            if (match[2].matched) {
                _operands.push_back(match[2]);
            }
            // add value if present
            if (match[3].matched) {
                _values.push_back(match[3]);
            }
        }
    }
    file.close();
    try {
        vm.run(*this);
    } catch (const std::exception &e) {
        throw std::runtime_error(e.what());
    }
    return 0;
}
