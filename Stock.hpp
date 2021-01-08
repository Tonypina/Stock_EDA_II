#ifndef Stock_INC
#define Stock_INC

#include "Map.hpp"

class Stock {

    private:

        Map map;

        void sortProducts();

    public:
        Stock( int max_size );

        bool createProduct( string id, Product product );
        bool deleteProduct( string id );
        bool addProduct( string id, int quantity );
        bool removeProduct( string id, int quantity );
        void print();
};

#endif   /* ----- #ifndef Stock_INC  ----- */