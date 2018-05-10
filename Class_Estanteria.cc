#include "Class_Estanteria.hh"
    
Estanteria::Estanteria(int filas, int columnas) {
    this->filas = filas;
    this->columnas = columnas;
    vacias = filas*columnas;
    estanteria = vector<string>(filas*columnas, "NULL");
}

Estanteria::Estanteria() { }

Estanteria::~Estanteria() { }

string Estanteria::consultar_pos(int fila, int columna) const {
    return estanteria[(fila-1)*columnas + columna-1];
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
}

void Estanteria::reorganizar() {
	//recorrer el map i posar-los al vector
	//cal revisar, no funciona
    compactar();
    sort(estanteria.begin(), estanteria.begin() + filas*columnas - vacias, Estanteria::comp); 
}

void Estanteria::redimensionar(int filas, int columnas) {
    compactar();
    estanteria.resize(filas*columnas, "NULL");
    this->filas = filas;
    this->columnas = columnas;
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
            vacias--;
        }
    }
    inv.sumar(id, -count);
	if (not sala_inv.esta_dado_de_alta(id)) sala_inv.poner_prod(id);
    sala_inv.sumar(id, -count);
    return quantitat - count;
}

void Estanteria::escribir() const {
    int size = filas*columnas;
    for (int i = size-columnas; i >= 0; i -= columnas){
        for (int j = 0; j < columnas; j++){
            if (j != 0) cout << " ";
            cout << estanteria[i+j];
        }
        cout << endl;
    }
    cout << size-vacias << endl;
	sala_inv.escribir();
}

bool Estanteria::comp(const string& s1, const string& s2) {
    if (s1 == "NULL") return false;
    if (s2 == "NULL") return true;
    return s1 < s2;
}
