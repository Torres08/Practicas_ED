

##-----------------------------------------------------------------------------
#

all: intro subimagen zoom contraste outro

intro:
	@echo Creando archivos...

outro:
	@echo Hecho.



##-----------------------------------------------------------------------------
#	DOXY

doxy:
	doxygen doxyfile


##-----------------------------------------------------------------------------
#	BIN

subimagen: subimagen.o imagen.o
	g++ subimagen.o imagen.o -o subimagen

zoom: zoom.o imagen.o
	g++ zoom.o imagen.o -o zoom

contraste: contraste.o imagen.o
	g++ contraste.o imagen.o -o contraste



##-----------------------------------------------------------------------------
#	OBJ

imagen.o: imagen.cpp imagen.h
	g++ -g -c -I. imagen.cpp -o imagen.o

subimagen.o: subimagen.cpp
	g++ -g -c -I. subimagen.cpp -o subimagen.o

zoom.o: zoom.cpp
	g++ -g -c -I. zoom.cpp -o zoom.o

contraste.o: contraste.cpp
	g++ -g -c -I. contraste.cpp -o contraste.o



##-----------------------------------------------------------------------------
#	LIMPIEZA

mr.proper: clean-bin clean-obj clean-doxy

clean-doxy:
	rm -f -r doc

clean-bin:
	rm -f subimagen zoom contraste

clean-obj:
	rm -f imagen.o subimagen.o zoom.o contraste.o
