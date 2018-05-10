CC = g++-5
OPTIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11
EXEC = program.exe
OBJECTS = program.o Class_Almacen.o Class_Estanteria.o Class_Inventario.o
CODE = program.cc Class_Almacen.cc Class_Estanteria.cc Class_Inventario.cc
HEADERS = Class_Almacen.hh Class_Estanteria.hh Class_Inventario.hh

program.exe: $(OBJECTS)
	$(CC) -o $(EXEC) $(OPTIONS) $(OBJECTS) 

program.o: program.cc Class_Almacen.hh Class_Inventario.hh
	$(CC) -c  $(OPTIONS) program.cc

Class_Almacen.o: Class_Almacen.cc Class_Almacen.hh Class_Estanteria.hh BinTree.hh
	$(CC) -c $(OPTIONS) Class_Almacen.cc

Class_Estanteria.o: Class_Estanteria.cc Class_Estanteria.hh 
	$(CC) -c $(OPTIONS) Class_Estanteria.cc

Class_Inventario.o: Class_Inventario.cc Class_Inventario.hh 
	$(CC) -c $(OPTIONS) Class_Inventario.cc

tar: $(CODE) $(HEADERS) Makefile
	tar -cvf practica.tar $(CODE) $(HEADERS) Makefile

clean:
	rm *.o
	rm *.exe
