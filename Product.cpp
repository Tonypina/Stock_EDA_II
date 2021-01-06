#include "Product.hpp"

Product::Product(  ){
}

Product::Product( string id, string name, string type, float cost, int quantity ){

    this->id = id;
    this->name = name;
    this->type = type;
    this->cost = cost;
    this->quantity = quantity;
}

void Product::setId( string id ){
    this->id = id;
}

void Product::setName( string name ){
    this->name = name;
}

void Product::setType( string type ){
    this->type = type;
}

void Product::setCost( float cost ){
    this->cost = cost;
}

void Product::setQuantity( int quantity ){
    this->quantity = quantity;
}


string Product::getId(){
    return this->id;
}

string Product::getName(){
    return this->name;
}

string Product::getType(){
    return this->type;
}

float Product::getCost(){
    return this->cost;
}

int Product::getQuantity(){
    return this->quantity;
}
