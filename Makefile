CC=gcc
SRC_DIR=src
OBJ_DIR=obj
BIN_DIR=bin
SRC= $(wildcard $(SRC_DIR)/*.c)
OBJS=$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
CFLAGS=-Wall
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

$(ARCHIVE)/libmaillon.so  :
	$(CC) -fPIC -c $(SRC_DIR)/maillon.c $(CPPFLAGS) -o $(OBJ_DIR)/maillon.o
	$(CC) -shared -o $@ $(OBJ_DIR)/maillon.o

clean:
	-rm $(OBJ_DIR)/*.o $(BIN_DIR)/$(EXEC)
