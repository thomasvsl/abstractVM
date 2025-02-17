/*
** EPITECH PROJECT, 2024
** B-SYN-400-MAR-4-1-abstractVM-thomas.vidal-savelli
** File description:
** VM.cpp
*/

#include "../include/VM.hpp"

VM::~VM() {}

VM::VM() {}

eOperandType VM::stringToOperandType(const std::string& typeStr) {
    static const std::map<std::string, eOperandType> typeMap = {
        {"int8", Int8},
        {"int16", Int16},
        {"int32", Int32},
        {"float", Float},
        {"double", Double}
    };

    auto it = typeMap.find(typeStr);
    if (it != typeMap.end()) {
        return it->second;
    } else {
        throw std::runtime_error("error: invalid operand type.");
    }
}

int VM::run(Parser &parser) {
    std::stack<IOperand*> _opStack;

    if (parser._commands.empty()) {
        std::cerr << "Error: no commands found." << std::endl;
        return 84;
    }
    for (_line = 0; _line < parser._commands.size(); _line++) {
        try {
            if (parser._commands[_line] == "push")
                push(parser, _opStack);
            else if (parser._commands[_line] == "pop")
                pop(_opStack);
            else if (parser._commands[_line] == "clear")
                clear(_opStack);
            else if (parser._commands[_line] == "dup")
                dup(_opStack);
            else if (parser._commands[_line] == "swap")
                swap(_opStack);
            else if (parser._commands[_line] == "dump")
                dump(_opStack);
            else if (parser._commands[_line] == "assert")
                assert(parser, _opStack);
            else if (parser._commands[_line] == "add")
                add(_opStack);
            else if (parser._commands[_line] == "sub")
                sub(_opStack);
            else if (parser._commands[_line] == "mul")
                mul(_opStack);
            else if (parser._commands[_line] == "div")
                div(_opStack);
            else if (parser._commands[_line] == "mod")
                mod(_opStack);
            else if (parser._commands[_line] == "load")
                load(_opStack);
            else if (parser._commands[_line] == "store")
                store(_opStack);
            else if (parser._commands[_line] == "print")
                print(_opStack);
            else if (parser._commands[_line] == "exit")
                return 0;
            else
                throw std::runtime_error("error: invalid command.");
        } catch (const std::exception &e) {
            throw std::runtime_error("Line " + std::to_string(_line + 1) + ": " + e.what());
        }
    }
    return 0;
}