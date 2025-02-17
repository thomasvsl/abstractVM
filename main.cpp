/*
** EPITECH PROJECT, 2024
** B-SYN-400-MAR-4-1-abstractVM-thomas.vidal-savelli
** File description:
** main.cpp
*/

#include "./include/Parser.hpp"

int main(int ac, char **av) {
    Parser parser;
    if (ac == 2) {
        try {
            parser.parseFile(av[1]);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
            return 84;
        }
    } else if (ac < 2) {
        std::string line;
        std::ofstream file("output.avm"); // create file

        while (std::getline(std::cin, line)) {
            if (line == ";;") {
                break; // exit the loop
            }
            if (file.is_open()) {
                file << line << std::endl; // write line to file
            } else {
                std::cerr << "Error: Unable to open file." << std::endl;
                return 84;
            }
        }
        file.close();
        try {
            parser.parseFile("output.avm");
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
            return 84;
        }
    }
    return 0;
}
