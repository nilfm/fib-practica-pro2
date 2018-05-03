/** @file Class_Almacen.hh
    @brief Especificación de la clase Almacen.
*/

#ifndef _CLASS_ALMACEN_
#define _CLASS_ALMACEN_

#include "Class_Estanteria.hh"

#ifndef NO_DIAGRAM
#include "Class_BinTree.hh"
#endif

/** @class Almacen
    @brief Representa un almacén.
    
    Puede contener salas, que tienen una estantería cada una. Puede usarse para añadir o quitar ítems de salas, o para modificar los parámetros de dichas salas.
*/

class Almacen{
private:
    BinTree<int> tree;
    vector<Estanteria> almacen;
    
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
    /** @brief Consulta una posición dada de la estantería de una sala dada.
     * 
      \pre sala contiene una sala que existe en el almacén, la posición determinada por fila y columna existe dentro de la estantería de dicha sala.
      \post Devuelve el elemento que se encuentra en la sala, fila y columna dadas. Si no hay nada, devuelve NULL.
      \coste N/A
    */  
    string consultar_pos(int sala, int fila, int columna) const;
    
    /** @brief Consulta el número de filas que tiene la estantería de una sala dada.
     * 
      \pre sala contiene una sala que existe en el almacén.
      \post Devuelve la cantidad de filas que tiene la estantería de esa sala.
      \coste N/A
    */  
    int consultar_filas(int sala) const;
    
    /** @brief Consulta el número de columnas que tiene la estantería de una sala dada.
     * 
      \pre sala contiene una sala que existe en el almacén.
      \post Devuelve la cantidad de columnas que tiene la estantería de esa sala.
      \coste N/A
    */  
    int consultar_columnas(int sala) const;
    
    /** @brief Consulta el número de posiciones vacías que tiene la estantería de una sala dada.
     * 
      \pre sala contiene una sala que existe en el almacén.
      \post Devuelve la cantidad de posiciones vacías que tiene la estantería de esa sala.
      \coste N/A
    */  
    int consultar_vacias(int sala) const;
    
    //Modificadores
    /** @brief Añade a una sala una cierta cantidad de ítems
     * 
      \pre sala contiene una sala que existe en el almacén, id es un producto dado de alta, quantitat es un entero no negativo.
      \post Se han añadido a la sala tantas unidades del producto como sea posible, y se devuelve un entero con la cantidad que ha sobrado. El inventario queda actualizado.
      \coste N/A
    */  
    int poner_items(int sala, const string& id, int quantitat, Inventario& inv);
    
    /** @brief Quita de una sala una cierta cantidad de ítems
     * 
      \pre sala contiene una sala que existe en el almacén, id es un producto dado de alta, quantitat es un entero no negativo.
      \post Se han quitado de la sala tantas unidades del producto como sea posible, y se devuelve un entero con la cantidad que no se ha podido quitar. El inventario queda actualizado.
      \coste N/A
    */  
    int quitar_items(int sala, const string& id, int quantitat, Inventario& inv);
    
    /** @brief Distribuye por el almacén una cierta cantidad de ítems, empezando por la sala de entrada y repartiendo los sobrantes recursivamente en sus dos salas "hijas".
     * 
      \pre id es un producto dado de alta, quantitat es un entero no negativo.
      \post Se han distribuido por el almacén tantas unidades del producto como ha sido posible, y se devuelve un entero con la cantidad que no se ha podido distribuir en ninguna sala.
      \coste N/A
    */  
    int distribuir(const string& id, int quantitat, Inventario& inv);
    
    /** @brief Compacta la estantería de una sala.
     * 
      \pre sala contiene una sala que existe en el almacén.
      \post Se ha compactado la estantería de la sala.
      \coste N/A
    */  
    void compactar(int sala);
    
    /** @brief Reorganiza la estantería de una sala
     * 
      \pre sala contiene una sala que existe en el almacén.
      \post Se ha compactado y ordenado la estantería de la sala.
      \coste N/A
    */  
    void reorganizar(int sala);
    
    /** @brief Redimensiona la estantería de una sala con las medidas dadas.
     * 
      \pre sala contiene una sala que existe en el almacén, los productos de la sala caben en las nuevas medidas.
      \post Se ha compactado y redimensionado la estantería de la sala.
      \coste N/A
    */  
    void redimensionar(int sala, int filas, int columnas);
    
    //Lectura
    /** @brief Lee del canal de entrada los detalles de un almacén y los guarda en el parámetro implícito.
     * 
      \pre n es un entero no negativo, el canal de entrada contiene un árbol binario en preorden con nodos no vacíos, y n pares de enteros filas-columnas.
      \post El parámetro implícito contiene el árbol de estanterías que ha leído del canal de entrada, inicializado con las dimensiones de cada estantería.
      \coste N/A
    */  
    void leer(int n);
    
    //Escriptura
    /** @brief Escribe en el canal de salida el contenido de la sala dada.
     * 
      \pre sala contiene una sala que existe en el almacén.
      \post Se han escrito en el canal de salida los elementos de la estantería de esa sala, de arriba abajo y de izquierda a derecha.
      \coste N/A
    */  
    void escribir(int sala) const;    
};

#endif
