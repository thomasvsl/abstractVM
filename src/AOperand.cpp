/*
** EPITECH PROJECT, 2024
** B-SYN-400-MAR-4-1-abstractVM-thomas.vidal-savelli
** File description:
** AOperand.cpp
*/

#include "../include/Factory.hpp"

template <typename T>
AOperand<T>::~AOperand() {}

template <typename T>
AOperand<T>::AOperand(T val, eOperandType t) : _value(val), _type(t) {}

template <typename T>
std::string AOperand<T>::toString() const {
    std::ostringstream ostring;
    ostring << _value;
    return ostring.str();
}

template <typename T>
eOperandType AOperand<T>::getType() const {
    return _type;
}

template <typename T>
IOperand *AOperand<T>::operator+(const IOperand &rhs) const {
    T rhsValue = static_cast<T>(std::stod(rhs.toString()));
    T result = rhsValue + this->_value;
    return Factory::createOperand(_type, std::to_string(result));
}

template <typename T>
IOperand *AOperand<T>::operator-(const IOperand &rhs) const {
    T rhsValue = static_cast<T>(std::stod(rhs.toString()));
    T result = rhsValue - this->_value;
    return Factory::createOperand(_type, std::to_string(result));
}

template <typename T>
IOperand *AOperand<T>::operator*(const IOperand &rhs) const {
    T rhsValue = static_cast<T>(std::stod(rhs.toString()));
    T result = rhsValue * this->_value;
    return Factory::createOperand(_type, std::to_string(result));
}

template <typename T>
IOperand *AOperand<T>::operator/(const IOperand &rhs) const {
    T rhsValue = static_cast<T>(std::stod(rhs.toString()));
    if (this->_value == 0)
        throw std::runtime_error("error: division by zero.");
    T result = rhsValue / this->_value;
    return Factory::createOperand(_type, std::to_string(result));
}

template <typename T>
IOperand *AOperand<T>::operator%(const IOperand &rhs) const {
    T rhsValue = static_cast<T>(std::stod(rhs.toString()));
    if (this->_value == 0) 
        throw std::runtime_error("error: modulo by zero.");
    T result = static_cast<int>(rhsValue) % static_cast<int>(this->_value);
    return Factory::createOperand(_type, std::to_string(result));
}

template class AOperand<int8_t>;
template class AOperand<int16_t>;
template class AOperand<int32_t>;
template class AOperand<float>;
template class AOperand<double>;
