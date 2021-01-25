##
## EPITECH PROJECT, 2021
## CPE_corewar_2019 [WSL: Ubuntu]
## File description:
## Makefile
##

SHELL = /bin/sh

# vars
NAME = libmy.a

CFLAGS = -Wall -Wextra -pedantic

# main rule, building main target
all: $(NAME)
.PHONY: all

# equivalent to "fclean all"
re: fclean all
.PHONY: re

# cleans everything but the final target (e.g. objects, libraries...)
clean::
.PHONY: clean

# cleans everything, including the final built targets
fclean::
.PHONY: fclean

# target $(NAME)
TARGET___NAME_ := $(NAME)
TARGET___NAME__SRCS := $(shell find -path './src/*.c')
TARGET___NAME__OBJS := $(TARGET___NAME__SRCS:.c=.o)
TARGET___NAME__CFLAGS := -I./include
TARGET___NAME__CFLAGS += -DMY_ALLOW_FUN_MALLOC
TARGET___NAME__CFLAGS += -DMY_ALLOW_FUN_FREE
TARGET___NAME__CFLAGS += -DMY_ALLOW_FUN_CALLOC
TARGET___NAME__CFLAGS += -DMY_ALLOW_FUN_MEMMOVE
TARGET___NAME__CFLAGS += -DMY_ALLOW_FUN_MEMCPY
TARGET___NAME__CFLAGS += -DMY_ALLOW_FUN_MEMSET
TARGET___NAME__CFLAGS += -DMY_ALLOW_FUN_WRITE
TARGET___NAME__CFLAGS += -DMY_ALLOW_FUN_READ
TARGET___NAME__CFLAGS += -DMY_ALLOW_FUN_OPEN
TARGET___NAME__CFLAGS += -DMY_ALLOW_FUN_CLOSE
TARGET___NAME__CFLAGS += -DMY_ALLOW_FUN_RAND
TARGET___NAME__CFLAGS += -DMY_ALLOW_FUN_RAND_R
TARGET___NAME__CFLAGS += -DMY_ALLOW_FUN_SRAND
TARGET___NAME__CFLAGS += -DMY_ALLOW_FUN_TIME

$(TARGET___NAME__OBJS): %.o: %.c
	$(CC) $(CFLAGS) $(TARGET___NAME__CFLAGS) -c -o $@ $<

$(TARGET___NAME_): $(TARGET___NAME__OBJS)
	$(AR) rc $@ $^

clean::
	rm -f $(TARGET___NAME__OBJS)

fclean::
	rm -f $(TARGET___NAME__OBJS)
	rm -f $(TARGET___NAME_)

# target tests.out
TARGET_TESTS_OUT := tests.out
TARGET_TESTS_OUT_SRCS := $(shell find -path './tests/*.c')
TARGET_TESTS_OUT_OBJS := $(TARGET_TESTS_OUT_SRCS:.c=.o)
TARGET_TESTS_OUT_CFLAGS := -I./include
TARGET_TESTS_OUT_LFLAGS := -lcriterion

$(TARGET_TESTS_OUT_OBJS): %.o: %.c
	$(CC) $(CFLAGS) $(TARGET_TESTS_OUT_CFLAGS) -c -o $@ $<

$(TARGET_TESTS_OUT): $(NAME)
$(TARGET_TESTS_OUT): $(TARGET_TESTS_OUT_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(TARGET_TESTS_OUT_LFLAGS)

clean::
	rm -f $(TARGET_TESTS_OUT_OBJS)

fclean::
	rm -f $(TARGET_TESTS_OUT_OBJS)
	rm -f $(TARGET_TESTS_OUT)

# action tests_run
tests_run: tests.out
	./tests.out $(ARGS)
.PHONY: tests_run
