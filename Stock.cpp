/**
 * @file Stock.cpp
 * @author Piña Rossette Marco Antonio
 * @brief Definiciones de la clase Stock
 * @version 0.1
 * @date 2021-01-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include "Stock.hpp"

/**
 * @brief Construct a new Stock:: Stock object
 * 
 * @param max_size Tamaño máximo del stock
 */
Stock::Stock( int max_size ){
    this->map.setSize( max_size );
}

/**
 * @brief Crea un producto en el stock
 * 
 * @param id ID del producto a crear
 * @param product Objeto Producto a crear
 * @return true Si se pudo crear
 * @return false Si no se pudo crear
 */
bool Stock::createProduct( std::string id, Product product ){

    if ( this->map.Insert( make_pair( id, product ) ) ) {
        return true;
    }
    return false;
}

/**
 * @brief Elimina un producto en el stock
 * 
 * @param id ID del producto a eliminar
 * @return true Si se pudo eliminar
 * @return false Si no se pudo eliminar
 */
bool Stock::deleteProduct( std::string id ){

    if( this->map.Delete( id ) ){
        return true;
    }
    return false;
}

/**
 * @brief Evlúa si existe un producto en el stock
 * 
 * @param id ID del producto a evaluar
 * @return true Si existe el producto
 * @return false Si no existe el producto
 */
bool Stock::existsProduct( std::string id ){
    if( this->map.Search( id ) != nullptr ){
        return false;
    }
    return true;
}

/**
 * @brief Busca un producto en el stock
 * 
 * @param id ID del producto a buscar
 * @return Product* Referencia del producto buscado
 */
Product* Stock::searchProduct( std::string id ){
    return this->map.Search( id );
}

/**
 * @brief Aumenta la cantidad a un producto existente
 * 
 * @param id ID del producto a aumentar
 * @param quantity Cantidad a aumentar
 * @return true Si se aumentó
 * @return false Si no se aumentó
 */
bool Stock::addProduct( std::string id, int quantity ){
    Product* add = this->map.Search( id );

    if( add != nullptr ){
        add->setQuantity( add->getQuantity() + quantity );
        return true;
    }
    return false;
}

/**
 * @brief Retira la cantidad a un producto eistente
 * 
 * @param id ID del producto a retirar
 * @param quantity Cantidad a retirar
 * @return true Si se pudo retirar
 * @return false Si no se pudo retirar
 */
bool Stock::removeProduct( std::string id, int quantity ){
    Product* remove = this->map.Search( id );

    if( remove != nullptr ){
        if( remove->getQuantity() > quantity ){    
            remove->setQuantity( remove->getQuantity() - quantity );
            return true;
        }
    }
    return false;
}

/**
 * @brief Imprime el stock existente
 * 
 */
void Stock::print(){
    system("clear");

    Map map_copy = this->map;

    std::cout << "REPORTE DE INVENTARIO." << std::endl;

    std::cout << "\tCODIGO\t\tPRODUCTO\t\tCATEGORIA\t\tPRECIO\t\tCANTIDAD\n" << std::endl;
    map_copy.Sort( 0, map_copy.getSize()-1);
    map_copy.print();
}

/**
 * @brief Serializa los datos en un archivo binario
 * 
 */
void Stock::serialize(){
    this->map.Serialize();
}

/**
 * @brief Desserializa los datos de un archivo binario
 * 
 */
void Stock::deserialize(){
    this->map.Deserialize();
}
