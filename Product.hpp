/**
 * @file Product.hpp
 * @brief Declaración de la clase Product
 * @version 0.1
 * @date 2021-01-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef Product_INC
#define Product_INC

#include <string>
#include <ostream>
#include <iostream>
/**
 * @brief Clase Product
 * 
 */
class Product {

    private:

        std::string name;
        std::string type;
        float       cost;
        int         quantity;

    public:

        Product();
        Product( std::string name, std::string type, float cost, int quantity );
        void print();

        void setName( std::string name );
        void setType( std::string type );
        void setCost( float cost );
        void setQuantity( int quantity );

        std::string getName();
        std::string getType();
        float  getCost();
        int    getQuantity();
};

#endif   /* ----- #ifndef Product_INC  ----- */