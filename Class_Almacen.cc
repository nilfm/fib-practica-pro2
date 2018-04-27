#include "ClassAlmacen.hh"

Almacen::Almacen() {
    tree = BinTree<int>();
    almacen = vector<Estanteria>;
}

Almacen::~Almacen() {}

string Almacen::consultar_pos(int sala, int fila, int columna) const {
    return almacen[sala].consultar_pos(fila, columna);
}

int Almacen::poner_items(int sala, const string& id, int quantitat, Inventario& inv) {
    return almacen[sala].poner_items(id, quantitat, inv);
}

int Almacen::quitar_items(int sala, const string& id, int quantitat, Inventario& inv) {
    return almacen[sala].quitar_items(id, quantitat, inv);
}

int Almacen::distribuir(const string& id, int quantitat, Inventario& inv) {
    //TO DO
}

void Almacen::compactar(int sala) {
    almacen[sala].compactar();
}

void Almacen::reorganizar(int sala) {
    almacen[sala].reorganizar();
}

void Almacen::redimensionar(int sala, int filas, int columnas) {
    almacen[sala].redimensionar();
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
