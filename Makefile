NAME = mouli
CC = gcc
CFLAGS = -std=gnu23 -Wall -Wextra
SRC = $(wildcard src/*.c)
OBJ_DIR = obj
OBJ = $(patsubst src/%.c, $(OBJ_DIR)/%.o, $(SRC))

default: all clean

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< 

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

.PHONY: default all clean fclean re
