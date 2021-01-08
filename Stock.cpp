#include <iostream>
#include "Stock.hpp"

Stock::Stock( int max_size ){
    this->map.setSize( max_size );
}

bool Stock::createProduct( string id, Product product ){

    if ( this->map.Insert( make_pair( id, product ) ) ) {
        this->map.Sort( 0, this->map.getSize()-1 );
        return true;
    }
    return false;
}

bool Stock::deleteProduct( string id ){

    if( this->map.Delete( id ) ){
        this->map.Sort( 0, this->map.getSize()-1 );
        return true;
    }
    return false;
}

bool Stock::addProduct( string id, int quantity ){
    Product add = this->map.Search( id );

    if( add.getName().compare( "null" ) != 0 ){
        add.setQuantity( add.getQuantity() + quantity );
        return true;
    }
    return false;
}

bool Stock::removeProduct( string id, int quantity ){
    Product remove = this->map.Search( id );

    if( remove.getName().compare("null") != 0 ){
        if( remove.getQuantity() > quantity ){    
            remove.setQuantity( remove.getQuantity() - quantity );
            return true;
        }
    }
    return false;
}

void Stock::print(){
    system("cls");

    cout << "REPORTE DE INVENTARIO." << endl;

    cout << "\tCODIGO\t\tPRODUCTO\t\tCATEGORIA\t\tPRECIO\t\tCANTIDAD\n" << endl;
    this->map.print();
}
