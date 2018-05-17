/** @file Class_Estanteria.hh
    @brief Especificación de la clase Estanteria.
*/

#ifndef _CLASS_ESTANTERIA_
#define _CLASS_ESTANTERIA_

#include "Class_Inventario.hh"

#ifndef NO_DIAGRAM

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

#endif

/** @class Estanteria
    @brief Representa una estantería.
    
    Tiene un cierto numero de filas y columnas, que contienen productos o NULL (si estan vacíos).
*/

class Estanteria{
//Invariante de la representación: Si un elemento está en la posición k del vector estanteria, entonces está en la fila (k/columnas) y en la columna (k%columnas).
private:
    Inventario sala_inv;
    vector<string> estanteria;
    int filas;
    int columnas;
    int vacias;
    bool compacto;

public:
    //Constructoras
    /** @brief Constructora por defecto.
      \pre <em>cierto</em>.
      \post Devuelve una estantería vacía.
      \coste O(1)
    */      
    Estanteria();
    
    /** @brief Constructora por tamaño.
     * 
      \pre filas y columnas son enteros positivos.
      \post Devuelve una estantería inicializada con las dimensiones dadas, donde cada elemento es NULL.
      \coste O(n), donde n = filas*columnas = número de casillas de la estantería.
    */  
    Estanteria(int filas, int columnas);
    
    //Destructoras
    /** @brief Destructora por defecto.
     * 
      \pre <em>cierto</em>.
      \post La estantería queda destruida.
      \coste O(1)
    */  
    ~Estanteria();
    
    //Consultoras
    /** @brief Consulta una posición dada.
     * 
      \pre La posición determinada por fila y columna existe dentro de la estantería.
      \post Devuelve el elemento que se encuentra en la fila y columna dadas, donde la posición
       superior izquierda es (1, 1). Si no hay nada, devuelve NULL.
      \coste O(1)
    */   
    string consultar_pos(int fila, int columna) const;
    
    /** @brief Consulta el número de filas que tiene la estantería.
     * 
      \pre <em>cierto</em>
      \post Devuelve la cantidad de filas que tiene la estantería.
      \coste O(1)
    */  
    int consultar_filas() const;
    
    /** @brief Consulta el número de columnas que tiene la estantería.
     * 
      \pre <em>cierto</em>
      \post Devuelve la cantidad de columnas que tiene la estantería.
      \coste O(1)
    */  
    int consultar_columnas() const;
    
    /** @brief Consulta el número de posiciones vacías que tiene la estantería.
     * 
      \pre <em>cierto</em>
      \post Devuelve la cantidad de posiciones vacías que tiene la estantería.
      \coste O(1)
    */  
    int consultar_vacias() const;
    
    //Modificadoras
    /** @brief Compacta la estantería.
     * 
      \pre <em>cierto</em>.
      \post Se ha compactado la estantería siguiendo las instrucciones del enunciado.
      \coste O(n), donde n es el número de casillas de la estantería.
    */  
    void compactar();
    
    /** @brief Reorganiza la estantería.
     * 
      \pre <em>cierto</em>.
      \post Se ha compactado y ordenado la estantería.
      \coste O(n), donde n es el número de casillas de la estantería.
    */  
    void reorganizar();
    
    /** @brief Redimensiona la estantería con las medidas dadas.
     * 
      \pre Los productos de la estantería caben en las nuevas medidas.
      \post Se ha compactado y redimensionado la estantería siguiendo las instrucciones del enunciado.
      \coste O(n), donde n es el número de casillas de la estantería.
    */  
    void redimensionar(int filas, int columnas);
    
    /** @brief Añade a la sala una cierta cantidad de ítems.
     * 
      \pre id es un producto dado de alta, quantitat es un entero no negativo.
      \post Se han añadido a la sala tantas unidades del producto como sea posible, y se devuelve un entero con la cantidad que ha sobrado.
      \coste O(n), donde n es el número de casillas de la estantería.
    */  
    int poner_items(const string& id, int quantitat, Inventario& inv);
    
    /** @brief Quita de la sala una cierta cantidad de ítems.
     * 
      \pre id es un producto dado de alta, quantitat es un entero no negativo.
      \post Se han quitado de la sala tantas unidades del producto como sea posible, y se devuelve un entero con la cantidad que no se ha podido quitar.
      \coste O(n), donde n es el número de casillas de la estantería.
    */  
    int quitar_items(const string& id, int quantitat, Inventario& inv);
    
    //Escritura
    /** @brief Escribe en el canal de salida el contenido de la estantería.
     * 
      \pre <em>cierto</em>.
      \post Se han escrito en el canal de salida los elementos de la estantería, de arriba abajo y de izquierda a derecha.
      \coste O(n), donde n es el número de casillas de la estantería.
    */  
    void escribir() const;
};

#endif
