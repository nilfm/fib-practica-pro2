/** @file Class_Almacen.hh
    @brief Especificación de la clase Almacen.
*/

#ifndef _CLASS_ALMACEN_
#define _CLASS_ALMACEN_

#include "Class_Estanteria.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#endif

/** @class Almacen
    @brief Representa un almacén.
    
    Puede contener salas, que tienen una estantería cada una. Puede usarse para añadir o quitar ítems de salas, o para modificar los parámetros de dichas salas.
*/

class Almacen{
private:
    BinTree<int> tree;
    vector<Estanteria> almacen;
    int i_distribuir(const string id, int quantitat, Inventario& inv, const BinTree<int>& t);
    static void leer_bintree(BinTree<int>& a);
    
public:
    //Constructores
    /** @brief Constructora por defecto. 
     * 
      Devuelve un almacén sin salas.
      \pre <em>cierto</em>
      \post El resultado es un almacén sin ninguna sala.
      \coste N/A
    */  
    Almacen();
    
    //Destructores
    /** @brief Destructora por defecto.
     * 
      \pre <em>cierto</em>.
      \post El almacén queda destruido.
      \coste N/A
    */  
    ~Almacen();
    
    
    //Consultores
    
    /** comentar
    */
    Estanteria& consultar_sala(int sala);
    
    
    //Modificadores
    /** @brief Distribuye por el almacén una cierta cantidad de ítems, empezando por la sala de entrada y repartiendo los sobrantes recursivamente en sus dos salas "hijas".
     * 
      \pre id es un producto dado de alta, quantitat es un entero no negativo.
      \post Se han distribuido por el almacén tantas unidades del producto como ha sido posible, y se devuelve un entero con la cantidad que no se ha podido distribuir en ninguna sala.
      \coste N/A
    */  
    int distribuir(const string& id, int quantitat, Inventario& inv);
    
    //Lectura
    /** @brief Lee del canal de entrada los detalles de un almacén y los guarda en el parámetro implícito.
     * 
      \pre n es un entero no negativo, el canal de entrada contiene un árbol binario en preorden con nodos no vacíos, y n pares de enteros filas-columnas.
      \post El parámetro implícito contiene el árbol de estanterías que ha leído del canal de entrada, inicializado con las dimensiones de cada estantería.
      \coste N/A
    */  
    void leer(int n);

};

#endif
