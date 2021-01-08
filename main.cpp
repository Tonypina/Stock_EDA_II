#include <iostream>
#include "Stock.hpp"


void principalMenu(){
    system("cls");

    cout << "Bienvenido al sistema de inventario." << endl;

    cout << "Eliga una opción.\n" << endl;
    cout << "1. Reporte de inventario." << endl;
    cout << "2. Crear grupo." << endl;
    cout << "3. Eliminar grupo." << endl;
    cout << "4. Agregar producto." << endl;
    cout << "5. Retirar producto." << endl;
    cout << "6. Salir.\n" << endl;
    cout << "--> ";
}

char createGroupMenu( Stock* stock ){
    system("cls");

    cout << "\nCREAR PRODUCTO" << endl;

    string id;
    bool correct_tam = false;

    while( !correct_tam ){
        cout << "\nCódigo del producto a crear (7 digitos): ";
        cin >> id;
        if( id.size() != 7 ){
            cout << "\nTiene que tener exactamente 7 digitos." << endl;
        } else {
            correct_tam = true;
        }
    }

    cout << "\nNombre del producto a crear: ";
    string name;
    cin >> name;
    cout << "\nTipo del producto a crear: ";
    string type;
    cin >> type;
    cout << "\nPrecio del producto a crear: ";
    float cost;
    cin >> cost;
    cout << "\nCantidad del producto a crear: ";
    int quantity;
    cin >> quantity;

    Product product( name, type, cost, quantity );
    ( stock->createProduct( id, product ) ) ?
        cout << "Se creó el grupo correctamente." << endl:
        cout << "El grupo ya existe." << endl;

    cout << "¿Desea crear otro?" << endl;
    char opcion;
    cin >> opcion;
    return opcion;
}

char deleteGroupMenu( Stock* stock ){
    system("cls");
    
    cout << "\nELIMINAR PRODUCTO" << endl;
    
    cout << "\nID del grupo a eliminar: ";
    string id;
    cin >> id;

    ( stock->deleteProduct( id ) )?
        cout << "Se eliminó correctamente." << endl:
        cout << "No se pudo eliminar el producto." << endl;

    cout << "¿Desea eliminar otro?" << endl;
    char opcion;
    cin >> opcion;
    return opcion;
}

char addProductMenu( Stock* stock ){
    system("cls");
   
    cout << "\nAGREGAR PRODUCTO" << endl;
   
    cout << "\nID del producto: ";
    string id;
    cin >> id;
    cout << "\nCantidad de producto a agregar: ";
    int quantity;
    cin >> quantity;

    ( stock->addProduct( id, quantity ) )?
        cout << "Se agregó con éxito." << endl:
        cout << "No se pudo agregar." << endl;

    cout << "¿Desea volver a agregar?" << endl;
    char opcion;
    cin >> opcion;
    return opcion;
}

char removeProductMenu( Stock* stock ){
    system("cls");
    
    cout << "\nRETIRAR PRODUCTO" << endl;
    
    cout << "\nID del producto:";
    string id;
    cin >> id;
    cout << "\nCantidad del producto a retirar:";
    int quantity;
    cin >> quantity;

    ( stock->removeProduct( id, quantity ) )?
        cout << "Se retiró con éxito." << endl:
        cout << "No se pudo retirar." << endl;

    cout << "¿Desea volve a retirar?" << endl;
    char opcion;
    cin >> opcion;
    return opcion;
}


int main(){

    Stock stock( HASH_SIZE );

    for(;;){
        principalMenu();

        int opcion;
        cin >> opcion;

        switch (opcion) {
            case 1:
                stock.print();
                system("pause");
                continue;
            case 2:
                while( createGroupMenu( &stock ) != 'N' );
                continue;
            case 3:
                while( deleteGroupMenu( &stock ) != 'N' );
                continue;
            case 4:
                while( addProductMenu( &stock ) != 'N' );
                continue;
            case 5:
                while( removeProductMenu( &stock ) != 'N' );
                continue;
            case 6:
                break;
            default:
                cout << "Opción inválida." << endl;
                continue;
        }
        break;
    }
}