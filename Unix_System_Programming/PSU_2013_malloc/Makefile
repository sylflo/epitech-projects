##
## Makefile for  in /home/chatea_s/project/unix/malloc/project
## 
## Made by Sylvain Chateau
## Login   <chatea_s@epitech.net>
## 
## Started on  Fri Feb 14 16:56:51 2014 Sylvain Chateau
## Last update Sun Feb 16 22:04:52 2014 Sylvain Chateau
##

NAME	= libmy_malloc_$(HOSTTYPE).so

LINK	= libmy_malloc.so

SRC 	= malloc.c \
	  realloc.c \
	  free.c \
	  showmem.c

CC 	= gcc

OBJS 	= $(SRC:.c=.o)

CFLAGS 	= -fPIC -Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(CC) -shared -o $(NAME) $(OBJS)
	ln -sf $(NAME) $(LINK)

all:	$(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)
	rm -f $(LINK)

re:	fclean all 
