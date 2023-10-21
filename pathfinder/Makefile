CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -g

INCD = inc
SRCD = src
OBJD = obj

LIBD = libmx
LIBMX = libmx.a
PATHFINDER = pathfinder

INC := -I$(INCD) -I$(LIBD)/inc
SRC := $(wildcard $(SRCD)/*.c) $(wildcard $(SRCD)/**/*.c)
OBJ := $(patsubst $(SRCD)/%.c, $(OBJD)/%.o, $(SRC))
LINK := -L$(LIBD) -lmx

.PHONY: all uninstall clean reinstall install

all: install

install: $(LIBMX) $(PATHFINDER)
	@printf "\r\033[K$(PATHFINDER) $@ done\n"

$(OBJ): $(OBJD)/%.o: $(SRCD)/%.c
	@mkdir -p $(dir $@)
	@printf "\r\033[K$(PATHFINDER) compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(LIBMX):
	@$(MAKE) -sC $(LIBD) install

$(PATHFINDER): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^ $(INC) $(LINK)

uninstall:
	@$(MAKE) -sC $(LIBD) uninstall
	@rm -rf $(OBJD)
	@rm -rf $(PATHFINDER)
	@printf "\r\033[K$(PATHFINDER) uninstalled\n"

clean:
	@$(MAKE) -sC $(LIBD) clean
	@rm -rf $(OBJD)
	@printf "\r\033[K$(OBJD) in $(PATHFINDER) cleaned\n"

reinstall: uninstall install

