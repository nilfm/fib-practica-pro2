/** @file Class_Almacen.hh
    @brief Especificación de la clase Almacen.
*/

#ifndef _CLASS_ALMACEN_
#define _CLASS_ALMACEN_

#include "Class_Estanteria.hh"
#include "Class_Inventario.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#endif

/** @class Almacen
    @brief Representa un almacén.
    
    Puede contener salas, que tienen una estantería cada una. Puede usarse para añadir o quitar ítems de salas, o para modificar los parámetros de dichas salas.
*/

class Almacen{
private:
    /** @brief Árbol binario que representa la estructura del almacén.
     * Contiene únicamente los números identificadores de las salas.
    */ 
    BinTree<int> tree;
    
    /** @brief Vector que contiene las estanterías de las salas del almacén.
     * Se ha escogido un vector para permitir acceso en tiempo constante a una sala sabiendo el número de la sala.
    */ 
    vector<Estanteria> almacen;
    
    /** @brief Función de inmersión para la función distribuir. 
      \pre id es un producto dado de alta en el inventario inv, t es un árbol binario de enteros que representan salas,
       t.value() es la sala en que estamos quantitat es la cantidad de items que no se ha podido poner en las salas 
       superiores a la actual y que se ha distribuido hacia la sala actual siguiendo las políticas del enunciado.
      \post Se han puesto en la sala todos los items posibles, y se han distribuido por sus salas hijas el resto
       de productos (si hay). Si sobraran productos que no han cabido en todo el árbol con la sala actual como raíz, 
       se devuelve como entero. Si no, se devuelve 0.
      \coste O(m*n), respecto a n salas y m posiciones en la estantería de cada sala
    */  
    int i_distribuir(const string id, int quantitat, Inventario& inv, const BinTree<int>& t);
    
    /** @brief Función de lectura del árbol binario en preorden.
      \pre En el canal de entrada hay un árbol binario de enteros en preorden.
      \post Se ha leído el árbol del canal de entrada y está contenido en el árbol a.
      \coste O(n), respecto al número de nodos del árbol binario a leer.
    */  
    static void leer_bintree(BinTree<int>& a);
    
public:
    //Constructoras
    /** @brief Constructora por tamaño. Lee del canal de entrada los detalles de un almacén y los guarda en el almacén.
     * 
      \pre n es un entero no negativo, el canal de entrada contiene un árbol binario en preorden con nodos no vacíos, y n pares de enteros filas-columnas.
      \post El almacén que ha sido creado contiene los datos que ha leído del canal de entrada, y está inicializado con las dimensiones de cada estantería.
      \coste O(m*n), respecto a n salas y m posiciones en la estantería de cada sala (para inicializar las estanterías)
    */  
    Almacen(int n);
    
    //Destructoras
    /** @brief Destructora por defecto.
     * 
      \pre <em>cierto</em>.
      \post El almacén queda destruido.
      \coste O(1)
    */  
    ~Almacen();
    
    
    //Consultoras
    /** @brief Destructora por defecto.
     * 
      \pre sala es una sala válida dentro del almacén
      \post Se devuelve una referencia a la sala
      \coste O(1)
    */  
    Estanteria& consultar_sala(int sala);
    
    
    //Modificadoras
    /** @brief Distribuye por el almacén una cierta cantidad de ítems, empezando por la sala de entrada y repartiendo los sobrantes recursivamente en sus dos salas "hijas".
     * 
      \pre id es un producto dado de alta en el inventario inv, quantitat es un entero no negativo.
      \post Se han distribuido por el almacén tantas unidades del producto como ha sido posible, y se devuelve un entero con la cantidad que no se ha podido distribuir en ninguna sala.
      \coste O(m*n), respecto a n salas y m posiciones en la estantería de cada sala
    */  
    int distribuir(const string& id, int quantitat, Inventario& inv);
};

#endif
