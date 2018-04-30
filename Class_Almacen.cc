#include "Class_Almacen.hh"
#include "BinTreeIO.hh"

Almacen::Almacen() {
    tree = BinTree<int>();
    almacen = vector<Estanteria>();
}

Almacen::~Almacen() {}

string Almacen::consultar_pos(int sala, int fila, int columna) const {
    return almacen[sala].consultar_pos(fila, columna);
}

int Almacen::consultar_filas(int sala) const {
	return almacen[sala].consultar_filas();
}

int Almacen::consultar_columnas(int sala) const {
	return almacen[sala].consultar_columnas();
}

int Almacen::consultar_vacias(int sala) const {
	return almacen[sala].consultar_vacias();
}

int Almacen::poner_items(int sala, const string& id, int quantitat, Inventario& inv) {
    return almacen[sala].poner_items(id, quantitat, inv);
}

int Almacen::quitar_items(int sala, const string& id, int quantitat, Inventario& inv) {
    return almacen[sala].quitar_items(id, quantitat, inv);
}

int Almacen::distribuir(const string& id, int quantitat, Inventario& inv) {
    return 0;
    //TO DO
}

void Almacen::compactar(int sala) {
    almacen[sala].compactar();
}

void Almacen::reorganizar(int sala) {
    almacen[sala].reorganizar();
}

void Almacen::redimensionar(int sala, int filas, int columnas) {
    almacen[sala].redimensionar(filas, columnas);
}

void Almacen::leer(int n) {
    llegir_preordre(tree);
    for (int i = 0; i < n; i++) {
        int f, c;
        cin >> f >> c;
        almacen[i] = Estanteria(f, c);
    }
}

void Almacen::escribir(int sala) const {
    almacen[sala].escribir();
}
