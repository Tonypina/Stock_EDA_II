#include "Map.hpp"

Map::Map(){
}

Map::Map( int size )
{
    this->len = 0;
    this->size = size;

    for( int i = 0; i < this->size; ++i ) this->table[ i ].first = EMPTY_CELL;
}

// Es la función hash

int Map::mid_square(int key, int n){
   int m = (3*n)/2;
   return (((key^2) % (10^m))/pow(10, (2*n)-m-1));
}

int Map::simple(char s[], int m){
   int sum = 0;
   for(size_t i = 0; i < m; i++){
      sum += s[i];
   }
   return (sum % m);
}

int Map::gonnet99(char s[], int m){
   int i;
   for(i = 0; *s; s++){
      i = (131*i) + (*s);
   }
   return (i % m);
}

int Map::koffman08(char s[], int m){
   int sum = 0;
   int n;

   for(n = 0; *s; s++){
      n++;
   }

   for(size_t i = 0; i < n-1; ++i){
      sum += ((31^(n-1-i))*s[i]);
   }
   return (sum % m);
}

int Map::h( int key, int m)
{
   //return key % m;
   return mid_square(key, m);
   //return koffman08(key, m);
}

// es la función de resolución de colisiones
int Map::quadratic_probing(int key, int i){
   return i^2;
}

int Map::probe( int key, int i ){
   //return i + 1;
   return quadratic_probing(key, i);
}

bool Map::Insert( Map* map, pair<int, Product> key )
{
   assert( map );
   assert( map->len < map->size );

   int pos;
   int home = pos = h( key.first, map->size );

   int i = 0;

   while( map->table[ pos ].first >= 0 ){
   // si el slot está ocupado, entonces tiene el valor de alguna llave,
   // y éstas son enteras positivas

      pos = ( home + probe( key.first, i ) ) % map->size;

      if( map->table[ pos ].first == key.first ) return false;
      // no se aceptan duplicados

      ++i;

   }

   map->table[ pos ] = key;
   ++map->len;

   return true;
}

Product Map::Search( Map* map, int key )
{
   assert( map );
   assert( map->len > 0 );

   int home = h( key, map->size );
   int pos = home;

   int i = 0;

   while( map->table[ pos ].first != EMPTY_CELL && map->table[ pos ].first != key ){

      if(map->table[pos].first == DELETED_CELL);

      pos = ( home + probe( key, i ) ) % map->size;

      ++i;
   }

   if( map->table[ pos ].first == key ){

      return map->table[ pos ].second;
      // en una aplicación del mundo real debería devolver los datos (value)
      // asociados a la llave (key), pero en este ejemplo, el propio valor de
      // key es el "value"

   } else{
        Product nullProduct( "null", "null", "null", 0, 0.0f );
        return nullProduct;
   }
}

bool Map::Delete( Map* map, int key )
{
   assert( map );
   assert( map->len > 0 );

   // busca el slot con la llave (prácticamente es el mismo código de Search())

   int home = h( key, map->size );
   int pos = home;

   int i = 0;
   while( map->table[ pos ].first != EMPTY_CELL && map->table[ pos ].first != key ){

      pos = ( home + probe( key, i ) ) % map->size;
      ++i;
   }

   if( map->table[ pos ].first == key ){

      map->table[ pos ].first = DELETED_CELL;
      return true;
      
   } else{
      return false;
   }
   // si no existe deberías terminar el programa inmediatamente (es un error borrar 
   // algo que no existe) pero en este ejemplo, y para poder realizar pruebas
   // unitarias (assert()), debes avisar que el slot no existe devolviendo "false"

   // si sí está, marca el slot como DELETED_CELL

   // decrementa el contador de slots ocupados

   // devuelve "true"
}

void Map::setSize( int size ){
    this->size = size;
}

void Map::setLen( int len ){
    this->len = len;
}

int Map::getSize(){
    return this->size;
}

int Map::getLen(){
    return this->len;
}

float Map::getLoadFactor(){
   return (this->len/(float)this->size);
}