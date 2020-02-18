##
## EPITECH PROJECT, 2018
## make file
## File description:
## make file
##

RM		=	rm -f

SRC		=	./lib/my/my_printf.c		\
			./lib/my/display_print.c	\
			./lib/my/flag_number.c		\
			./lib/my/string_flags.c		\
			./lib/my/get_number.c		\
			./lib/my/assign_number.c	\
			./lib/my/found_assign.c		\
			./lib/my/reco.c				\
			./lib/my/number.c			\
			./lib/my/sepa.c				\
			./lib/my/secu_string.c

OBJ		=	$(SRC:.c=.o)

TEST	=	tests/test_printf.c

TNAME	=	tests/unit_test

NAME	=	libmy.a

all:		$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	make clean

tests_run:
			gcc -o $(TNAME) $(SRC) $(TEST) --coverage -lcriterion
			tests/./unit_test

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
