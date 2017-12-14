##
## Makefile for nibbler in /home/storm/snake_test/snake
## 
## Made by Julian Caille
## Login <caille_j@epitech.net>
## 
## Started on  Wed Apr  2 18:44:55 2014 Julian Caille
## Last update Sun Jul 13 22:52:39 2014 Arthur Coudert
##

NAME		= zappy_gui

ASMFLAGS	=
CFLAGS		=
CXXFLAGS	=
LDFLAGS		= -lsfml-audio -lsfml-network -lsfml-graphics -lsfml-window -lsfml-system

SRCSXX		= main.cpp \
		  Sound.cpp \
		  Menu.cpp \
		  Texture.cpp \
		  Animate.cpp \
		  Game.cpp \
		  Network.cpp \
		  World.cpp \
		  Case.cpp \
		  Team.cpp \
		  LivingEntity.cpp \
		  Item.cpp \
		  Draw.cpp \
		  Camera.cpp \
		  Events.cpp \
		  CountItems.cpp \
		  InitializeAnimations.cpp \
		  Entities.cpp \
		  BroadCast.cpp \
		  Line.cpp \
		  Time.cpp \
		  Socket.cpp \
		  CheckSound.cpp


CXX		= g++
RM		= rm -f
RMDIR		= rm -rf
MKDIR		= mkdir -p
CPY		= cp

SRCDIR		= src
HEADDIR		= inc
OBJDIR		= obj
BINDIR		= ..
INSTALLDIR	= /bin

VPATH		= $(SRCDIR):$(OBJDIR):$(BINDIR)

CFLAGS		+= -I$(SRCDIR) -I$(HEADDIR) -Wall -Wextra
CXXFLAGS	+= -I$(SRCDIR) -I$(HEADDIR) -Wall -Wextra

LDFLAGS		+= -lstdc++

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

$(OBJDIR)/%.cpp.o:	%.cpp
			@if [ ! -d "./$(OBJDIR)" ]; then $(MKDIR) $(OBJDIR); echo " (MKDIR) $(OBJDIR)"; fi
			@$(CXX) $(CXXFLAGS) -o $@ -c $<
			@echo " (CXX) $@"

.PHONY:		all compilate clean fclean dclean re
