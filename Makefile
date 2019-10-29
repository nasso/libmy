##
## EPITECH PROJECT, 2019
## libmy
## File description:
## Makefile to build libmy
##

CC		=	gcc

INCLUDE =	-I./include

CFLAGS	=	-fdiagnostics-color -fno-builtin -W -Wall -Wextra $(INCLUDE)

SRC		=	./src/my_compute_power_rec.c \
			./src/my_compute_square_root.c \
			./src/my_find_prime_sup.c \
			./src/my_getnbr_base.c \
			./src/my_getnbr.c \
			./src/my_isneg.c \
			./src/my_is_prime.c \
			./src/my_putchar.c \
			./src/my_putnbr_base.c \
			./src/my_put_nbr.c \
			./src/my_putstr.c \
			./src/my_revstr.c \
			./src/my_showmem.c \
			./src/my_showstr.c \
			./src/my_show_word_array.c \
			./src/my_sort_int_array.c \
			./src/my_strcapitalize.c \
			./src/my_strcat.c \
			./src/my_strcmp.c \
			./src/my_strcpy.c \
			./src/my_str_isalpha.c \
			./src/my_str_islower.c \
			./src/my_str_isnum.c \
			./src/my_str_isprintable.c \
			./src/my_str_isupper.c \
			./src/my_strlen.c \
			./src/my_strlowcase.c \
			./src/my_strncat.c \
			./src/my_strncmp.c \
			./src/my_strncpy.c \
			./src/my_strstr.c \
			./src/my_strupcase.c \
			./src/my_swap.c

TESTSRC	=	./tests/compute_square_root.c \
			./tests/find_prime_sup.c \
			./tests/put_nbr.c \
			./tests/putnbr_base.c \
			./tests/revstr.c \
			./tests/show_word_array.c \
			./tests/str_isalpha.c \
			./tests/str_islower.c \
			./tests/str_isprintable.c \
			./tests/strcapitalize.c \
			./tests/strcat.c \
			./tests/strncat.c \
			./tests/strncmp.c \
			./tests/strncpy.c \
			./tests/strstr.c

OBJ		=	$(SRC:.c=.o)

TESTOBJ	=	$(TESTSRC:.c=.o)

COVREPS	=	$(SRC:.c=.gcda) $(SRC:.c=.gcno) \
			$(TESTSRC:.c=.gcda) $(TESTSRC:.c=.gcno)

NAME	=	libmy.a

TEST	=	unit-tests

all: $(NAME)

tests_run: $(TEST)
	./$(TEST)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

$(TEST): CFLAGS += --coverage
$(TEST): LIBS += -lm -lcriterion
$(TEST): $(OBJ) $(TESTOBJ)
	$(CC) $(CFLAGS) -o $(TEST) $(OBJ) $(TESTOBJ) $(LIBDIRS) $(LIBS)

clean:
	rm -f $(OBJ) $(TESTOBJ) $(COVREPS)

fclean: clean
	rm -f $(NAME) $(TEST)

re: fclean all

retest: fclean tests_run

.PHONY: all tests_run clean fclean re retest
