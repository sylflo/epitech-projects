##
## Makefile for  in /home/chatea_s/am/norme/asm
## 
## Made by Sylvain Chateau
## Login   <chatea_s@epitech.net>
## 
## Started on  Sat Mar 29 21:59:24 2014 Sylvain Chateau
## Last update Sun Mar 30 20:50:55 2014 Sylvain Chateau
##

NAME	= libasm.so

ASM	= nasm -f elf64 -g

CC	= gcc

CFLAGS	= -shared -fPIC -W -Wall -fno-builtin

SRC	= strlen.S \
	  strchr.S \
	  memset.S \
	  strcmp.S \
	  memcpy.S \
	  strcasecmp.S \
	  memmove.S \
	  rindex.S \

OBJ	= $(SRC:.S=.o)

RM	= rm -f

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

%.o: %.S
	$(ASM) -o $@ $<
