SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
CXX = g++
CPPFLAGS = -Wall -g -I$(INC) -c

# ************ Documentacion ******************
documentacion:
	doxygen Doxyfile


# ************ Compilación ************

pila_max_cola: $(BIN)/usopilas_max_cola

$(BIN)/usopilas_max_cola: $(OBJ)/usopilas_max_cola.o $(LIB)/libpilamaxCola.a
	$(CXX) -o $@ $< -lpilamaxCola -L$(LIB)

$(OBJ)/usopilas_max_cola.o: $(SRC)/usopilas_max.cpp  $(INC)/pila_max_cola.h $(INC)/cola.h
	$(CXX) $(CPPFLAGS) $< -o $@

$(LIB)/libpilamaxCola.a: $(OBJ)/pila_max_cola.o $(OBJ)/cola.o
	ar -rvs $@ $^

$(OBJ)/pila_max_cola.o: $(SRC)/pila_max_cola.cpp $(INC)/pila_max_cola.h $(INC)/cola.h $(SRC)/cola.cpp
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/cola.o: $(INC)/cola.h $(SRC)/cola.cpp
	$(CXX) $(CPPFLAGS) $< -o $@



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
