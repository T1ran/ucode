CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

INCD = inc
SRCD = src
OBJD = obj

LIBMX = libmx.a

INC := -I$(INCD)
SRC := $(wildcard $(SRCD)/*.c)
OBJ := $(patsubst $(SRCD)/%.c, $(OBJD)/%.o, $(SRC))

.PHONY: all install uninstall clean reinstall

all: install

install: $(LIBMX)
	@printf "\033[K$(LIBMX) $@ done \n \r"

$(OBJ): $(OBJD)/%.o: $(SRCD)/%.c
	@mkdir -p $(dir $@)
	@printf "\033[K$(LIBMX) compiling $<\r"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(LIBMX): $(OBJ)
	@ar rcs $(LIBMX) $(OBJ)
	@printf "$@ created \r"

uninstall:
	@rm -rf $(OBJD)
	@rm -rf $(LIBMX)
	@printf "$(LIBMX) uninstalled\n"

clean:
	@rm -rf $(OBJD)
	@printf "$(OBJD) in $(LIBMX) cleaned\n"

reinstall: uninstall install
