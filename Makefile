##
## EPITECH PROJECT, 2019
## libmy
## File description:
## Makefile to build libmy
##

CC		=	gcc

INCLUDE =	-I./include -I./lib/include

CFLAGS	=	-fdiagnostics-color -fno-builtin -W -Wall -Wextra -pedantic \
			$(INCLUDE)

LIBDIRS =	-L./lib

LIBS	=	-lstream

SRC		=	./src/my_compute_power_rec.c \
			./src/my_compute_square_root.c \
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
			./src/my_strchr.c \
			./src/my_strchr_mut.c \
			./src/my_strupcase.c \
			./src/my_swap.c \
			./src/fmt/my_format.c \
			./src/fmt/my_printf.c \
			./src/fmt/my_vbufprintf.c \
			./src/fmt/my_fmt__converter.c \
			./src/fmt/my_fmt__converter_new.c \
			./src/fmt/my_fmt__converter_fn_d.c \
			./src/fmt/my_fmt__converter_fn_c.c \
			./src/fmt/my_fmt__converter_fn_s.c \
			./src/fmt/my_fmt__converter_fn_u.c \
			./src/fmt/my_fmt__converter_fn_pc.c \

TESTSRC	=	./tests/compute_square_root.c \
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
			./tests/strstr.c \
			./tests/format.c

OBJ		=	$(SRC:.c=.o)

TESTOBJ	=	$(TESTSRC:.c=.o)

COVREPS	=	$(SRC:.c=.gcda) $(SRC:.c=.gcno) \
			$(TESTSRC:.c=.gcda) $(TESTSRC:.c=.gcno)

BUNDLE	=	all

NAME	=	libmy.a

TEST	=	unit-tests

all: $(NAME)

libs:
	$(MAKE) -C ./lib

tests_run: $(TEST)
	./$(TEST)

$(NAME): libs $(OBJ)
	if [ '$(BUNDLE)' = 'all' ]; then \
		mkdir -p build_deps; \
		cd build_deps; \
		ar x ../lib/*.a; \
		cd ..; \
		ar -rc $(NAME) $(OBJ) ./build_deps/*.o; \
	else \
		ar -rc $(NAME) $(OBJ); \
	fi

$(TEST): CFLAGS += --coverage
$(TEST): LIBS += -lm -lcriterion
$(TEST): libs $(OBJ) $(TESTOBJ)
	$(CC) $(CFLAGS) -o $(TEST) $(OBJ) $(TESTOBJ) $(LIBDIRS) $(LIBS)

testbin: CFLAGS += -g3
testbin: libs $(OBJ) ./tests/main.o
	$(CC) $(CFLAGS) -o a.out $(OBJ) ./tests/main.o $(LIBDIRS) $(LIBS)

clean:
	$(MAKE) -C ./lib clean
	rm -f $(OBJ) $(TESTOBJ) $(COVREPS) ./tests/main.o
	rm -rf ./build_deps

fclean: clean
	$(MAKE) -C ./lib fclean
	rm -f $(NAME) $(TEST) a.out

re: fclean all

retest: fclean tests_run

retestbin: fclean testbin

.PHONY: all tests_run testbin clean fclean re retest retestbin
