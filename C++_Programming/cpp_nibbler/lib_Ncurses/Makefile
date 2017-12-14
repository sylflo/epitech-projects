## Makefile for  in /home/chatea_s/cpp_nibbler
## 
## Made by Sylvain Chateau
## Login   <chatea_s@epitech.net>
## 
## Started on  Wed Apr  2 22:29:21 2014 Sylvain Chateau
## Last update Sat Apr  5 13:02:44 2014 Sylvain Chateau
##

NCU_SRC		=	Ncurse.cpp

NCU_NAME	=	lib_nibbler_ncurses.so

RM		= 	rm -f

CPPFLAGS 	+= 	-W -Wextra -Wall
CPPFLAGS 	+= 	-rdynamic -fPIC -g

NCU_OBJ		=	$(NCU_SRC:.cpp=.o)

$(NCU_NAME):	$(NCU_OBJ)
			$(CC) -shared $(NCU_OBJ) -o $(NCU_NAME) -lsfml-graphics -lsfml-window -lsfml-system -lncurses

all: 		 $(NCU_NAME)

clean:
	$(RM) 	$(NCU_OBJ)

fclean: clean
	$(RM) 	$(NCU_NAME)

re: fclean all

.PHONY: all clean fclean re
