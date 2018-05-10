#include "Class_Inventario.hh"

Inventario::Inventario() { } //preguntar

Inventario::~Inventario() { }

int Inventario::consultar_prod(const string& id) const {
    return inventario.find(id)->second;
}

bool Inventario::esta_dado_de_alta(const string& id) const {
    return inventario.find(id) != inventario.end();
}

void Inventario::poner_prod(const string& id) {
    inventario.insert(pair<string, int>(id, 0));
}

void Inventario::quitar_prod(const string& id) {
    inventario.erase(id);
}

void Inventario::sumar(const string& id, int num) {
    inventario[id] += num;
}

//falta poder escriure els inventaris de cada sala - bool com a parametre

void Inventario::escribir() const {
    for (map<string, int>::const_iterator it = inventario.begin(); it != inventario.end(); it++) {
        cout << it->first << " " << it-> second << endl;
    }
}


