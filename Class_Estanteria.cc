#include "Class_Estanteria.hh"

int Estanteria::cerca_lineal(const string& s) const {
    int size = files*columnes;
    for (int i = 0; i < size; i++) {
        if (estanteria[i] == s) return i;
    }
    return -1;
}
int Estanteria::cerca_dicot(const string& s) const {
    int size = files*columnes;
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
    
Estanteria::Estanteria(int files, int columnes) {
    this->files = files;
    this-> columnes = columnes;
    ordenat = true;
    buides = files*columnes;
    estanteria = vector<string>(files*columnes, "NULL");
}

Estanteria::~Estanteria() {}

string Estanteria::consultar_pos(int fila, int columna) const {
    return estanteria[fila*columnes + columna];
}

int Estanteria::cerca(const string& id) const {
    if (ordenat) return cerca_dicot(id);
    else return cerca_lineal(id);
}

void Estanteria::compactar() {
    //TO DO
}

void Estanteria::reorganizar() {
    compactar();
    sort(estanteria.begin(), estanteria.begin() + files*columnes - buides); 
}

void Estanteria::redimensionar(int filas, int columnas) {
    compactar();
    this->files = filas;
    this->columnes = columnas;
}

int Estanteria::poner_items(const string& id, int quantitat, Inventario& inv) {
    return 0;
    //TO DO
}

int Estanteria::quitar_items(const string& id, int quantitat, Inventario& inv) {
    return 0;
    //TO DO
}

void Estanteria::escribir() const{
    //TO DO
}

