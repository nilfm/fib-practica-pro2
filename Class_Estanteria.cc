/** @file Class_Estanteria.cc
    @brief Implementación de la clase Estanteria.
*/

#include "Class_Estanteria.hh"
    
Estanteria::Estanteria(int filas, int columnas) {
    this->filas = filas;
    this->columnas = columnas;
    vacias = filas*columnas;
    compacto = true;
    estanteria = vector<string>(filas*columnas, "NULL");
}

Estanteria::Estanteria() { }

Estanteria::~Estanteria() { }

string Estanteria::consultar_pos(int fila, int columna) const {
	int f_actual = filas - fila;
	int c_actual = columna - 1;
    return estanteria[(f_actual)*columnas + c_actual];
}

int Estanteria::consultar_filas() const {
    return filas;
}

int Estanteria::consultar_columnas() const {
    return columnas;
}

int Estanteria::consultar_vacias() const {
    return vacias;
}

void Estanteria::compactar() {
    if (compacto) return;
    int size = filas*columnas;
    int i = 0; //recorre todas las casillas
    int j = 0; //recorre las casillas llenas
    //inv: j <= i
    while (i < size) {
        if (estanteria[j] == "NULL" and estanteria[i] != "NULL") {
            estanteria[j] = estanteria[i];
            estanteria[i] = "NULL";
            j++;
        }
        else if (estanteria[j] != "NULL") j++;
        i++;
    }
    compacto = true;
}

void Estanteria::reorganizar() {
	int i = 0;
	sala_inv.iterador_al_principio();
    while (sala_inv.iterador_valido()) {
        pair<string, int> it = sala_inv.consultar_iterador();
        for (int j = 0; j < it.second; j++) {
            estanteria[i] = it.first;
            i++;
        }
        sala_inv.adelantar_iterador();
    }
    int size = filas*columnas;
    while (i < size) {
        estanteria[i] = "NULL";
        i++;
    }
    compacto = true;
}

void Estanteria::redimensionar(int filas, int columnas) {
    if (not compacto) compactar();
    estanteria.resize(filas*columnas, "NULL");
    vacias += (filas*columnas - this->filas*this->columnas);
    this->filas = filas;
    this->columnas = columnas;
    compacto = true;
}

int Estanteria::poner_items(const string& id, int quantitat, Inventario& inv) {
    int size = filas*columnas;
    int count = 0;
    for (int i = 0; i < size and count < quantitat; i++) {
        if (estanteria[i] == "NULL") {
            estanteria[i] = id;
            count++;
            vacias--;
        }
    }
    inv.sumar(id, count);
    if (not sala_inv.esta_dado_de_alta(id)) sala_inv.poner_prod(id);
    sala_inv.sumar(id, count);
    return quantitat - count;
}

int Estanteria::quitar_items(const string& id, int quantitat, Inventario& inv) {
    int size = filas*columnas;
    int count = 0;
    for (int i = 0; i < size and count < quantitat; i++) {
        if (estanteria[i] == id) {
            estanteria[i] = "NULL";
            count++;
            vacias++;
        }
    }
    inv.sumar(id, -count);
    if (not sala_inv.esta_dado_de_alta(id)) sala_inv.poner_prod(id);
    sala_inv.sumar(id, -count);
    compacto = false;
    return quantitat - count;
}

void Estanteria::escribir() const {
    int size = filas*columnas;
    for (int i = size-columnas; i >= 0; i -= columnas){
        cout << ESPACIOS;
        for (int j = 0; j < columnas; j++){
            if (j != 0) cout << " ";
            cout << estanteria[i+j];
        }
        cout << endl;
    }
    cout << ESPACIOS << size-vacias << endl;
    sala_inv.escribir(false);
}
