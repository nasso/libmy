##
## EPITECH PROJECT, 2019
## libbignum
## File description:
## Makefile to build libbignum
##

CC		=	gcc

INCLUDE	=	-I./include -I./lib/include

CFLAGS	=	-fdiagnostics-color -fno-builtin -W -Wall -Wextra $(INCLUDE)

LIBDIRS	=	-L./lib

LIBS	=

SRC		=	./src/bufreader.c \
			./src/filereader.c \
			./src/bufwriter.c \
			./src/filewriter.c

TESTSRC	=

OBJ		=	$(SRC:.c=.o)

TESTOBJ	=	$(TESTSRC:.c=.o)

TEST	=	unit-tests

NAME	=	libstream.a

all: $(NAME)

libs:
	$(MAKE) -C ./lib

dep_build: libs
	for lib in $(LIBS); \
	do \
		name=$$(echo $$lib | sed -e 's/^-l/lib/'); \
		mkdir -p ./dep_build/$$name; \
		cd ./dep_build/$$name; \
		ar x ../../lib/$$name.a; \
		cd ../..; \
	done

tests_run: $(TEST)
	./$(TEST)

$(NAME): dep_build $(OBJ)
	if [ -d ./dep_build ]; then \
		ar -rc $(NAME) $(OBJ) ./dep_build/**/*.o; \
	else \
		ar -rc $(NAME) $(OBJ); \
	fi

$(TEST): LIBS += -lcriterion
$(TEST): libs $(OBJ) $(TESTOBJ)
	$(CC) $(CFLAGS) -o $(TEST) $(OBJ) $(TESTOBJ) $(LIBDIRS) $(LIBS)

testbin: CFLAGS += -g3
testbin: $(OBJ) ./tests/main.o
	$(CC) $(CFLAGS) -o a.out $(OBJ) ./tests/main.o $(LIBDIRS) $(LIBS)

clean:
	$(MAKE) -C ./lib clean
	rm -f $(OBJ) $(TESTOBJ)
	rm -rf dep_build

fclean: clean
	$(MAKE) -C ./lib fclean
	rm -f $(NAME) $(TEST) a.out

re: fclean all

retest: fclean tests_run

retestbin: fclean testbin

.PHONY: all libs tests_run testbin clean fclean re retest retestbin
