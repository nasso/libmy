##
## EPITECH PROJECT, 2019
## libmy
## File description:
## Makefile to test libmy.
##

CC		=	gcc

CFLAGS	=	-fno-builtin -W -Wall -Wextra -Werror --coverage

LIBDIRS	=	-L./lib/

LIBS	= 	-lmy \
			-lcriterion \
			-lm

INCLUDE	=	-I./include/

SRC		=	./tests/test_my_compute_power_rec.c \
			./tests/test_my_compute_square_root.c \
			./tests/test_my_find_prime_sup.c \
			./tests/test_my_putnbr_base.c \
			./tests/test_my_put_nbr.c \
			./tests/test_my_revstr.c \
			./tests/test_my_show_word_array.c \
			./tests/test_my_strcapitalize.c \
			./tests/test_my_strcat.c \
			./tests/test_my_str_isalpha.c \
			./tests/test_my_str_islower.c \
			./tests/test_my_str_isprintable.c \
			./tests/test_my_strncat.c \
			./tests/test_my_strncmp.c \
			./tests/test_my_strncpy.c \
			./tests/test_my_strstr.c

OBJ		=	$(SRC:.c=.o)

LIBMY	=	./lib/libmy.a

NAME	=	tester

all: tests_run

$(LIBMY):
	$(MAKE) -C ./lib/my

%.o: %.c
	$(CC) \
		$(CFLAGS) \
		-o $@ \
		-c $< \
		$(INCLUDE) \
		$(LIBDIRS) $(LIBS) 

$(NAME): $(LIBMY) $(OBJ)
	$(CC) \
		$(CFLAGS) \
		-o $(NAME) \
		$(OBJ) \
		$(INCLUDE) \
		$(LIBDIRS) $(LIBS)

tests_run: $(NAME)
	./$(NAME)

clean:
	$(MAKE) -C ./lib/my clean
	find . -name "*.o" -delete
	find . -name "*.a" -delete
	find . -name "*.gcda" -delete
	find . -name "*.gcno" -delete

fclean: clean
	$(MAKE) -C ./lib/my fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean cover tests_run 
