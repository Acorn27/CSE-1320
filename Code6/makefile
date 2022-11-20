# Mai Tran 
# 1002092849
# UTA Coding Assignment 6

SRC1 = Code6_1002092849.c
SRC2 = DrawTool.c
SRC3 = ListLib.c
SRC4 = FileLib.c

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)
OBJ3 = $(SRC2:.c=.o)
OBJ4 = $(SRC2:.c=.o)

EXE = $(SRC1:.c=.e)

CFLAGS = -g

all : $(EXE)
 
$(EXE): $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4)
	gcc $(CFLAGS) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) -o $(EXE) 

$(OBJ1) : $(SRC1)
	gcc -c $(CFLAGS) $(SRC1)

$(OBJ2) : $(SRC2)
	gcc -c $(CFLAGS) $(SRC2)

$(OBJ3) : $(SRC3)
	gcc -c $(CFLAGS) $(SRC3)

$(OBJ4) : $(SRC4)
	gcc -c $(CFLAGS) $(SRC4)