SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/testlista_palabras
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************


$(BIN)/testlista_palabras : $(OBJ)/testlista_palabras.o $(OBJ)/lista_palabras.o

	$(CXX) $(OBJ)/testlista_palabras.o $(OBJ)/lista_palabras.o -o $(BIN)/testlista_palabras


$(OBJ)/letra.o : $(SRC)/letra.cpp $(INC)/letra.h
	$(CXX) $(CPPFLAGS) $(SRC)/letra.cpp -o $(OBJ)/letra.o

$(OBJ)/conjunto_letras.o : $(SRC)/conjunto_letras.cpp $(INC)/conjunto_letras.h
	$(CXX) $(CPPFLAGS) $(SRC)/conjunto_letras.cpp -o $(OBJ)/conjunto_letras.o

$(OBJ)/lista_palabras.o : $(SRC)/lista_palabras.cpp $(INC)/lista_palabras.h
	$(CXX) $(CPPFLAGS) $(SRC)/lista_palabras.cpp -o $(OBJ)/lista_palabras.o



$(OBJ)/testlista_palabras.o : $(SRC)/testlista_palabras.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/testlista_palabras.cpp -o $(OBJ)/testlista_palabras.o

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*


