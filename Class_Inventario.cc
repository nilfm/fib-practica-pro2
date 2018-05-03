#include "Class_Inventario.hh"

Inventario::Inventario() { }

Inventario::~Inventario() { }

int Inventario::consultar_prod(const string& id) const {
    return inv[id]; //estamos seguros que existe por la precondición
}

bool Inventario::esta_dado_de_alta(const string& id) const {
    return inv.find(id) != inv.end();
}

void Inventario::poner_prod(const string& id) {
    //TO DO
}

void Inventario::quitar_prod(const string& id) {
    //TO DO
}

void Inventario::escribir() const {
    //TO DO 
}
