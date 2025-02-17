/*
** EPITECH PROJECT, 2024
** B-SYN-400-MAR-4-1-abstractVM-thomas.vidal-savelli
** File description:
** commands.cpp
*/

#include "../include/VM.hpp"

void VM::push(Parser &parser, std::stack<IOperand*> &_opStack) {
    _type = stringToOperandType(parser._operands[_val]);
    _op = Factory::createOperand(_type, parser._values[_val]);
    _opStack.push(_op);
    _val++;
}

void VM::pop(std::stack<IOperand*> &_opStack) {
    if (_opStack.empty())
        throw std::runtime_error("error: pop on an empty stack.");
    else
        _opStack.pop();
}

void VM::clear(std::stack<IOperand*> &_opStack) {
    if (_opStack.empty())
        throw std::runtime_error("error: clear on an empty stack.");
    else {
        while (!_opStack.empty()) {
            _opStack.pop();
        }
    }
}

void VM::dup(std::stack<IOperand*> &_opStack) {
    if (_opStack.empty())
        throw std::runtime_error("error: dup on an empty stack.");
    else {
        IOperand* temp = _opStack.top();
        _opStack.push(temp);
    }
}

void VM::swap(std::stack<IOperand*> &_opStack) {
    if (_opStack.size() < 2)
        throw std::runtime_error("error: swap on a stack with less than 2 values.");
    else {
        IOperand* temp = _opStack.top();
        _opStack.pop();
        IOperand* temp2 = _opStack.top();
        _opStack.pop();
        _opStack.push(temp);
        _opStack.push(temp2);
    }
}

void VM::dump(std::stack<IOperand*> &_opStack) {
    if (_opStack.empty())
        throw std::runtime_error("error: dump on an empty stack.");
    else {
        std::stack<IOperand*> tmp = _opStack;
        while (!tmp.empty()) {
            std::cout << tmp.top()->toString() << std::endl;
            tmp.pop();
        }
    }
}

void VM::assert(Parser &parser, std::stack<IOperand*> &_opStack) {
    if (_opStack.empty())
        throw std::runtime_error("error: assert on an empty stack.");
    else {
        _type = stringToOperandType(parser._operands[_val]);
        _op = Factory::createOperand(_type, parser._values[_val]);
        if (_opStack.top()->toString() != _op->toString())
            throw std::runtime_error("error: assert failed.");
        _val++;
    }
}

void VM::add(std::stack<IOperand*> &_opStack) {
    if (_opStack.size() < 2)
        throw std::runtime_error("error: add on a stack with less than 2 values.");
    else {
        IOperand* temp = _opStack.top();
        _opStack.pop();
        IOperand* temp2 = _opStack.top();
        _opStack.pop();
        IOperand* result = temp->operator+(*temp2);
        _opStack.push(result);
    }
}

void VM::sub(std::stack<IOperand*> &_opStack) {
    if (_opStack.size() < 2)
        throw std::runtime_error("error: sub on a stack with less than 2 values.");
    else {
        IOperand* temp = _opStack.top();
        _opStack.pop();
        IOperand* temp2 = _opStack.top();
        _opStack.pop();
        IOperand* result = temp->operator-(*temp2);
        _opStack.push(result);
    }
}

void VM::mul(std::stack<IOperand*> &_opStack) {
    if (_opStack.size() < 2)
        throw std::runtime_error("error: mul on a stack with less than 2 values.");
    else {
        IOperand* temp = _opStack.top();
        _opStack.pop();
        IOperand* temp2 = _opStack.top();
        _opStack.pop();
        IOperand* result = temp->operator*(*temp2);
        _opStack.push(result);
    }
}

void VM::div(std::stack<IOperand*> &_opStack) {
    if (_opStack.size() < 2)
        throw std::runtime_error("error: div on a stack with less than 2 values.");
    else {
        try {
            IOperand* temp = _opStack.top();
            _opStack.pop();
            IOperand* temp2 = _opStack.top();
            _opStack.pop();
            IOperand* result = temp->operator/(*temp2);
            _opStack.push(result);
        } catch (std::exception &e) {
            throw std::runtime_error(e.what());
        }
    }
}

void VM::mod(std::stack<IOperand*> &_opStack) {
    if (_opStack.size() < 2)
        throw std::runtime_error("error: mod on a stack with less than 2 values.");
    else {
        try {
            IOperand* temp = _opStack.top();
            _opStack.pop();
            IOperand* temp2 = _opStack.top();
            _opStack.pop();
            IOperand* result = temp->operator%(*temp2);
            _opStack.push(result);
        } catch (std::exception &e) {
            throw std::runtime_error(e.what());
        }
    }
}

void VM::load(std::stack<IOperand*> &_opStack) {}

void VM::store(std::stack<IOperand*> &_opStack) {}

void VM::print(std::stack<IOperand*> &_opStack) {
    if (_opStack.empty())
        throw std::runtime_error("error: print on an empty stack.");
    else {
        if (_opStack.top()->getType() != Int8)
            throw std::runtime_error("error: value is not of type int8.");
        else
            std::cout << static_cast<char>(std::stoi(_opStack.top()->toString())) << std::endl;
    }
}
