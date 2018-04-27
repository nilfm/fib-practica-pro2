/** @file Class_Estanteria.hh
    @brief Especificación de la clase Estantería
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

/** @class Estantería
    @brief Representa una estantería 
    
    Tiene un cierto numero de filas y columnas, que contienen productos o NULL (si estan vacíos)
*/

class Estanteria{
private:
    vector<string> estanteria;
    int files;
    int columnes;
    bool ordenat;
    int buides;
    
    int cerca_dicot(const string& s) const;
    int cerca_lineal(const string& s) const;
    
public:
    //Constructores
    /** @brief Constructora por tamaño
     * 
      \pre files y columnes son enteros positivos
      \post Devuelve una estantería inicializada con las dimensiones dadas, donde cada elemento es NULL
      \coste N/A
    */  
    Estanteria(int files, int columnes);
    
    //Destructores
    /** @brief Destructora por defecto
     * 
      \pre <em>cierto</em>
      \post La estantería queda destruída
      \coste N/A
    */  
    ~Estanteria();
    
    //Consultores
    /** @brief Consulta una posición dada
     * 
      \pre fila y columna existen dentro de la estantería 
      \post Devuelve el elemento que se encuentra en la fila y columna dada. Si no hay nada, devuelve NULL.
      \coste N/A
    */   
    string consultar_pos(int fila, int columna) const;
    
    /** @brief Busca un ítem en la sala
     * 
      \pre id contiene un identificador de producto
      \post Si el producto no está en la sala, devuelve -1. Si está, devuelve un entero con la posición del producto (la fila y la columna se obtienen a través de este número)
      \coste Logarítmico si la estantería está ordenada, lineal si no lo está
    */ 
    int cerca(const string& id) const;
    
    //Modificadores
    /** @brief Compacta la estantería 
     * 
      \pre <em>cierto</em>
      \post Se ha compactado la estantería siguiendo las instrucciones del enunciado
      \coste N/A
    */  
    void compactar();
    
    /** @brief Reorganiza la estantería 
     * 
      \pre <em>cierto</em>
      \post Se ha compactado y ordenado la estantería
      \coste N/A
    */  
    void reorganizar();
    
    /** @brief Redimensiona la estantería con las medidas dadas
     * 
      \pre Los productos de la estantería caben en las nuevas medidas
      \post Se ha compactado y redimensionado la estantería siguiendo las instrucciones del enunciado
      \coste N/A
    */  
    void redimensionar(int filas, int columnas);
    
    /** @brief Añade a la sala una cierta cantidad de ítems
     * 
      \pre id es un producto dado de alta, quantitat es un entero no negativo
      \post Se han añadido a la sala tantas unidades del producto como sea posible, y se devuelve un entero con la cantidad que ha sobrado.
      \coste N/A
    */  
    int poner_items(const string& id, int quantitat, Inventario& inv);
    
    /** @brief Quita de la sala una cierta cantidad de ítems
     * 
      \pre id es un producto dado de alta, quantitat es un entero no negativo 
      \post Se han quitado de la sala tantas unidades del producto como sea posible, y se devuelve un entero con la cantidad que no se ha podido quitar.
      \coste N/A
    */  
    int quitar_items(const string& id, int quantitat, Inventario& inv);
    
    //Escritura
    /** @brief Escribe en el canal de salida el contenido de la estantería
     * 
      \pre <em>cierto</em>
      \post Se han escrito en el canal de salida los elementos de la estantería, de arriba abajo y de izquierda a derecha
      \coste N/A
    */  
    void escribir() const;
};

#endif