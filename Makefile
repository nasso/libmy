CC=gcc
CFLAGS=-fno-builtin -W -Wall -Werror

# Libs
INCLUDE_FOLDERS= \
	-I./include/

# Test options
TEST_CFLAGS=--coverage
TEST_INCLUDE_FOLDERS=
TEST_LIB_FOLDERS=
TEST_LIBS= \
	-lcriterion \
	-lm

all: tests_run cover

unit_tests.o:
	$(CC) \
		$(CFLAGS) $(TEST_CFLAGS) \
		-o unit_tests.o \
		./lib/my/*.c ./tests/*.c \
		$(INCLUDE_FOLDERS) \
		$(LIB_FOLDERS) $(LIBS) \
		$(TEST_LIB_FOLDERS) $(TEST_LIBS)

tests_run: unit_tests.o
	./unit_tests.o

cover: tests_run
	gcovr --exclude tests/ 
	gcovr --exclude tests/ --branches

clean:
	find . -name "*.o" -delete
	find . -name "*.a" -delete
	find . -name "*.gcda" -delete
	find . -name "*.gcno" -delete

.PHONY: all clean cover tests_run 
