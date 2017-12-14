##
## Makefile for  in /home/chatea_s/project/unix/my_script
## 
## Made by Sylvain Chateau
## Login   <chatea_s@epitech.net>
## 
## Started on  Fri Jan 31 14:28:47 2014 Sylvain Chateau
## Last update Sun Apr 27 19:19:20 2014 Sylvain Chateau
##

CC	= g++

RM	= rm -f

CPPFLAGS += -Wall -Wextra  -g

NAME	= plazza

SRCS	= main.cpp \
	  Thread.cpp \
	  Receive.cpp

OBJS	= $(SRCS:.cpp=.o)

$(NAME)	: $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

all	: $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all
