#include "Class_Almacen.hh"
#include "Class_Inventario.hh"

const string ERROR = "Error. Una o más precondiciones no se cumplen.";

int main(){
    int n;
    cin >> n;
    Almacen alm;
    alm.leer(n);
    Inventario inv;
    
    bool cont = true;
    while (cont) {
        string opcion;
        cin >> opcion;
        if (opcion == "escribir") {
            int sala;
            cin >> sala;
            if (sala <= 0 or sala > n) cout << ERROR << endl;
            else alm.escribir(sala);
        }
        else if (opcion == "compactar") {
            int sala;
            cin >> sala;
            if (sala <= 0 or sala > n) cout << ERROR << endl;
            else alm.compactar(sala);
        }
        else if (opcion == "reorganizar") {
            int sala;
            cin >> sala;
            if (sala <= 0 or sala > n) cout << ERROR << endl;
            else alm.reorganizar(sala);
        }
        else if (opcion == "redimensionar") {
            int sala, filas, columnas;
            cin >> sala >> filas >> columnas;
            int max_filas = alm.consultar_filas(sala);
            int max_columnas = alm.consultar_columnas(sala);
            int vacias = alm.consultar_vacias(sala);
            if (sala <= 0 or sala > n) cout << ERROR << endl;
            else if (filas < 0 or columnas < 0) cout << ERROR << endl;
            else if (max_filas*max_columnas - vacias > filas*columnas) cout << ERROR << endl;
            else alm.redimensionar(sala, filas, columnas);
        }
        else if (opcion == "poner_items") {
            int sala, quant;
            string id;
            cin >> sala >> id >> quant;
            if (sala <= 0 or sala > n) cout << ERROR << endl;
            else if (not inv.esta_dado_de_alta(id)) cout << ERROR << endl;
            else if (quant < 0) cout << ERROR << endl;
            else {
                int sobra = alm.poner_items(sala, id, quant, inv);
                cout << sobra << endl;
            }
        }
        else if (opcion == "quitar_items") {
            int sala, quant;
            string id;
            cin >> sala >> id >> quant;
            if (sala <= 0 or sala > n) cout << ERROR << endl;
            else if (not inv.esta_dado_de_alta(id)) cout << ERROR << endl;
            else if (quant < 0) cout << ERROR << endl;
            else {
                int sobra = alm.quitar_items(sala, id, quant, inv);
                cout << sobra << endl;
            }
        }
        else if (opcion == "distribuir") {
            string id;
            int quant;
            cin >> id >> quant;
            if (not inv.esta_dado_de_alta(id)) cout << ERROR << endl;
            else if (quant < 0) cout << ERROR << endl;
            else {
                int sobra = alm.distribuir(id, quant, inv);
                cout << sobra << endl;
            }
        }
        else if (opcion == "consultar_pos") {
            int sala, fila, columna;
            cin >> sala >> fila >> columna;
            int max_filas = alm.consultar_filas(sala);
            int max_columnas = alm.consultar_columnas(sala);
            if (sala <= 0 or sala > n) cout << ERROR << endl;
            else if (fila < 0 or columna < 0) cout << ERROR << endl;
            else if (fila > max_filas or columna > max_columnas) cout << ERROR << endl;
            else alm.consultar_pos(sala, fila, columna);
        }
        else if (opcion == "consultar_prod") {
            string id;
            cin >> id;
            if (not inv.esta_dado_de_alta(id)) cout << ERROR << endl;
            else {
                int prod = inv.consultar_prod(id);
                cout << prod << endl;
            }
        }
        else if (opcion == "poner_prod") {
            string id;
            cin >> id;
            if (not inv.esta_dado_de_alta(id)) cout << ERROR << endl;
            else inv.poner_prod(id);
        }
        else if (opcion == "quitar_prod") {
            string id;
            cin >> id;
            if (not inv.esta_dado_de_alta(id)) cout << ERROR << endl;
            else inv.quitar_prod(id);
        }
        else if (opcion == "inventario") {
            inv.escribir();
        }
        else cont = false;
    }
}
