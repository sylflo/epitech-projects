## Makefile for  in /home/chatea_s/cpp_nibbler
## 
## Made by Sylvain Chateau
## Login   <chatea_s@epitech.net>
## 
## Started on  Wed Apr  2 22:29:21 2014 Sylvain Chateau
## Last update Sat Apr  5 13:18:25 2014 Sylvain Chateau
##

NB_SRC 		= 	Nibbler.cpp \
			Objlib.cpp \
			main.cpp

NB_NAME 	= 	$(addprefix ../, nibbler)

RM		= 	rm -f

CPPFLAGS 	+= 	-W -Wextra -Wall
CPPFLAGS 	+= 	-rdynamic -fPIC

CC		= 	g++

NB_OBJ 		= 	$(NB_SRC:.cpp=.o)

$(NB_NAME): 	$(NB_OBJ)
			$(CC) $(NB_OBJ) -lpthread -ldl -o $(NB_NAME)

all: 		$(NB_NAME)

clean:
	$(RM) 	$(NB_OBJ)

fclean: clean
	$(RM) 	$(NB_NAME)

re: fclean all

.PHONY: all clean fclean re
