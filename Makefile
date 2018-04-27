CC = g++
OPTIONS = -std=c++11 -O2 -Wall -Wextra
EXEC = main.x
CODE = main.cc Class_Almacen.cc Class_Estanteria.cc Class_Inventario.cc BinTreeIO.cc

all:
	$(CC) -o $(EXEC) $(OPTIONS) $(CODE)

clean:
	rm *.o
