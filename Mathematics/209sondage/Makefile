##
## Makefile for  in /home/chatea_s/project/unix/my_script
## 
## Made by Sylvain Chateau
## Login   <chatea_s@epitech.net>
## 
## Started on  Fri Jan 31 14:28:47 2014 Sylvain Chateau
## Last update Sun Jun  8 12:38:25 2014 
##

CC	= g++

RM	= rm -f

LDFLAGS = -lm

NAME	= 209sondage

SRCS	= main.c \

OBJS	= $(SRCS:.c=.o)

$(NAME)	: $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

all	: $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all
