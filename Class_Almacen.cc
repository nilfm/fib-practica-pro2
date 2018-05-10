#include "Class_Almacen.hh"

Almacen::Almacen() { }

Almacen::~Almacen() { }

int Almacen::i_distribuir(const string id, int quantitat, Inventario& inv, const BinTree<int>& t) {    
    if (not t.empty()) {
        int restantes = poner_items(t.value(), id, quantitat, inv);
        int r1 = i_distribuir(id, restantes - restantes/2, inv, t.left());
        int r2 = i_distribuir(id, restantes/2, inv, t.right());
        return r1 + r2;
    }
    else return quantitat;
}

void Almacen::leer_bintree(BinTree<int>& a) {
    int k;
    cin >> k;
    if (k != 0) {
        BinTree<int> left;
        BinTree<int> right;
        leer_bintree(left);
        leer_bintree(right);
        a = BinTree<int>(k, left, right);
    }
}

string Almacen::consultar_pos(int sala, int fila, int columna) const {
    return almacen[sala-1].consultar_pos(fila, columna);
}

int Almacen::consultar_filas(int sala) const {
    return almacen[sala-1].consultar_filas();
}

int Almacen::consultar_columnas(int sala) const {
    return almacen[sala-1].consultar_columnas();
}

int Almacen::consultar_vacias(int sala) const {
    return almacen[sala-1].consultar_vacias();
}

int Almacen::poner_items(int sala, const string& id, int quantitat, Inventario& inv) {
    return almacen[sala-1].poner_items(id, quantitat, inv);
}

int Almacen::quitar_items(int sala, const string& id, int quantitat, Inventario& inv) {
    return almacen[sala-1].quitar_items(id, quantitat, inv);
}

int Almacen::distribuir(const string& id, int quantitat, Inventario& inv) {
    int resto = i_distribuir(id, quantitat, inv, tree);
    return resto;
}

void Almacen::compactar(int sala) {
    almacen[sala-1].compactar();
}

void Almacen::reorganizar(int sala) {
    almacen[sala-1].reorganizar();
    //falla, cal revisar
}

void Almacen::redimensionar(int sala, int filas, int columnas) {
    almacen[sala-1].redimensionar(filas, columnas);
}

void Almacen::leer(int n) {
    almacen = vector<Estanteria>(n);
    leer_bintree(tree);
    for (int i = 0; i < n; i++) {
        int f, c;
        cin >> f >> c;
        almacen[i] = Estanteria(f, c);
    }
}

void Almacen::escribir(int sala) const {
    almacen[sala-1].escribir();
}
