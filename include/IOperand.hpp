/*
** EPITECH PROJECT, 2024
** B-SYN-400-MAR-4-1-abstractVM-thomas.vidal-savelli
** File description:
** IOperand.hpp
*/

#ifndef IOPERAND_HPP
    #define IOPERAND_HPP

#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <csignal>
#include <regex>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <map>
#include <memory>
#include <stack>

enum eOperandType {
    Int8,
    Int16,
    Int32,
    Float,
    Double
};

class IOperand {
    public:
        virtual ~IOperand() = default;
        virtual std::string toString() const = 0;
        virtual eOperandType getType() const = 0;
        virtual IOperand *operator+(const IOperand &rhs) const = 0;
        virtual IOperand *operator-(const IOperand &rhs) const = 0;
        virtual IOperand *operator*(const IOperand &rhs) const = 0;
        virtual IOperand *operator/(const IOperand &rhs) const = 0;
        virtual IOperand *operator%(const IOperand &rhs) const = 0;
};

#endif //IOPERAND_HPP
