/** @file Class_Inventario.hh
    @brief Especificación de la clase Inventario.
*/

#ifndef _CLASS_INVENTARIO_
#define _CLASS_INVENTARIO_

#ifndef NO_DIAGRAM

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

#endif

/** @class Inventario
    @brief Representa un inventario.
    
    Contiene la cantidad que hay en el almacén de cada uno de sus productos dados de alta.
*/

class Inventario{
private:
    map<string, int> inventario;
    
public:
    //Constructores
    /** @brief Constructora por defecto.
     * 
      \pre <em>cierto</em>
      \post Devuelve un inventario vacío.
      \coste N/A
    */  
    Inventario();
    
    //Destructores
    /** @brief Destructora por defecto.
     * 
      \pre <em>cierto</em>
      \post El inventario queda destruido.
      \coste N/A
    */  
    ~Inventario();
    
    //Consultores
    /** @brief Consulta la cantidad de unidades que hay en el inventario de un cierto producto.
     * 
      \pre El producto está dado de alta en el inventario.
      \post Devuelve la cantidad de unidades que hay en el inventario del producto con identificador id.
      \coste N/A
    */  
    int consultar_prod(const string& id) const;
    
    /** @brief Consulta si un cierto producto está dado de alta en el inventario.
     * 
      \pre <em>cierto</em>.
      \post Devuelve cierto si el producto está dado de alta, y falso si no.
      \coste N/A
    */  
    bool esta_dado_de_alta(const string& id) const;
    
    //Modificadores
    /** @brief Da de alta un producto en el inventario.
     * 
      \pre El producto no estaba dado de alta.
      \post El producto queda dado de alta.
      \coste N/A
    */  
    void poner_prod(const string& id);
    
    /** @brief Da de baja un producto en el inventario.
     * 
      \pre El producto estaba dado de alta y había cero unidades de él en el inventario.
      \post El producto queda dado de baja.
      \coste N/A
    */  
    void quitar_prod(const string& id);
    
    /** @brief Suma una cantidad de unidades a un producto.
     * 
      \pre El producto estaba dado de alta, num es un entero (puede ser negativo).
      \post Se han sumado num unidades al producto asociado a id.
      \coste N/A
    */  
    void sumar(const string& id, int num);
    
    //Escriure
    /** @brief Escribe los contenidos del inventario, producto-cantidad, en orden de identificador de producto.
     * 
      \pre <em>cierto</em>.
      \post Se ha escrito en el canal de salida la cantidad de cada producto del inventario, ordenados por su identificador.
      \coste N/A
    */  
    void escribir() const;

};

#endif
