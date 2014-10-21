# Release/Debug
DEBUG=no

# Directories
SRC_DIR = SRC
INC_DIR = INC
OBJ_DIR = OBJ
BIN_DIR = BIN


BIN = main

SRC = $(foreach dir, $(SRC_REP), $(wildcard $(dir)/*.c))
OBJ = $(addsuffix .o, $(basename $(subst ${SRC_REP}, ${OBJ_REP}, ${SRC})))


.PHONY: clean mrproper clear dir
.SUFFIXES:



all: clear dir $(BIN_REP)/$(BIN)


#
# BIN creation.
#


$(BIN_REP)/$(BIN): $(OBJ)
    $(CC) $(OBJ) -o $@ -I $(INC_REP) $(CFLAGS)
    @echo "./bin/"$(BIN)" well created !"
    
    
#
# Object files creation.
#

$(OBJ_REP)/%.o: $(SRC_REP)/%.c
    $(CC) -c $^ -o $@ -I $(INC_REP) $(CFLAGS)
    
#
# Other usefull targets.
#

clean:
    rm -f ./$(OBJ_REP)/*.o;
    rm -f output


rebuild: mrproper clear all

#
# Screen cleaning.
#

clear:
    clear
#
# Repository creation.
#

dir:
    @mkdir -p $(OBJ_REP)
    @mkdir -p $(BIN_REP)