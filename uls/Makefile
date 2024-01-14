CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

INCD = inc
SRCD = src
OBJD = obj

LIBD = libmx
LIBMX = libmx.a
ULS = uls

INC := -I$(INCD) -I$(LIBD)/inc
SRC := $(wildcard $(SRCD)/*.c) $(wildcard $(SRCD)/**/*.c)
OBJ := $(patsubst $(SRCD)/%.c, $(OBJD)/%.o, $(SRC))
LINK := -L$(LIBD) -lmx

.PHONY: all uninstall clean reinstall install

all: install

install: $(LIBMX) $(ULS)
	@printf "\r\033[K$(ULS) $@ done\n"

$(OBJ): $(OBJD)/%.o: $(SRCD)/%.c
	@mkdir -p $(dir $@)
	@printf "\r\033[K$(ULS) compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(LIBMX):
	@$(MAKE) -sC $(LIBD) install

$(ULS): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^ $(INC) $(LINK)

uninstall:
	@$(MAKE) -sC $(LIBD) uninstall
	@rm -rf $(OBJD)
	@rm -rf $(ULS)
	@printf "\r\033[K$(ULS) uninstalled\n"

clean:
	@$(MAKE) -sC $(LIBD) clean
	@rm -rf $(OBJD)
	@printf "\r\033[K$(OBJD) in $(ULS) cleaned\n"

reinstall: uninstall install

