/** @file Class_Inventario.hh
    @brief Especificación de la clase Inventario
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
#include "Class_BinTree.hh"
using namespace std;

#endif

/** @class Inventario
    @brief Representa un inventario 
    
    Contiene la cantidad que hay en el almacén de cada uno de sus productos dados de alta
*/

class Inventario{
private:
	map<string, int> inv;
	
public:
	//Constructores
	/** @brief Constructora por defecto
	 * 
      \pre <em>cierto</em>
      \post Devuelve un inventario vacío
      \coste N/A
	*/  
	Inventario();
	
	/** @brief Constructora por copia
	 * 
      \pre original contiene un inventario válido
      \post Devuelve un inventario igual que el original
      \coste N/A
	*/  
	Inventario(const Inventario& original);
	
	//Destructores
	/** @brief Destructora por defecto
	 * 
      \pre <em>cierto</em>
      \post El inventario queda destruído
      \coste N/A
	*/  
	~Inventario();
    
	//Consultores
	/** @brief Consulta la cantidad de unidades que hay en el inventario de un cierto producto
	 * 
      \pre El producto está dado de alta en el inventario
      \post 
      \coste N/A
	*/  
	int consultar_prod(const string& id) const;
	
	//Modificadores
	/** @brief Da de alta un producto en el inventario
	 * 
      \pre El producto no estaba dado de alta
      \post El producto queda dado de alta
      \coste N/A
	*/  
	void poner_prod(const string& id);
	
	/** @brief Da de baja un producto en el inventario
	 * 
      \pre El producto estaba dado de alta y había cero unidades de él en el inventario
      \post El producto queda dado de baja
      \coste N/A
	*/  
	void quitar_prod(const string& id);
	
	//Escriure
	/** @brief Escribe los contenidos del inventario, producto-cantidad, en orden de identificador de producto
	 * 
      \pre <em>cierto</em>
      \post Se ha escrito en el canal de salida la cantidad de cada producto del inventario, ordenados por su identificador 
      \coste N/A
	*/  
	void escribir() const;

};

#endif
