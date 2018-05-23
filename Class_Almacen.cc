/** @file Class_Almacen.cc
    @brief Implementación de la clase Almacen.
*/

#include "Class_Almacen.hh"

Almacen::Almacen() { }

Almacen::~Almacen() { }

int Almacen::i_distribuir(const string id, int quantitat, Inventario& inv, const BinTree<int>& t) {    
    if (not t.empty()) {
        Estanteria& est = consultar_sala(t.value());
        int restantes = est.poner_items(id, quantitat, inv);
        int r1 = i_distribuir(id, restantes - restantes/2, inv, t.left()); //restantes - restantes/2 = parte entera superior de restantes/2
        int r2 = i_distribuir(id, restantes/2, inv, t.right()); //restantes/2 = parte entera inferior de restantes/2
        //Hipótesis de inducción: Se han distribuído por los hijos izquierdo y derecho del árbol los productos correspondientes.
        //r1 y r2 contienen los productos sobrantes en cada hijo del árbol
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
        //Hipótesis de inducción: Se han leído los dos hijos izquierdo y derecho de a en left y right
        a = BinTree<int>(k, left, right);
    }
}

Estanteria& Almacen::consultar_sala(int sala) {
    return almacen[sala-1];
}

int Almacen::distribuir(const string& id, int quantitat, Inventario& inv) {
    int resto = i_distribuir(id, quantitat, inv, tree);
    return resto;
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

