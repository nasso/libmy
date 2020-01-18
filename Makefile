##
## EPITECH PROJECT, 2019
## libmy
## File description:
## Makefile to build libmy
##

CC		?=	gcc

SHELL	?=	/bin/sh

readcfg	=	$(strip $(shell sed -n '/^$(1):/,/^\S/s/^\s\+\-//p' Myfile.yml))

ALLOWED ?=	$(call readcfg,allowed)

SRC		:=	$(call readcfg,src)

NAME	:=	$(call readcfg,name)

TESTSRC	:=	$(call readcfg,tests_src)

INCLUDE =	-I./include -I./lib/include

CFLAGS	:=	-fdiagnostics-color -fno-builtin -W -Wall -Wextra -pedantic \
			$(INCLUDE) $(if $(DEBUG),-g3) \
			$(patsubst %,-DMY_ALLOW_FUN_%,$(strip \
				$(shell echo $(ALLOWED) | tr a-z A-Z)))

CPPFLAGS =	-MD -MP

TEST	=	unit-tests

OUTDIR	=	./target/$(if $(DEBUG),debug,release)

OUTNAME	=	$(OUTDIR)/$(notdir $(NAME))

OUTTEST	=	$(OUTDIR)/$(TEST)

CPPDEPS	=	$(SRC:%.c=$(OUTDIR)/%.d)

OBJ		=	$(SRC:%.c=$(OUTDIR)/%.o)

TESTOBJ	=	$(TESTSRC:%.c=$(OUTDIR)/%.o)

COVREPS	=	$(SRC:%.c=$(OUTDIR)/%.gcda) $(SRC:.c=$(OUTDIR)/%.gcno) \
			$(TESTSRC:.c=$(OUTDIR)/%.gcda) $(TESTSRC:.c=$(OUTDIR)/%.gcno)

all: $(NAME)

$(NAME): $(OUTNAME)
	@cp $< $@

$(OUTNAME): $(OBJ)
	@ar -rc $@ $(OBJ)
	@printf '\r  \033[K\033[0;32m Finished\033[0m `%s`\n' "$@"

$(OUTDIR)/%.o: %.c
	@printf '\r  \033[K\033[0;32mCompiling\033[0m `$<`\n'
	@mkdir -p $(dir $@)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(TEST): $(OUTTEST)
	@cp $(OUTTEST) $(TEST)

$(OUTTEST): $(OBJ:%main.o=) $(TESTOBJ)
	@$(CC) $(CFLAGS) --coverage -o $@ $(OBJ:%main.o=) $(TESTOBJ) -lcriterion
	@printf '\r  \033[K\033[0;32m Finished\033[0m %s test build\n' \
		$(if $(DEBUG),'debug','release')

run: $(NAME)
	@printf '\r  \033[K\033[0;32m  Running\033[0m `$(strip $(NAME) $(ARGS))`\n'
	@./$(NAME) $(ARGS)

tests_run: $(TEST)
	@printf '\r  \033[K\033[0;32m  Running\033[0m `$(TEST)`\n'
	@./$(TEST)

clean:
	@printf '\r  \033[K\033[0;34m Cleaning\033[0m `$(NAME)`\n'
	@rm -f $(OBJ) $(TESTOBJ) $(COVREPS) $(CPPDEPS) $(OUTNAME) $(OUTTEST)

fclean:
	@printf '\r  \033[K\033[0;36m   Wiping\033[0m `$(NAME)`\n'
	@rm -f $(OBJ) $(TESTOBJ) $(COVREPS) $(CPPDEPS) $(OUTNAME) $(OUTTEST)
	@rm -f $(NAME) $(TEST)
	@rm -rf $(OUTDIR)

re: fclean all

retest: fclean tests_run

rerun: re run

.PHONY: all run tests_run clean fclean re retest rerun

-include $(CPPDEPS)
