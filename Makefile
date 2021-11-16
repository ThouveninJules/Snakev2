CC	:=	g++

RM	:=	rm -f

NAME	:=	snake

SRC	:=	./source/*.cpp

INCL    :=      ./include/*.hpp

LFLAGS	:=	-lsfml-graphics -lsfml-window -lsfml-system 

OBJ	:=	$(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC)  -o $(NAME) $(OBJ) $(INCL)  $(LFLAGS)
clean:
	$(RM) $(OBJ) 

fclean:		clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:		all clean fclean re
