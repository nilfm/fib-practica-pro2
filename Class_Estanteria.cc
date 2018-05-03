#include "Class_Estanteria.hh"

int Estanteria::cerca_lineal(const string& s) const {
    int size = filas*columnas;
    for (int i = 0; i < size; i++) {
        if (estanteria[i] == s) return i;
    }
    return -1;
}
int Estanteria::cerca_dicot(const string& s) const {
    int size = filas*columnas;
    int left = 0;
    int right = size;
    while (left < right) {
        int mid = (left+right)/2;
        if (estanteria[mid] == s) return mid;
        else if (estanteria[mid] < s) right = mid-1;
        else left = mid+1;
    }
    return -1;
}
    
Estanteria::Estanteria(int filas, int columnas) {
    this->filas = filas;
    this->columnas = columnas;
    ordenat = true;
    vacias = filas*columnas;
    estanteria = vector<string>(filas*columnas, "NULL");
}

Estanteria::~Estanteria() {}

string Estanteria::consultar_pos(int fila, int columna) const {
    return estanteria[(fila-1)*columnas + columna-1];
}

int Estanteria::cerca(const string& id) const {
    if (ordenat) return cerca_dicot(id);
    else return cerca_lineal(id);
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
    //TO DO
}

void Estanteria::reorganizar() {
    compactar();
    sort(estanteria.begin(), estanteria.begin() + filas*columnas - vacias); 
}

void Estanteria::redimensionar(int filas, int columnas) {
    compactar();
    this->filas = filas;
    this->columnas = columnas;
}

int Estanteria::poner_items(const string& id, int quantitat, Inventario& inv) {
    if (quantitat > 0) ordenat = false;
    int size = filas*columnas;
    int count = 0;
    for (int i = 0; i < size and count < quantitat; i++) {
        if (estanteria[i] == "NULL") {
            estanteria[i] = id;
            count++;
            vacias--;
        }
    }
    inv[id] += count;
    return quantitat - count;
}

int Estanteria::quitar_items(const string& id, int quantitat, Inventario& inv) {
    if (quantitat > 0) ordenat = false;
    int size = filas*columnas;
    int count = 0;
    for (int i = 0; i < size and count < quantitat; i++) {
        if (estanteria[i] == id) {
            estanteria[i] = "NULL";
            count++;
            vacias--;
        }
    }
    inv[id] -= count;
    return quantitat - count;
}

void Estanteria::escribir() const{
    //TO DO
}

