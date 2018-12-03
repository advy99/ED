SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: documentacion $(BIN)/pruebadiccionario
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************
$(BIN)/pruebadiccionario: $(OBJ)/pruebadiccionario.o $(OBJ)/Diccionario.o $(OBJ)/Termino.o
	$(CXX) $(OBJ)/Diccionario.o $(OBJ)/Termino.o $(OBJ)/pruebadiccionario.o -o $(BIN)/pruebadiccionario

$(OBJ)/pruebadiccionario.o : $(SRC)/pruebadiccionario.cpp $(INC)/Diccionario.h
	$(CXX) $(CPPFLAGS) $(SRC)/pruebadiccionario.cpp -o $(OBJ)/pruebadiccionario.o

$(OBJ)/Diccionario.o : $(SRC)/Diccionario.cpp $(INC)/Diccionario.h $(INC)/Termino.h 
	$(CXX) $(CPPFLAGS) $(SRC)/Diccionario.cpp -o $(OBJ)/Diccionario.o

$(OBJ)/Termino.o : $(SRC)/Termino.cpp $(INC)/Termino.h 
	$(CXX) $(CPPFLAGS) $(SRC)/Termino.cpp -o $(OBJ)/Termino.o





# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
