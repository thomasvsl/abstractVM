/*
** EPITECH PROJECT, 2024
** B-SYN-400-MAR-4-1-abstractVM-thomas.vidal-savelli
** File description:
** VM.hpp
*/

#ifndef VM_HPP
    #define VM_HPP

#include "Parser.hpp"
#include "Factory.hpp"

class VM {
    public:
        ~VM();
        VM();
        int run(Parser &parser);
        eOperandType stringToOperandType(const std::string& typeStr);
        IOperand* _op;
    private:
        size_t _line;
        eOperandType _type;
        int _val = 0;
        int _v = 0;
        void push(Parser &parser, std::stack<IOperand*> &_opStack);
        void pop(std::stack<IOperand*> &_opStack);
        void clear(std::stack<IOperand*> &_opStack);
        void dup(std::stack<IOperand*> &_opStack);
        void swap(std::stack<IOperand*> &_opStack);
        void dump(std::stack<IOperand*> &_opStack);
        void assert(Parser &parser, std::stack<IOperand*> &_opStack);
        void add(std::stack<IOperand*> &_opStack);
        void sub(std::stack<IOperand*> &_opStack);
        void mul(std::stack<IOperand*> &_opStack);
        void div(std::stack<IOperand*> &_opStack);
        void mod(std::stack<IOperand*> &_opStack);
        void load(std::stack<IOperand*> &_opStack);
        void store(std::stack<IOperand*> &_opStack);
        void print(std::stack<IOperand*> &_opStack);
};

#endif // VM_HPP
