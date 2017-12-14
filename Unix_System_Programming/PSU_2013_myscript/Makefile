##
## Makefile for  in /home/chatea_s/project/unix/my_script
## 
## Made by Sylvain Chateau
## Login   <chatea_s@epitech.net>
## 
## Started on  Fri Jan 31 14:28:47 2014 Sylvain Chateau
## Last update Tue Feb 18 13:32:05 2014 Sylvain Chateau
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wall -Wextra 

LDFLAGS	= -lutil

NAME	= my_script

SRCS	= main.c \
	  my_forkpty.c \
	  misc.c \
	  canonic_mode.c \
	  script.c 

OBJS	= $(SRCS:.c=.o)

$(NAME)	: $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LDFLAGS)

all	: $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all
