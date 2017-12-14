##
## Makefile for  in /home/chatea_s/project/unix/my_script
## 
## Made by Sylvain Chateau
## Login   <chatea_s@epitech.net>
## 
## Started on  Fri Jan 31 14:28:47 2014 Sylvain Chateau
## Last update Sat Mar 29 20:23:04 2014 Sylvain Chateau
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wall -Wextra

NAME	= lemipc

SRCS	= main.c \
	  init_board.c \
	  init_players.c \
	  lemipc.c \
	  lock_sem.c \
	  number_player.c \
	  opponent.c

OBJS	= $(SRCS:.c=.o)

$(NAME)	: $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

all	: $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all
