/*
** EPITECH PROJECT, 2024
** B-SYN-400-MAR-4-1-abstractVM-thomas.vidal-savelli
** File description:
** Factory.hpp
*/

#ifndef FACTORY_HPP
    #define FACTORY_HPP

#include "AOperand.hpp"

class Factory {
    public:
        ~Factory();
        Factory();
        static IOperand *createOperand(eOperandType type, const std::string &value);
        static IOperand *createInt8(const std::string &value);
        static IOperand *createInt16(const std::string &value);
        static IOperand *createInt32(const std::string &value);
        static IOperand *createFloat(const std::string &value);
        static IOperand *createDouble(const std::string &value);
};

#endif //FACTORY_HPP
