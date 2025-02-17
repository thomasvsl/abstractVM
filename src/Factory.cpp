/*
** EPITECH PROJECT, 2024
** B-SYN-400-MAR-4-1-abstractVM-thomas.vidal-savelli
** File description:
** Factory.cpp
*/

#include "../include/Factory.hpp"

Factory::~Factory() {}

Factory::Factory() {}

IOperand* Factory::createOperand(eOperandType type, const std::string &value) {
    switch (type) {
        case Int8:
            return Factory::createInt8(value);
        case Int16:
            return Factory::createInt16(value);
        case Int32:
            return Factory::createInt32(value);
        case Float:
            return Factory::createFloat(value);
        case Double:
            return Factory::createDouble(value);
        default:
            return nullptr;
    }
}

IOperand* Factory::createInt8(const std::string &value) {
    return new AOperand<int8_t>(std::stoi(value), Int8);
}

IOperand* Factory::createInt16(const std::string &value) {
    return new AOperand<int16_t>(std::stoi(value), Int16);
}

IOperand* Factory::createInt32(const std::string &value) {
    return new AOperand<int32_t>(std::stoi(value), Int32);
}

IOperand* Factory::createFloat(const std::string &value) {
    return new AOperand<float>(std::stof(value), Float);
}

IOperand* Factory::createDouble(const std::string &value) {
    return new AOperand<double>(std::stod(value), Double);
}
