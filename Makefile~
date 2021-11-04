CC	:=	g++

RM	:=	rm -f

NAME	:=	snake

SRC	:=	./src/*.cpp

LFLAGS	:=	-lsfml-graphics -lsfml-window -lsfml-system 

OBJ	:=	$(SRC:.cpp=.o)

INC	:= 	$(SRC:.hpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC)  -o $(NAME) $(OBJ) $(INC)  $(LFLAGS)
clean:
	$(RM) $(OBJ) 

fclean:		clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:		all clean fclean re
