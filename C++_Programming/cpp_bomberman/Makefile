NAME	:=	bomberman
CXXFLAGS:=	-I./inc -I./sound/inc -I./gdl/includes
DEBUG	:=	-g3  -Wall -Wextra -Werror
LIBDIR	:=	./gdl/libs ./sound/lib/libfmodex64.so	
LDFLAGS	:=	-L$(LIBDIR) -lgdl_gl -lGL -lGLEW -ldl -lrt -lfbxsdk -lSDL2 -lpthread -Wl,-rpath=$(LIBDIR)
OBJDIR	:=	obj
SRCDIR	:=	src

GREEN	:=	'\033[1;32m'
RED	:=	'\033[1;31m'
NC	:=	'\033[1;m'
MSG_CLEAN:=	echo -e $(GREEN)'clean: Done.'$(NC)
MSG_FCLEAN:=	echo -e $(GREEN)'fclean: Done.'$(NC)

MSG_DEBUG:=	echo -e $(RED)'Debug'$(NC)
# "\
# 	   _, \
#        `$$' \
#         $$  \
#         $$  \
#   ,d$$$g$$  \
#  ,$$P' `$$  \
#  $$'    $$  \
#  $$     $$  \
#  $$    ,$$  \
#  `$$g.,$$$  \
#   `Y$$P'$$. \
# "

FILE_EXCLUDED:=	$(addprefix $(SRCDIR)/, Menu.cpp Ia.cpp Ai.cpp)
MSG_EXCLUSION:=	echo -e $(RED)'the following have been exclude from compilation : '$(NC)$(FILE_EXCLUDED)

CHECKEX	:=	@if [[ '${FILE_EXCLUDED}' ]]; then  $(MSG_EXCLUSION); fi
SRC	:=	$(filter-out $(FILE_EXCLUDED),$(wildcard $(SRCDIR)/*.cpp))
OBJ	:=	$(addprefix $(OBJDIR)/,$(notdir $(SRC:.cpp=.o)))


$(NAME):	$(OBJ)
	$(CHECKEX) && $(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

all:		$(NAME)


$(OBJDIR)/%.o:	$(SRCDIR)/%.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

debug:		$(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS) $(DEBUG)

print-%:
	@echo "$*=$($*)"

clean:
	@$(RM) $(OBJ) && $(MSG_CLEAN)

fclean:		clean
	@$(RM) $(NAME) &&  $(MSG_FCLEAN)

re:		fclean all

re4:		
	@clear && make -s fclean && make -j4

.PHONY: all debug clean fclean print-% re re4
