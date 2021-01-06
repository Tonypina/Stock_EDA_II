#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
#include <math.h>
#include "Product.hpp"

enum{ EMPTY_CELL = -2, DELETED_CELL = -1 };

class Map {
    private:

        pair<int, Product>* table;    ///< Es la tabla hash
        int  size;     ///< Es el número máximo de elementos en la tabla
        int  len;      ///< Es el número actual de elementos en la tabla

        int mid_square( int key, int n );
        int simple( char s[], int m );
        int gonnet99( char s[], int m );
        int koffman08( char s[], int m );
        int h( int key, int m );

        int quadratic_probing( int key, int i );
        int probe( int key, int i );

    public:    
        
        Map();
        Map( int size );

        bool Insert( Map* map, pair<int, Product> key );
        Product Search( Map* map, int key );
        bool Delete( Map* map, int key );

        void setSize( int size );
        void setLen( int len );

        float getLoadFactor();
        int getSize();
        int getLen();
};
