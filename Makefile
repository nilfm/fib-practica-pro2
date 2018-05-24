CC = g++-5
OPTIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11
EXEC = program.exe
OBJECTS = program.o Class_Almacen.o Class_Estanteria.o Class_Inventario.o
CODE = program.cc Class_Almacen.cc Class_Estanteria.cc Class_Inventario.cc
HEADERS = Class_Almacen.hh Class_Estanteria.hh Class_Inventario.hh

program.exe: $(OBJECTS) $(HEADERS)
	$(CC) -o $(EXEC) $(OPTIONS) $(OBJECTS) 

program.o: program.cc $(HEADERS)
	$(CC) -c  $(OPTIONS) program.cc

Class_Almacen.o: Class_Almacen.cc $(HEADERS)
	$(CC) -c $(OPTIONS) Class_Almacen.cc

Class_Estanteria.o: Class_Estanteria.cc Class_Estanteria.hh Class_Inventario.hh
	$(CC) -c $(OPTIONS) Class_Estanteria.cc

Class_Inventario.o: Class_Inventario.cc Class_Inventario.hh 
	$(CC) -c $(OPTIONS) Class_Inventario.cc

practica.tar: $(CODE) $(HEADERS) Makefile Doxyfile html html.zip
	tar -cvf practica.tar $(CODE) $(HEADERS) Makefile html.zip

html.zip: Doxyfile html $(CODE) $(HEADERS)
	doxygen Doxyfile
	zip -r html.zip html

clean:
	rm *.o
	rm *.exe
