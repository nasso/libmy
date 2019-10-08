CC=gcc
CFLAGS=-fno-builtin -W -Wall -Werror
LIBS=
LIB_FOLDERS=
INCLUDE_FOLDERS=
TEST_CFLAGS=--coverage
TEST_LIBS=
TEST_LIB_FOLDERS=
TEST_INCLUDE_FOLDERS=

# Libs
LIB_FOLDERS += -L./lib/my
LIBS += -lmy
INCLUDE_FOLDERS += -I./include/

# Test libs
TEST_LIBS += -lcriterion

all: clean tests_run cover

unit_tests.o:
	$(CC) \
		$(CFLAGS) $(TEST_CFLAGS) \
		-o unit_tests.o \
		./*.c ./tests/*.c \
		$(INCLUDE_FOLDERS) \
		$(LIB_FOLDERS) $(LIBS) \
		$(TEST_LIB_FOLDERS) $(TEST_LIBS)

./lib/my/libmy.a:
	cd ./lib/my && ./build.sh

tests_run: ./lib/my/libmy.a unit_tests.o
	./unit_tests.o

cover: tests_run
	gcovr --exclude tests/ 
	gcovr --exclude tests/ --branches

clean:
	rm -f **.o **/*.o
	rm -f **.a **/*.a
	rm -f **.gcda **/*.gcda
	rm -f **.gcno **/*.gcno
	rm -f program 

.PHONY: all clean cover tests_run 
