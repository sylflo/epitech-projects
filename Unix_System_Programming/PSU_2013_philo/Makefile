##
## Makefile for  in /home/chatea_s/project/unix/my_script
## 
## Made by Sylvain Chateau
## Login   <chatea_s@epitech.net>
## 
## Started on  Fri Jan 31 14:28:47 2014 Sylvain Chateau
## Last update Sun Mar 23 21:46:31 2014 Sylvain Chateau
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wall -Wextra  

LDFLAGS	= -lpthread

NAME	= philo

SRCS	= philo.c \
	  philo_two.c

OBJS	= $(SRCS:.c=.o)

$(NAME)	: $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LDFLAGS)

all	: $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all
