CC	:=	g++

RM	:=	rm -f

NAME	:=	snake

SRC	:=	./source/*.cpp

INCL    :=      ./include/*.hpp

LFLAGS	:=	-lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system


all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC)  -o $(NAME) $(SRC) $(INCL)  $(LFLAGS)
clean:
	$(RM) $(OBJ) 

fclean:		clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:		all clean fclean re
