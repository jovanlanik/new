# New
# Copyright (c) 2020 Jovan Lanik

# Makefile

NAME := new

CFLAGS += -std=c11

SRC = source.c
OBJ = $(SRC:%.c=%.o)

TRASH = $(OBJ) $(NAME)

.PHONY: all clean

all: $(NAME)
clean:
	@rm $(TRASH) | true
$(NAME): $(OBJ)
	$(LINK.c) $^ $(LDLIBS) -o $@
