##
## EPITECH PROJECT, 2019
## libbignum
## File description:
## Makefile to build libraries
##

LIBS 	=	

define makelibs
	for lib in $(LIBS); do \
		$(MAKE) -C ./$$lib $(1) NAME=../$$lib.a; \
	done
endef

define cpheaders
	for lib in $(LIBS); do \
		name=$$(echo $$lib | sed -e 's/^lib//'); \
		mkdir -p ./include/$$name; \
		cp -rf ./$$lib/include/* ./include/$$name; \
	done
endef

all:
	$(call makelibs, all)
	$(call cpheaders)

clean:
	rm -rf ./include
	$(call makelibs, clean)

fclean: clean
	$(call makelibs, fclean)

.PHONY: all clean fclean
