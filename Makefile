##
## EPITECH PROJECT, 2019
## libmy
## File description:
## Makefile to build libmy
##

CC		?=	gcc

AR		?=	ar

SHELL	?=	/bin/sh

MYFILE	?=	Myfile.yml

readcfg	=	$(strip \
				$(shell sed -n '/^$(1):/,/^\S/s/^\s\+\-\|^$(1)://p' $(MYFILE)))

ALLOWED ?=	$(call readcfg,allowed)

SRC		:=	$(call readcfg,src)

NAME	:=	$(call readcfg,name)

NAMESPC :=	$(call readcfg,namespace)

TESTSRC	:=	$(call readcfg,tests_src)

TEST	=	unit-tests

OUTDIR	=	./target/$(if $(DEBUG),debug,release)

OUTNAME	=	$(OUTDIR)/$(notdir $(NAME))

OUTTEST	=	$(OUTDIR)/$(TEST)

CPPDEPS	=	$(SRC:%.c=$(OUTDIR)/%.d)

OBJ		=	$(SRC:%.c=$(OUTDIR)/%.o)

TESTOBJ	=	$(TESTSRC:%.c=$(OUTDIR)/%.o)

COVREPS	=	$(SRC:%.c=$(OUTDIR)/%.gcda) $(SRC:%.c=$(OUTDIR)/%.gcno) \
			$(TESTSRC:%.c=$(OUTDIR)/%.gcda) $(TESTSRC:%.c=$(OUTDIR)/%.gcno)

INCLUDE =	-I$(OUTDIR)/include

CFLAGS	:=	-fdiagnostics-color -fno-builtin -W -Wall -Wextra -pedantic \
			$(INCLUDE) $(if $(DEBUG),-g3) $(if $(COVERAGE),--coverage) \
			$(patsubst %,-DMY_ALLOW_FUN_%,$(strip \
				$(shell echo $(ALLOWED) | tr a-z A-Z)))

CPPFLAGS =	-MD -MP

all: $(NAME)

info:
	@echo "\033[0;32mname:\033[0m" $(NAME)
	@echo -n "\033[0;32mallowed:\033[0m"
	@for fn in $(ALLOWED); do echo -n " $$fn"; done
	@echo
	@echo "\033[0;32msrc:\033[0m" $(shell echo $(SRC) | wc -w) 'file(s)'
	@echo "\033[0;32mtests:\033[0m" $(shell echo $(TESTSRC) | wc -w) 'file(s)'
	@echo "\033[0;32mobj:\033[0m"
	@for obj in $(OBJ); do echo -n " $$obj"; done
	@echo

$(NAME): $(OUTNAME)
	@cp $< $@

$(OUTNAME): $(OBJ)
	@$(AR) -rc $@ $(OBJ)
	@printf '\r  \033[K\033[0;32m Finished\033[0m `%s`\n' "$@"

$(OUTDIR)/%.o: %.c | $(OUTDIR)
	@printf '\r  \033[K\033[0;32mCompiling\033[0m `$<`\n'
	@mkdir -p $(dir $@)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OUTDIR): $(abspath ./include)
	@mkdir -p $@/include
	@ln -Tfs $(abspath ./include) $@/include/$(NAMESPC)

$(TEST): $(OUTTEST)
	@cp $(OUTTEST) $(TEST)

$(OUTTEST): $(OBJ) $(TESTOBJ)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(TESTOBJ) -lcriterion
	@printf '\r  \033[K\033[0;32m Finished\033[0m %s test build\n' \
		$(if $(DEBUG),'debug','release')

run: $(NAME)
	@printf '\r  \033[K\033[0;32m  Running\033[0m `$(strip $(NAME) $(ARGS))`\n'
	@./$(NAME) $(ARGS)

tests_run: $(TEST)
	@printf '\r  \033[K\033[0;32m  Running\033[0m `$(TEST)`\n'
	@./$(TEST) $(ARGS)

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

.PHONY: all info run tests_run clean fclean re retest rerun

-include $(CPPDEPS)
