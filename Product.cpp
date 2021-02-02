/**
 * @file Product.cpp
 * @brief Defniciones de la clase Product
 * @version 0.1
 * @date 2021-01-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Product.hpp"

/**
 * @brief Construct a new Product:: Product object
 * 
 */
Product::Product(  ){
}

/**
 * @brief Construct a new Product:: Product object
 * 
 * @param name Nombre del producto
 * @param type Categoría del producto
 * @param cost Precio del producto
 * @param quantity Cantidad de artículos a crear
 */
Product::Product( std::string name, std::string type, float cost, int quantity ){

    //this->id = id;
    this->name = name;
    this->type = type;
    this->cost = cost;
    this->quantity = quantity;
}

/**
 * @brief Imprime un producto
 *
 */
void Product::print() {
    
    std::cout << "\tPRODUCTO\t\tCATEGORIA\t\tPRECIO\t\tCANTIDAD\n" << std::endl;
    std::cout << "\t" << this->getName()
        << "\t\t" << this->getType()
        << "\t\t" << this->getCost()
        << "\t\t" << this->getQuantity()
        << std::endl;
}

/**
 * @brief Setter para el nombre del producto
 * 
 * @param name Nuevo nombre del producto
 */
void Product::setName( std::string name ){
    this->name = name;
}

/**
 * @brief Setter para el tipo del producto
 * 
 * @param type Nuevo tipo del producto
 */
void Product::setType( std::string type ){
    this->type = type;
}

/**
 * @brief Setter para el costo del producto
 * 
 * @param cost Nuevo costo del producto
 */
void Product::setCost( float cost ){
    this->cost = cost;
}

/**
 * @brief Setter para la cantidad del producto
 * 
 * @param quantity Nueva cantidad del producto
 */
void Product::setQuantity( int quantity ){
    this->quantity = quantity;
}

/**
 * @brief Getter del nombre del producto
 * 
 * @return std::string El nombre del producto
 */
std::string Product::getName(){
    return this->name;
}

/**
 * @brief Getter del tipo del producto
 * 
 * @return std::string El tipo del prodcuto 
 */
std::string Product::getType(){
    return this->type;
}

/**
 * @brief Getter del costo del producto
 * 
 * @return float El costo del producto
 */
float Product::getCost(){
    return this->cost;
}

/**
 * @brief Getter de la cantidad del producto
 * 
 * @return int La cantidad del producto
 */
int Product::getQuantity(){
    return this->quantity;
}