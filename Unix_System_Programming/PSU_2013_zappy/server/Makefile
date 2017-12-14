##
## Makefile for  in /home/chatea_s/PSU_2013_zappy
## 
## Made by 
## Login   <chatea_s@epitech.net>
## 
## Started on  Sat Jul 12 20:41:34 2014 
## Last update Sun Jul 13 21:29:16 2014 
##

NAME		= zappy

ASMFLAGS	=
CFLAGS		=
CXXFLAGS	=
LDFLAGS		= -lm

SRCSASM		=

SRCS		= server.c \
		  parsing.c \
		  create_server.c \
		  create_server_2.c \
		  map.c \
		  circular_buf.c \
		  command.c \
		  AI.c \
		  command_2.c \
		  bct.c \
		  msz.c \
		  sgt.c \
		  tna.c \
		  mct.c \
		  tna.c \
		  ppo.c \
		  plv.c \
		  pin.c \
		  sst.c \
		  take_ai.c \
		  drop_ai.c\
		  move_ai.c\
		  orientation.c \
		  pnw.c \
		  vision.c \
		  init_AI.c \
		  write_on_server.c \
		  init_graphic.c \
		  incantation.c \
		  vision2.c \
		  sanitizer.c \
		  expulse.c \
		  expulse2.c \
		  broadcast.c \
		  broadcast_2.c \
		  fork.c \
		  convert_timeval.c \
		  ins_and_del_circ_buf.c \
		  check_and_exec_cmd_ia.c \
		  first_cmd_ia.c \
		  first_cmd_all.c \
		  nbr_connect.c \
		  death.c \
		  death_time.c \
		  do_select.c \
		  time_action.c \
		  init_pointer_array.c \
		  check_level_incantation_1.c \
		  check_level_incantation_2.c \
		  change_map_incantation_1.c \
		  change_map_incantation_2.c \
		  misc_incantation.c \
		  exec_incantation_and_fork.c \
		  win.c \
		  verif_malloc.c

SRCSXX		=

ASM		= nasm
CC		= gcc
CXX		= g++
RM		= rm -f
RMDIR		= rm -rf
MKDIR		= mkdir -p
CPY		= cp
TAR		= tar -cf

SRCDIR		= src
HEADDIR		= include
OBJDIR		= obj
BINDIR		= ..
INSTALLDIR	= /bin

VPATH		= $(SRCDIR):$(OBJDIR):$(BINDIR)

ASMFLAGS	+= -f elf64
CFLAGS		+= -I$(SRCDIR) -I$(HEADDIR) -Wall -Wextra
CXXFLAGS	+= -I$(SRCDIR) -I$(HEADDIR) -Wall -Wextra

LDFLAGS		+= -lstdc++

debug		= 1

ifeq ($(debug), 1)
CFLAGS		+= -g
CXXFLAGS	+= -g
endif
ifeq ($(debug), 2)
CFLAGS		+= -g2
CXXFLAGS	+= -g2
endif
ifeq ($(debug), 3)
qCFLAGS		+= -g3
CXXFLAGS	+= -g3
endif

OBJSASM		= $(SRCSASM:%.S=%.S.o)

OBJS		= $(SRCS:%.c=%.c.o)

OBJSXX		= $(SRCSXX:%.cpp=%.cpp.o)

$(NAME):	$(addprefix $(OBJDIR)/, $(OBJS)) $(addprefix $(OBJDIR)/, $(OBJSXX))
		@if [ ! -d "./$(BINDIR)" ]; then $(MKDIR) $(BINDIR); echo " (MKDIR) $(BINDIR)"; fi
		@$(CC) $^ $(LDFLAGS) -o $(BINDIR)/$(NAME)
		@echo " (CC)  $(BINDIR)/$(NAME)"

all:		compilate $(NAME)
		@echo "ENDING"

compilate:
		@echo "COMPILATING"

clean:
		@$(RM) $(addprefix $(OBJDIR)/, $(OBJS)) $(addprefix $(OBJDIR)/, $(OBJSXX))
		@echo "CLEANING"
		@echo " (RM)$(OBJS) $(OBJSXX)"

fclean:		clean
		@$(RM) $(BINDIR)/$(NAME)
		@echo " (RM) $(NAME)"

dclean:
		@$(RMDIR) $(OBJDIR) $(BINDIR)/$(NAME)
		@echo "CLEANING"
		@echo " (RM) $(OBJS) $(OBJSXX)"
		@echo " (RM) $(NAME)"

re:		fclean all

prepare:
		@if [ ! -d "./$(SRCDIR)" ]; then $(MKDIR) $(SRCDIR); echo " (MKDIR) $(SRCDIR)"; fi
		@if [ ! -d "./$(HEADDIR)" ]; then $(MKDIR) $(HEADDIR); echo " (MKDIR) $(HEADDIR)"; fi

packed:		dclean
		@$(TAR) $(NAME).tar Makefile $(SRCDIR) $(HEADDIR)
		@echo "TARBALL"
		@echo " (TAR) $(NAME).tar"

install:	all
		@$(CPY) $(BINDIR)/$(NAME) $(INSTALLDIR)
		@echo "INSTALL"
		@echo " (CPY) $(NAME)"

$(OBJDIR)/%.S.o:	%.S
			@if [ ! -d "./$(OBJDIR)" ]; then $(MKDIR) $(OBJDIR); echo " (MKDIR) $(OBJDIR)"; fi
			@$(CS) $(CSFLAGS) -o $@ -c $<
			@echo " (CC)  $@"

$(OBJDIR)/%.c.o:	%.c
			@if [ ! -d "./$(OBJDIR)" ]; then $(MKDIR) $(OBJDIR); echo " (MKDIR) $(OBJDIR)"; fi
			@$(CC) $(CFLAGS) -o $@ -c $<
			@echo " (CC)  $@"

$(OBJDIR)/%.cpp.o:	%.cpp
			@if [ ! -d "./$(OBJDIR)" ]; then $(MKDIR) $(OBJDIR); echo " (MKDIR) $(OBJDIR)"; fi
			@$(CXX) $(CXXFLAGS) -o $@ -c $<
			@echo " (CXX) $@"

.PHONY:		all compilate clean fclean dclean re prepare packed install
