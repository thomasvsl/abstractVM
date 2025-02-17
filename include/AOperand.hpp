/*
** EPITECH PROJECT, 2024
** B-SYN-400-MAR-4-1-abstractVM-thomas.vidal-savelli
** File description:
** AOperand.hpp
*/

#ifndef AOPERAND_HPP
    #define AOPERAND_HPP

#include "IOperand.hpp"
#include <string>
#include <sstream>

template <typename T>
class AOperand : public IOperand {
    public:
        ~AOperand();
        AOperand(T val, eOperandType t);
        std::string toString() const override;
        eOperandType getType() const override;
        IOperand* operator+(const IOperand& rhs) const override;
        IOperand* operator-(const IOperand& rhs) const override;
        IOperand* operator*(const IOperand& rhs) const override;
        IOperand* operator/(const IOperand& rhs) const override;
        IOperand* operator%(const IOperand& rhs) const override;
        T _value;
        eOperandType _type;
};

#endif //AOPERAND_HPP
