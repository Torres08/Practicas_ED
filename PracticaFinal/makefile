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

# *** Diccionario

all: $(BIN)/testdiccionario $(BIN)/testcantidad $(BIN)/letras

testdiccionario:
	./$(BIN)/testdiccionario ./$(DATOS)/diccionario1000.txt

testcantidad:
	./$(BIN)/testcantidad ./$(DATOS)/diccionario1.txt ./$(DATOS)/letras.txt ./$(DATOS)/salida.txt 

testletras:
	./$(BIN)/letras ./$(DATOS)/diccionario1.txt ./$(DATOS)/letras.txt 10 L



diccionario: $(BIN)/testdiccionario

$(BIN)/testdiccionario: $(OBJ)/usodiccionario.o $(LIB)/libdiccionario.a
	$(CXX) -o $@ $< -ldiccionario -L./$(LIB)

$(LIB)/libdiccionario.a: $(OBJ)/diccionario.o
	ar -rvs $@ $^

$(OBJ)/usodiccionario.o: $(SRC)/testdiccionario.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@

$(OBJ)/diccionario.o: $(SRC)/diccionario.cpp $(INC)/diccionario.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@

# *** cantidad letras

cantidad: $(BIN)/testcantidad

$(BIN)/testcantidad: $(OBJ)/usocantidadletras.o $(LIB)/libcantidad.a
	$(CXX) -o $@ $< -lcantidad -L./$(LIB)

$(OBJ)/usocantidadletras.o: $(SRC)/testcantidadletras.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@

$(LIB)/libcantidad.a: $(OBJ)/diccionario.o $(OBJ)/cantidadletras.o
	ar -rvs $@ $^

$(OBJ)/cantidadletras.o: $(SRC)/cantidadletras.cpp $(INC)/cantidadletras.h $(INC)/diccionario.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@



# *** letras

letras: $(BIN)/letras

$(BIN)/letras: $(SRC)/letras.cpp $(LIB)/libletras.a
	$(CXX) -o $@ $< -lletras -L./$(LIB)

$(LIB)/libletras.a: $(OBJ)/bolsaletras.o $(OBJ)/cantidadletras.o
	ar -rvs $@ $^

$(OBJ)/bolsaletras.o: $(SRC)/bolsaletras.cpp $(INC)/bolsaletras.h $(INC)/conjuntoletras.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@

$(OBJ)/cantidadletras.o: $(SRC)/cantidadletras.cpp $(INC)/cantidadletras.h $(INC)/diccionario.h
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