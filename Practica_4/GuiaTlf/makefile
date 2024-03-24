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
# ./usodiccionario < data.txt 

all: $(BIN)/usoguia
	./$(BIN)/usoguia ./$(DATOS)/guia.txt

$(BIN)/usoguia: $(OBJ)/usoguia.o
	$(CXX) -o $(BIN)/usoguia $(OBJ)/usoguia.o

$(OBJ)/usoguia.o: $(SRC)/usoguia.cpp
	$(CXX) $(CXXFLAGS) -o  $(OBJ)/usoguia.o $(SRC)/usoguia.cpp




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