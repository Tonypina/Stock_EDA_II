/**
 * @file Map.cpp
 * @brief Definiciones de la clase Map
 * @version 0.1
 * @date 2021-01-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Map.hpp"

Map::Map(){
}

/**
 * @brief Construct a new Map:: Map object
 * 
 * @param max_size Tamaño máximo de la hash
 */
Map::Map( int max_size )
{
    this->max_size = max_size;
    this->len = 0;

    Product void_prod( "null", "null", 0.0, 0 );

    for( size_t i = 0; i < this->max_size; ++i ){

        this->table.push_back( std::make_pair( EMPTY_CELL, void_prod ) );
    }
}

/**
 * @brief Función hash
 * 
 * @param key llave string
 * @param m Tamaño de la hash
 * @return int Cálculo de la hash
 */
int Map::simple( std::string key, int m ){
   int sum = 0;
   for(size_t i = 0; i < key.size(); i++){
      sum += key.c_str()[i];
   }
   return (sum % m);
}

int Map::h( std::string key, int m)
{
    return simple( key, m );
}

/**
 * @brief Función de solución de colisiones
 * 
 * @param key Llave string
 * @param i Movimiento de la función
 * @return int Cálculo de la función de colisiones
 */
int Map::probe( std::string key, int i ){
    return i + 1;
}

/**
 * @brief Inserta un registro en la hash
 * 
 * @param key Par a insertar en la hash
 * @return true Si se pudo insertar
 * @return false Si no se pudo insertar
 */
bool Map::Insert( std::pair< std::string, Product > key)
{
    assert( this );

    int pos;
    int home = pos = h( key.first, this->max_size );

    int i = 0;

    while( this->table[ pos ].first.compare( EMPTY_CELL ) != 0 ){

        if( this->table[ pos ].first.compare( key.first ) == 0 ) return false;

        pos = ( home + probe( key.first, i ) ) % this->max_size;

        ++i;
    }

    this->table[ pos ] = key;
    ++this->len;

    return true;
}

/**
 * @brief Busca un registro en la hash
 * 
 * @param key Llave a buscar
 * @return Product* Referencia a un objeto Product
 */
Product* Map::Search( std::string key )
{
    assert( this );

    int home = h( key, this->max_size );
    int pos = home;

    int i = 0;

    while(  this->table[ pos ].first.compare( EMPTY_CELL ) != 0 && this->table[ pos ].first.compare( key ) != 0 ){
        pos = ( home + probe( key, i ) ) % this->max_size;
        ++i;   
    }

    if( this->table[ pos ].first.compare( key ) == 0 ){ 

        return &(this->table[ pos ].second);

    } else{
        return nullptr;
    }
}

/**
 * @brief Borra un registro de la hash
 * 
 * @param key Llave para identificar el registro a borrar
 * @return true 
 * @return false 
 */
bool Map::Delete( std::string key )
{
    assert( this );

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

/**
 * @brief Método privado para intercambiar valores en Sort
 * 
 * @param val1 
 * @param val2 
 */
void Map::swap(std::pair<std::string, Product>* val1, std::pair<std::string, Product>* val2){
    std::pair<std::string, Product> tmp = *val1;
    *val1 = *val2;
    *val2 = tmp;
}

/**
 * @brief Algoritmo de ordenamiento QuickSort adaptado a Productos
 * 
 * @param first Primer índice del vector
 * @param last Segundo índice del vector
 */
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
        #pragma omp task shared(first, x1)
        {
            Sort( first, x1 );
        }
    }

    if(x0 < last){
        #pragma omp task shared(x0, last)
        {
            Sort( x0, last );
        }
    }
}

/**
 * @brief Setter del tamaño máximo de la hash
 * 
 * @param max_size Tamaño máximo de la hash
 */
void Map::setSize( int max_size ){

    this->max_size = max_size;
    Product void_prod( "null", "null", 0.0, 0 );

    for( size_t i = 0; i < this->max_size; ++i ){

        this->table.push_back( std::make_pair( EMPTY_CELL, void_prod ) );
    }
}

/**
 * @brief Getter del tamaño máximo de la hash
 * 
 * @return int Tamañano de la hash
 */
int Map::getSize(){
    return this->max_size;
}

/**
 * @brief Getter del tamaño actual de la hash
 * 
 * @return int 
 */
int Map::getLen(){
    return this->len;
}

/**
 * @brief Regresa el factor de carga de la hash
 * 
 * @return float Factor de carga de la hash
 */
float Map::getLoadFactor(){
   return ( this->len/(float)this->max_size );
}

/**
 * @brief Imprime la hash
 * 
 */
void Map::print(){
    for( size_t i = 0; i < this->max_size; ++i ){
        if( this->table[i].first.compare( EMPTY_CELL ) != 0 && this->table[i].first.compare( DELETED_CELL ) != 0 ){
            std::cout << "\t" << this->table[i].first 
                << "\t\t" << this->table[i].second.getName()
                << "\t\t" << this->table[i].second.getType()
                << "\t\t" << this->table[i].second.getCost()
                << "\t\t" << this->table[i].second.getQuantity() 
                << std::endl;
        }
    }
}

/**
 * @brief Serializa los objetos guardados en el mapa en un json
 * 
 */
void Map::Serialize() {

    std::vector<std::pair<std::string, Product>> json;

    for (auto& p : this->table) {
        if (p.first.compare(EMPTY_CELL) != 0) {
            json.push_back(p);
        }
    }

    FILE* file = fopen("stock.json", "w");

    std::string str;

    str = "{\n";
    str += "\"products\" : [\n";

    size_t productos_size = json.size();
    for (auto& p : json) {
        if (productos_size != 1) {
            str += "\t{ \"id\" : \"" + p.first + "\""
                + ", \"name\" : \"" + p.second.getName() + "\""
                + ", \"type\" : \"" + p.second.getType() + "\""
                + ", \"cost\" : " + std::to_string(p.second.getCost())
                + ", \"quantity\" : " + std::to_string(p.second.getQuantity())
                + " },\n";
        } else {
            str += "\t{ \"id\" : \"" + p.first + "\""
                + ", \"name\" : \"" + p.second.getName() + "\""
                + ", \"type\" : \"" + p.second.getType() + "\""
                + ", \"cost\" : " + std::to_string(p.second.getCost())
                + ", \"quantity\" : " + std::to_string(p.second.getQuantity())
                + " }\n";
        }
        --productos_size;
    }

    str += "]\n";
    str += "}";

    fputs(str.c_str(), file);

    fclose(file);
}

/**
 * @brief Deserealiza los objetos de un archivo json
 * 
 */
void Map::Deserialize() {

}
