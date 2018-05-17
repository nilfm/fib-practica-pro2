#include "Class_Almacen.hh"
#include "Class_Inventario.hh"

const string ERROR = "  error";

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
            cout << opcion << " " << sala << endl;
            if (sala <= 0 or sala > n) cout << ERROR << endl;
            else alm.consultar_sala(sala).escribir();
        }
        else if (opcion == "compactar") {
            int sala;
            cin >> sala;
            cout << opcion << " " << sala << endl;
            if (sala <= 0 or sala > n) cout << ERROR << endl;
            else alm.consultar_sala(sala).compactar();
        }
        else if (opcion == "reorganizar") {
            int sala;
            cin >> sala;
            cout << opcion << " " << sala << endl;
            if (sala <= 0 or sala > n) cout << ERROR << endl;
            else alm.consultar_sala(sala).reorganizar();
        }
        else if (opcion == "redimensionar") {
            int sala, filas, columnas;
            cin >> sala >> filas >> columnas;
            cout << opcion << " " << sala << " " << filas << " " << columnas << endl;
            int max_filas = alm.consultar_sala(sala).consultar_filas();
            int max_columnas = alm.consultar_sala(sala).consultar_columnas();
            int vacias = alm.consultar_sala(sala).consultar_vacias();
            if (sala <= 0 or sala > n) cout << ERROR << endl;
            else if (filas < 0 or columnas < 0) cout << ERROR << endl;
            else if (max_filas*max_columnas - vacias > filas*columnas) cout << ERROR << endl;
            else alm.consultar_sala(sala).redimensionar(filas, columnas);
        }
        else if (opcion == "poner_items") {
            int sala, quant;
            string id;
            cin >> sala >> id >> quant;
            cout << opcion << " " << sala << " " << id << " " << quant << endl;
            if (sala <= 0 or sala > n) cout << ERROR << endl;
            else if (not inv.esta_dado_de_alta(id)) cout << ERROR << endl;
            else if (quant < 0) cout << ERROR << endl;
            else cout << ESPACIOS << alm.consultar_sala(sala).poner_items(id, quant, inv) << endl;
        }
        else if (opcion == "quitar_items") {
            int sala, quant;
            string id;
            cin >> sala >> id >> quant;
            cout << opcion << " " << sala << " " << id << " " << quant << endl;
            if (sala <= 0 or sala > n) cout << ERROR << endl;
            else if (not inv.esta_dado_de_alta(id)) cout << ERROR << endl;
            else if (quant < 0) cout << ERROR << endl;
            else if (alm.consultar_sala(sala).consultar_cantidad(id) < quant) cout << ERROR << endl; //preguntar si cal comprovar tambe la sala -- si es pot posar un cas de prova aixi
            else cout << ESPACIOS << alm.consultar_sala(sala).quitar_items(id, quant, inv) << endl;
        }
        else if (opcion == "distribuir") {
            string id;
            int quant;
            cin >> id >> quant;
            cout << opcion << " " << id << " " << quant << endl;
            if (not inv.esta_dado_de_alta(id)) cout << ERROR << endl;
            else if (quant < 0) cout << ERROR << endl;
            else cout << ESPACIOS << alm.distribuir(id, quant, inv) << endl;
        }
        else if (opcion == "consultar_pos") {
            int sala, fila, columna;
            cin >> sala >> fila >> columna;
            cout << opcion << " " << sala << " " << fila << " " << columna << endl;
            int max_filas = alm.consultar_sala(sala).consultar_filas();
            int max_columnas = alm.consultar_sala(sala).consultar_columnas();
            if (sala <= 0 or sala > n) cout << ERROR << endl;
            else if (fila < 0 or columna < 0) cout << ERROR << endl;
            else if (fila > max_filas or columna > max_columnas) cout << ERROR << endl;
            else cout << ESPACIOS << alm.consultar_sala(sala).consultar_pos(fila, columna) << endl;
        }
        else if (opcion == "consultar_prod") {
            string id;
            cin >> id;
            cout << opcion << " " << id << endl;
            if (not inv.esta_dado_de_alta(id)) cout << ERROR << endl;
            else cout << ESPACIOS << inv.consultar_prod(id) << endl;
        }
        else if (opcion == "poner_prod") {
            string id;
            cin >> id;
            cout << opcion << " " << id << endl;
            if (inv.esta_dado_de_alta(id)) cout << ERROR << endl;
            else inv.poner_prod(id);
        }
        else if (opcion == "quitar_prod") {
            string id;
            cin >> id;
            cout << opcion << " " << id << endl;
            if (not inv.esta_dado_de_alta(id) or inv.consultar_prod(id) != 0) cout << ERROR << endl;
            else inv.quitar_prod(id);
        }
        else if (opcion == "inventario") {
            cout << opcion << endl;
            inv.escribir(true);
        }
        else {
            cout << opcion << endl;
            cont = false;
        }
    }
}
