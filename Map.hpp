/**
 * @file Map.hpp
 * @author Piña Rossette Marco Antonio
 * @brief Declaración de la clase Map
 * @version 0.1
 * @date 2021-01-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef  Map_INC
#define  Map_INC

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
#include <math.h>
#include <vector>
#include "Product.hpp"

#define EMPTY_CELL "EMPTY"
#define DELETED_CELL "DELETED"
#define HASH_SIZE 31

/**
 * @brief Clase Map que soporta productos
 * 
 */
class Map {
    private:

        std::vector<std::pair<std::string, Product>> table; ///< Es la tabla hash

        unsigned int max_size; ///< Es el número máximo de elementos en la tabla
        unsigned int len; ///< Tamaño de la tabla hash

        int simple( std::string s, int m );
        int h( std::string key, int m );

        int probe( std::string key, int i );
        void swap(std::pair<std::string, Product>* val1, std::pair<std::string, Product>* val2);

    public:    
        
        Map();
        Map( int max_size );

        bool Insert( std::pair< std::string, Product > key );
        Product* Search( std::string key );
        bool Delete( std::string key );
        void Sort( int first, int last );

        void setSize( int max_size);

        int getSize();
        int getLen();
        float getLoadFactor();

        void Serialize();
        void Deserialize();
        void print();
};

#endif   /* ----- #ifndef Map_INC  ----- */
