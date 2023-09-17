SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
TARGET = libmx.a

$(TARGET): $(OBJ_FILES)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c -o $@ $<

all: $(TARGET)

clean:
	rm -f $(OBJ_DIR)/*.o

fclean: clean
	rm -f $(TARGET)
	rm -rf $(OBJ_DIR)

complile: fclean all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_FILES): | $(OBJ_DIR)
