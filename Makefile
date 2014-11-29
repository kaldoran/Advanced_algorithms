# Release/Debug
DEBUG=yes

# Directories
SRC_DIR = SRC
INC_DIR = INC
OBJ_DIR = OBJ
BIN_DIR = BIN

CC = gcc
CFLAGS = -W -Wall -Wextra -O2 -lm
BIN = main

ifeq ($(DEBUG), yes) 
	CFLAGS += -g -DDEBUG
endif

SRC = $(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.c))
OBJ = $(addsuffix .o, $(basename $(subst ${SRC_DIR}, ${OBJ_DIR}, ${SRC})))


.PHONY: clear dir
.SUFFIXES:

all: clear dir $(BIN_DIR)/$(BIN)

#
# BIN creation.
#

$(BIN_DIR)/$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $@ -I $(INC_DIR) $(CFLAGS)
	@echo "./"$(BIN_DIR)"/"$(BIN)" well created !"
        
#
# Object files creation.
#

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $^ -o $@ -I $(INC_DIR) $(CFLAGS)

#
# Other usefull targets.
#

clean:
	rm -f ./$(OBJ_DIR)/*.o ./$(BIN_DIR)/$(BIN);
	rm -rf ./$(OBJ_DIR);
	rm -rf ./$(BIN_DIR);


rebuild: clean all

#
# Screen cleaning.
#

clear:
	clear
#
# Repository creation.
#

dir:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)
