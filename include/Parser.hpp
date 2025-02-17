/*
** EPITECH PROJECT, 2024
** B-SYN-400-MAR-4-1-abstractVM-thomas.vidal-savelli
** File description:
** Parser.hpp
*/

#ifndef PARSER_HPP
    #define PARSER_HPP

#include "IOperand.hpp"

class Parser {
    public:
        ~Parser();
        Parser();
        int parseFile(const std::string &filename);
        std::vector<std::string> _commands;
        std::vector<std::string> _operands;
        std::vector<std::string> _values;
        int _error = 0;
};

#endif //PARSER_HPP
