SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
CXX = g++
CPPFLAGS = -Wall -g -I$(INC) -c


# ************ Documentacion ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación ************

cola_max_pila: $(BIN)/usocola_max_pila

$(BIN)/usocola_max_pila: $(OBJ)/usocola_max_pila.o $(LIB)/libcolamaxPila.a
	$(CXX) -o $@ $< -lcolamaxPila -L$(LIB)

$(OBJ)/usocola_max_pila.o: $(SRC)/usocolas_max.cpp  $(INC)/Cola_max_Pila.h $(INC)/pila.h
	$(CXX) $(CPPFLAGS) $< -o $@

$(LIB)/libcolamaxPila.a: $(OBJ)/Cola_max_Pila.o $(OBJ)/pila.o
	ar -rvs $@ $^

$(OBJ)/Cola_max_Pila.o: $(SRC)/Cola_max_Pila.cpp $(INC)/Cola_max_Pila.h $(INC)/pila.h $(SRC)/pila.cpp
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/pila.o: $(INC)/pila.h $(SRC)/pila.cpp
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
