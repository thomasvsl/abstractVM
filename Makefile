##
## EPITECH PROJECT, 2024
## B-SYN-400-MAR-4-1-abstractVM-thomas.vidal-savelli
## File description:
## Makefile
##

SRC = 	main.cpp \
		./src/AOperand.cpp \
		./src/Factory.cpp \
		./src/Parser.cpp \
		./src/VM.cpp \
		./src//Command.cpp \

NAME = abstractVM

all:
	g++ -o $(NAME) $(SRC) -g3

clean:
	rm -f *.o
	rm -f *~

fclean : clean
	rm -f $(NAME)

re: fclean 	all
