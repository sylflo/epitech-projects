## Makefile for  in /home/chatea_s/cpp_nibbler
## 
## Made by Sylvain Chateau
## Login   <chatea_s@epitech.net>
## 
## Started on  Wed Apr  2 22:29:21 2014 Sylvain Chateau
## Last update Sat Apr  5 12:59:25 2014 Sylvain Chateau
##

SFML_SRC  	= 	Sfml.cpp 

SFML_NAME 	= 	lib_nibbler_sfml.so

RM		= 	rm -f

CPPFLAGS 	+= 	-W -Wextra -Wall
CPPFLAGS 	+= 	-rdynamic -fPIC

CC		= 	g++

SFML_OBJ  	= 	$(SFML_SRC:.cpp=.o)

$(SFML_NAME): 	$(SFML_OBJ)
			$(CC) -shared $(SFML_OBJ) -o $(SFML_NAME) -lsfml-network -lsfml-graphics -lsfml-window -lsfml-system

all: 		 $(SFML_NAME)

clean:
	$(RM) 	$(SFML_OBJ)

fclean: clean
	$(RM) 	$(SFML_NAME)

re: fclean all

.PHONY: all clean fclean re
