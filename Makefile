##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## task01
##

EXEC   =    nanotekspice

all:   $(EXEC)

$(EXEC):    $(OBJ)
	g++ -o $(EXEC) Parser/*.cpp Components/*.cpp src/*.cpp

clean:
	rm -f $(EXEC)

fclean: clean
	rm -f $(EXEC)

re: fclean all
