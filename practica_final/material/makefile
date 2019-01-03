SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -std=c++11 -Wall -g  -I$(INC) -c -O2


all: $(BIN)/testlista_palabras $(BIN)/letras $(BIN)/cantidad_letras
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************


$(BIN)/testlista_palabras : $(OBJ)/testlista_palabras.o $(OBJ)/lista_palabras.o

	$(CXX) $(OBJ)/testlista_palabras.o $(OBJ)/lista_palabras.o -o $(BIN)/testlista_palabras


$(BIN)/letras : $(OBJ)/letras.o $(OBJ)/lista_palabras.o $(OBJ)/bolsa_letras.o \
                $(OBJ)/conjunto_letras.o $(OBJ)/letra.o
	$(CXX) $(OBJ)/letras.o $(OBJ)/lista_palabras.o $(OBJ)/bolsa_letras.o \
	       $(OBJ)/conjunto_letras.o $(OBJ)/letra.o -o $(BIN)/letras


$(BIN)/cantidad_letras : $(OBJ)/cantidad_letras.o $(OBJ)/lista_palabras.o $(OBJ)/conjunto_letras.o $(OBJ)/letra.o

	$(CXX) $(OBJ)/cantidad_letras.o $(OBJ)/lista_palabras.o $(OBJ)/conjunto_letras.o $(OBJ)/letra.o -o $(BIN)/cantidad_letras





$(OBJ)/letra.o : $(SRC)/letra.cpp $(INC)/letra.h
	$(CXX) $(CPPFLAGS) $(SRC)/letra.cpp -o $(OBJ)/letra.o

$(OBJ)/conjunto_letras.o : $(SRC)/conjunto_letras.cpp $(INC)/conjunto_letras.h $(INC)/letra.h $(INC)/bolsa_letras.h $(INC)/lista_palabras.h
	$(CXX) $(CPPFLAGS) $(SRC)/conjunto_letras.cpp -o $(OBJ)/conjunto_letras.o

$(OBJ)/lista_palabras.o : $(SRC)/lista_palabras.cpp $(INC)/lista_palabras.h
	$(CXX) $(CPPFLAGS) $(SRC)/lista_palabras.cpp -o $(OBJ)/lista_palabras.o

$(OBJ)/bolsa_letras.o : $(SRC)/bolsa_letras.cpp $(INC)/bolsa_letras.h $(INC)/conjunto_letras.h $(INC)/letra.h
	$(CXX) $(CPPFLAGS) $(SRC)/bolsa_letras.cpp -o $(OBJ)/bolsa_letras.o




$(OBJ)/testlista_palabras.o : $(SRC)/testlista_palabras.cpp $(INC)/lista_palabras.h
	$(CXX) $(CPPFLAGS) $(SRC)/testlista_palabras.cpp -o $(OBJ)/testlista_palabras.o

$(OBJ)/letras.o : $(SRC)/letras.cpp $(INC)/lista_palabras.h $(INC)/bolsa_letras.h $(INC)/conjunto_letras.h
	$(CXX) $(CPPFLAGS) $(SRC)/letras.cpp -o $(OBJ)/letras.o

$(OBJ)/cantidad_letras.o : $(SRC)/cantidad_letras.cpp $(INC)/lista_palabras.h $(INC)/conjunto_letras.h $(INC)/letra.h
	$(CXX) $(CPPFLAGS) $(SRC)/cantidad_letras.cpp -o $(OBJ)/cantidad_letras.o


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*


