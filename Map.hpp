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
#define HASH_SIZE 30

class Map {
    private:

        vector<pair<string, Product>> table;    ///< Es la tabla hash

        unsigned int max_size; ///< Es el número máximo de elementos en la tabla

        int simple( string s, int m );
        int h( string key, int m );

        int probe( string key, int i );
        void swap(pair<string, Product>* val1, pair<string, Product>* val2);

    public:    
        
        Map();
        Map( int max_size );

        bool Insert( pair< string, Product > key );
        Product Search( string key );
        bool Delete( string key );
        void Sort( int first, int last );

        void setSize( int max_size);

        int getSize();
        int getLen();
        float getLoadFactor();

        void print();
};

#endif   /* ----- #ifndef Map_INC  ----- */