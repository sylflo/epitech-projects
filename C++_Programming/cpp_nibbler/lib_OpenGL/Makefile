## Makefile for  in /home/chatea_s/cpp_nibbler
## 
## Made by Sylvain Chateau
## Login   <chatea_s@epitech.net>
## 
## Started on  Wed Apr  2 22:29:21 2014 Sylvain Chateau
## Last update Sat Apr  5 13:27:05 2014 Sylvain Chateau
##

OGL_SRC 	= 	OpenGL.cpp \
			Painter.cpp \
			Texture.cpp

OGL_NAME 	= 	lib_nibbler_opengl.so

RM		= 	rm -f

CPPFLAGS 	+= 	-W -Wextra -Wall
CPPFLAGS 	+= 	-rdynamic -fPIC

CC		= 	g++

OGL_OBJ 	= 	$(OGL_SRC:.cpp=.o)

$(OGL_NAME): 	$(OGL_OBJ)
			$(CC) -shared $(OGL_OBJ) -o $(OGL_NAME) -lglut -lGL -lGLU -lsfml-network -lsfml-graphics -lsfml-window -lsfml-system

all: 		$(OGL_NAME)

clean:
	$(RM) 	$(OGL_OBJ)

fclean: clean
	$(RM) 	$(OGL_NAME)

re: fclean all

.PHONY: all clean fclean re
