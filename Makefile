##
## EPITECH PROJECT, 2019
## libmy
## File description:
## Makefile to build libmy
##

CC		=	gcc

SHELL	=	/bin/sh

INCLUDE =	-I./include -I./lib/include

CFLAGS	=	-fdiagnostics-color -fno-builtin -W -Wall -Wextra -pedantic \
			$(INCLUDE) $(if $(DEBUG),-g3)

CPPFLAGS =	-MD -MP

SRC		=	./src/cstr/cstr_getnbr_base.c \
			./src/cstr/cstr_getnbr.c \
			./src/cstr/cstrrev.c \
			./src/cstr/cstr_isalpha.c \
			./src/cstr/cstr_islower.c \
			./src/cstr/cstr_isnum.c \
			./src/cstr/cstr_isprintable.c \
			./src/cstr/cstr_isupper.c \
			./src/cstr/cstrcapitalize.c \
			./src/cstr/cstrcat.c \
			./src/cstr/cstrchr_mut.c \
			./src/cstr/cstrchr.c \
			./src/cstr/cstrcmp.c \
			./src/cstr/cstrcpy.c \
			./src/cstr/cstrlen.c \
			./src/cstr/cstrlowcase.c \
			./src/cstr/cstrncat.c \
			./src/cstr/cstrncmp.c \
			./src/cstr/cstrncpy.c \
			./src/cstr/cstrstr.c \
			./src/cstr/cstrupcase.c \
			./src/fmt/format.c \
			./src/io/priv/converter_fn_c.c \
			./src/io/priv/converter_fn_d.c \
			./src/io/priv/converter_fn_p.c \
			./src/io/priv/converter_fn_pc.c \
			./src/io/priv/converter_fn_s.c \
			./src/io/priv/converter_fn_u.c \
			./src/io/priv/converter_new.c \
			./src/io/priv/converter.c \
			./src/io/printf.c \
			./src/io/putchar.c \
			./src/io/putcstr.c \
			./src/io/vbufprintf.c \
			./src/mem/memshow.c \
			./src/stream/bufreader.c \
			./src/stream/bufwriter.c \
			./src/stream/filereader.c \
			./src/stream/filewriter.c \

NAME	=	libmy.a

TESTSRC	=	./tests/cstr_getnbr_base.c \
			./tests/cstr_isalpha.c \
			./tests/cstr_islower.c \
			./tests/cstr_isprintable.c \
			./tests/cstrcapitalize.c \
			./tests/cstrcat.c \
			./tests/cstrncat.c \
			./tests/cstrncmp.c \
			./tests/cstrncpy.c \
			./tests/cstrrev.c \
			./tests/cstrstr.c \
			./tests/format.c \
			./tests/memshow.c \

TEST	=	unit-tests

OUTDIR	=	./target/$(if $(DEBUG),debug,release)

OUTNAME	=	$(OUTDIR)/$(NAME)

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
