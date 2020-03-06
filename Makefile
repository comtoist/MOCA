CC=wllvm
SRC_DIR=src
OBJ_DIR=obj
BIN_DIR=bin
SRC= $(wildcard $(SRC_DIR)/*.c)
OBJS=$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
CFLAGS=-Wall -g
CPPFLAGS=-Iinclude 
ARCHIVE=librairie/lib
#LDFLAGS=-Llibrairie/lib
EXEC=appli-dico


$(BIN_DIR)/$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@  

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ 

$(ARCHIVE)/libmaillon.a  : $(OBJ_DIR)/maillon.o
	ar r $(ARCHIVE)/libmaillon.a $(OBJ_DIR)/maillon.o

$(ARCHIVE)/libCuTest.a  : $(OBJ_DIR)/CuTest.o
	ar r $(ARCHIVE)/libCuTest.a $(OBJ_DIR)/CuTest.o

$(ARCHIVE)/libmaillon.so  :
	$(CC) -fPIC -c $(SRC_DIR)/maillon.c $(CPPFLAGS) -o $(OBJ_DIR)/maillon.o
	$(CC) -shared -o $@ $(OBJ_DIR)/maillon.o

clean:
	-rm $(OBJ_DIR)/*.o $(BIN_DIR)/$(EXEC) $(OBJ_DIR)/*.gcno
