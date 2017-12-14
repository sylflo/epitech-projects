##
## Makefile for Makefile  in /home/storm/IA/Gomoku
## 
## Made by caille_j
## Login   <caille_j@epitech.net>
## 
## Started on  Mon Nov  3 11:28:01 2014 
## Last update Wed Dec 17 14:25:17 2014 caille_j
##

NAME		= gomoku

ASMFLAGS	=
CFLAGS		=
CXXFLAGS	=
LDFLAGS		= -DSFML_STATIC -lsfml-audio -lsfml-network -lsfml-graphics -lsfml-window -lsfml-system -lm

SRCSXX		= main.cpp \
		  Sound.cpp \
		  Texture.cpp \
		  Menu.cpp \
		  Hotkeys.cpp \
		  MenuShow.cpp \
		  Game.cpp \
		  GameDraw.cpp \
		  Referee.cpp \
	          Board.cpp \
		  VerifyFinish.cpp

CXX		= g++
RM		= rm -f
RMDIR		= rm -rf
MKDIR		= mkdir -p
CPY		= cp

SRCDIR		= src
HEADDIR		= inc
OBJDIR		= obj
BINDIR		= ./
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
			@echo " (CPP) $@"

.PHONY:		all compilate clean fclean dclean re
