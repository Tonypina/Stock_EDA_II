#include "Map.hpp"

Map::Map(){
}

Map::Map( int max_size )
{
    this->max_size = max_size;
    Product void_prod( "null", "null", 0.0, 0 );

    for( size_t i = 0; i < this->max_size; ++i ){

        this->table.push_back( make_pair( EMPTY_CELL, void_prod ) );
    }
}

// Es la función hash

int Map::simple( string key, int m ){
   int sum = 0;
   for(size_t i = 0; i < key.size(); i++){
      sum += key.c_str()[i];
   }
   return (sum % m);
}

int Map::h( string key, int m)
{
    return simple( key, m );
}

// es la función de resolución de colisiones

int Map::probe( string key, int i ){
    return i + 1;
}

bool Map::Insert( pair< string, Product > key)
{
    assert( this );
    assert( this->table.size() <= this->max_size );

    int pos;
    int home = pos = h( key.first, this->max_size );

    int i = 0;

    while( this->table[ pos ].first.compare( EMPTY_CELL ) != 0 ){

        if( this->table[ pos ].first.compare( key.first ) == 0 ) return false;

        pos = ( home + probe( key.first, i ) ) % this->max_size;

        ++i;
    }

    this->table[ pos ] = key;    
    return true;
}

Product Map::Search( string key )
{
    assert( this );

    int home = h( key, this->max_size );
    int pos = home;

    int i = 0;

    while( ( this->table[ pos ].first.compare( EMPTY_CELL ) != 0 && this->table[ pos ].first.compare( key ) != 0 ) || this->table[ pos ].first.compare( DELETED_CELL ) == 0){

        pos = ( home + probe( key, i ) ) % this->max_size;

        ++i;
    }

    if( this->table[ pos ].first == key ){

        return this->table[ pos ].second;

    } else{
        Product nullProduct( "null", "null", 0.0, 0 );
        return nullProduct;
    }
}

bool Map::Delete( string key )
{
    assert( this );
    assert( this->table.size() > 0 );

    int home = h( key, this->max_size );
    int pos = home;

    int i = 0;
    while( this->table[ pos ].first.compare( EMPTY_CELL ) != 0 && this->table[ pos ].first.compare( key ) != 0 ){

        pos = ( home + probe( key, i ) ) % this->max_size;
        ++i;
    }

    if( this->table[ pos ].first.compare( key ) == 0 ){

        this->table[ pos ].first = DELETED_CELL;
        return true;
        
    } else {

        return false;
    }
}

void Map::swap(pair<string, Product>* val1, pair<string, Product>* val2){
    pair<string, Product> tmp = *val1;
    *val1 = *val2;
    *val2 = tmp;
}

void Map::Sort( int first, int last ){

    int x0 = first;
    int x1 = last;
    int mid = (first + last)/2;
    auto piv = this->table[mid];

    while( x0 <= x1){

        while( this->table[x0].second.getName() < piv.second.getName() ){
            x0++;
        }

        while(this->table[x1].second.getName() > piv.second.getName() ){
            --x1;
        }

        if(x0 <= x1){
            swap(&this->table[x0], &this->table[x1]);
            x0++;
            x1--;
        }
    }

    if(first < x1){
        Sort( first, x1 );
    }

    if(x0 < last){
        Sort( x0, last );
    }
}

void Map::setSize( int max_size ){

    this->max_size = max_size;
    Product void_prod( "null", "null", 0.0, 0 );

    for( size_t i = 0; i < this->max_size; ++i ){

        this->table.push_back( make_pair( EMPTY_CELL, void_prod ) );
    }
}

int Map::getSize(){
    return this->max_size;
}

int Map::getLen(){
    return this->table.size();
}

float Map::getLoadFactor(){
   return ( this->table.size()/(float)this->max_size );
}

void Map::print(){
    for( size_t i = 0; i < this->max_size; ++i ){
        if( this->table[i].first.compare( EMPTY_CELL ) != 0 ){
            cout << "\t" << this->table[i].first 
                << "\t\t" << this->table[i].second.getName()
                << "\t\t" << this->table[i].second.getType()
                << "\t\t" << this->table[i].second.getCost()
                << "\t\t" << this->table[i].second.getQuantity() 
                << endl;
        }
    }
}