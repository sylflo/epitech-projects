##
## Makefile for  in /home/chatea_s/project/unix/my_script
## 
## Made by Sylvain Chateau
## Login   <chatea_s@epitech.net>
## 
## Started on  Fri Jan 31 14:28:47 2014 Sylvain Chateau
## Last update Sun Mar 30 19:56:24 2014 edouard mansuy
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wall -Wextra

LDFLAGS	= -lSDL

NAME	= display

SRCS	= main.c \
	  draw_map.c \
	  init_grid.c \
	  init_sdl.c \
	  map_and_pos.c

OBJS	= $(SRCS:.c=.o)

$(NAME)	: $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LDFLAGS)

all	: $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all
