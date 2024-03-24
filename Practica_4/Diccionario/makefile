INC = include
OBJ = obj
SRC = src
BIN = bin
LIB = lib
DATOS = datos
CXX = g++
CPPFLAGS = -Wall -g -std=c++11
CXXFLAGS = -c -I./$(INC)



# ************ Documentacion ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación ************

all: diccionario
	./$(BIN)/usodiccionario ./$(DATOS)/data.txt

diccionario: $(BIN)/usodiccionario

$(BIN)/usodiccionario: $(OBJ)/usodiccionario.o $(LIB)/libdiccionario.a
	$(CXX) -o $@ $< -ldiccionario -L./$(LIB)

$(LIB)/libdiccionario.a: $(OBJ)/diccionario.o
	ar -rvs $@ $^

$(OBJ)/usodiccionario.o: $(SRC)/usodiccionario.cpp $(INC)/diccionario.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@

$(OBJ)/diccionario.o: $(SRC)/diccionario.cpp $(INC)/diccionario.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@




# ************ Limpieza ************
clean :
	@echo "Limpiando..."
	@rm -f $(OBJ)/*
	@rm -f $(BIN)/* 
	@rm -f $(LIB)/*
	@rm -rf $(DOC)
	@echo "Archivos borrados con exito"

mrproper: clean
	-rm -r doc/html doc/latex doc/man doc/xml

autor:
	@echo "Torres Ramos, Juan Luis"