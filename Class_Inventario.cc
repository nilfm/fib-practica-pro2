/** @file Class_Inventario.cc
    @brief Implementación de la clase Inventario.
*/

#include "Class_Inventario.hh"

Inventario::Inventario() { }

Inventario::~Inventario() { }

pair<string, int> Inventario::consultar_iterador() const {
	return make_pair(itera->first, itera->second); //se puede retornar *itera y ya?
}

bool Inventario::iterador_valido() const {
	return (itera != inventario.end());
}

int Inventario::consultar_prod(const string& id) const {
    return inventario.find(id)->second;
}

bool Inventario::esta_dado_de_alta(const string& id) const {
    return inventario.find(id) != inventario.end();
}

void Inventario::iterador_al_principio() {
	itera = inventario.begin();
}

void Inventario::adelantar_iterador() {
	itera++;
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

void Inventario::escribir(bool todas) const {
    for (map<string, int>::const_iterator it = inventario.begin(); it != inventario.end(); it++) {
        if (todas or it->second != 0) cout << ESPACIOS << it->first << " " << it->second << endl;
    }
}


