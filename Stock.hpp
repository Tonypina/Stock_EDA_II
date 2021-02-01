/**
 * @file Stock.hpp
 * @brief Declaración de la clase Stock
 * @version 0.1
 * @date 2021-01-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef Stock_INC
#define Stock_INC

#include "Map.hpp"

/**
 * @brief Clase stock
 * 
 */
class Stock {

    private:

        Map map;

    public:
        Stock( int max_size );

        bool createProduct( std::string id, Product product );
        bool deleteProduct( std::string id );
        bool existsProduct( std::string id );
        Product* searchProduct ( std::string id );
        bool addProduct( std::string id, int quantity );
        bool removeProduct( std::string id, int quantity );
        void print();
        void serialize();
        void deserialize();
};

#endif   /* ----- #ifndef Stock_INC  ----- */
