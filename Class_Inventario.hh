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

const string ESPACIOS = "  ";

/** @class Inventario
    @brief Representa un inventario.
    
    Contiene la cantidad que hay en el almacén de cada uno de sus productos dados de alta.
*/

class Inventario{
private:
    map<string, int> inventario;
    map<string, int>::const_iterator itera;
    
public:
    //Constructoras
    /** @brief Constructora por defecto.
     * 
      \pre <em>cierto</em>
      \post Devuelve un inventario vacío.
      \coste O(1)
    */  
    Inventario();
    
    //Destructoras
    /** @brief Destructora por defecto.
     * 
      \pre <em>cierto</em>
      \post El inventario queda destruido.
      \coste O(1)
    */  
    ~Inventario();
    
    //Consultoras
   	/** @brief Consulta la posición a la que está apuntando el iterador.
     * 
      \pre El iterador está apuntando a una posición del inventario en que hay un producto.
      \post Devuelve un pair con el identificador del producto al que apunta el iterador y la cantidad de ese producto que hay en el inventario.
      \coste O(1)
    */  
    pair<string, int> consultar_iterador() const;
    
    /** @brief Consulta si el iterador está apuntando a una posición en la que hay un producto.
     * 
      \pre <em>cierto</em>
      \post Devuelve cierto si el iterador apunta a una posición que no sea el final del inventario. En particular, si el inventario está vacío devuelve falso.
      \coste O(1)
    */  
    bool iterador_valido() const;
    
	/** @brief Consulta la cantidad de unidades que hay en el inventario de un cierto producto.
     * 
      \pre El producto está dado de alta en el inventario.
      \post Devuelve la cantidad de unidades que hay en el inventario del producto con identificador id.
      \coste O(log n), donde n es la cantidad de productos dados de alta en el inventario.
    */  
    int consultar_prod(const string& id) const;
    
    /** @brief Consulta si un cierto producto está dado de alta en el inventario.
     * 
      \pre <em>cierto</em>.
      \post Devuelve cierto si el producto está dado de alta, y falso si no.
      \coste O(log n), donde n es la cantidad de productos dados de alta en el inventario.
    */  
    bool esta_dado_de_alta(const string& id) const;
    
    //Modificadoras
    /** @brief Hace que el iterador apunte al principio del inventario.
     * 
      \pre <em>cierto</em>
      \post El iterador queda apuntando al principio del inventario
      \coste O(1)
    */  
    void iterador_al_principio();
    
    /** @brief Hace que el iterador se adelante una posición.
     * 
      \pre El iterador no está apuntando al final del inventario.
      \post El iterador queda apuntando a una posición más adelante de la que estaba.
      \coste O(1)
    */  
    void adelantar_iterador();
    
    /** @brief Da de alta un producto en el inventario.
     * 
      \pre El producto no estaba dado de alta.
      \post El producto queda dado de alta.
      \coste O(log n), donde n es la cantidad de productos dados de alta en el inventario.
    */  
    void poner_prod(const string& id);
    
    /** @brief Da de baja un producto en el inventario.
     * 
      \pre El producto estaba dado de alta y había cero unidades de él en el inventario.
      \post El producto queda dado de baja.
      \coste O(log n), donde n es la cantidad de productos dados de alta en el inventario.
    */  
    void quitar_prod(const string& id);
    
    /** @brief Suma una cantidad de unidades a un producto.
     * 
      \pre El producto estaba dado de alta, num es un entero (puede ser negativo).
      \post Se han sumado num unidades al producto asociado a id.
      \coste O(log n), donde n es la cantidad de productos dados de alta en el inventario.
    */  
    void sumar(const string& id, int num);
    
    //Escritura
    /** @brief Escribe los contenidos del inventario, producto-cantidad, en orden de identificador de producto.
     * Tiene una opción para escribir o no escribir los productos de los cuales hay cero unidades.
     * 
      \pre <em>cierto</em>.
      \post Se ha escrito en el canal de salida la cantidad de unidades de cada producto del inventario, ordenados por su identificador.
      Si "todas" es falso, no se han escrito aquellos productos que tengan cero unidades.
      \coste O(n), donde n es la cantidad de productos dados de alta en el inventario.
    */  
    void escribir(bool todas) const;

};

#endif
