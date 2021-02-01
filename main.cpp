#include <iostream>
#include "Stock.hpp"

/**
 * @brief Pausa y limpia la pantalla
 */
void clear_screen(){
  printf("Presione 'Enter' para continuar...");
  setbuf(stdin, NULL);
  getchar();
  system("clear");
}

/**
 * @brief Muestra el menú principal del sistema
 *
 */
void principalMenu(){
    system("clear");

    std::cout << "Bienvenido al sistema de inventario." << std::endl;

    std::cout << "Eliga una opción.\n" << std::endl;
    std::cout << "1. Reporte de inventario." << std::endl;
    std::cout << "2. Crear grupo." << std::endl;
    std::cout << "3. Eliminar grupo." << std::endl;
    std::cout << "4. Agregar producto." << std::endl;
    std::cout << "5. Retirar producto." << std::endl;
    std::cout << "6. Salir.\n" << std::endl;
    std::cout << "--> ";
}

/**
 * @brief Muestra el menú de creación
 * 
 * @param stock Referencia de objeto Stock
 * @return char Opción de salida
 */
char createGroupMenu( Stock* stock ){
    system("clear");

    std::cout << "\nCREAR PRODUCTO" << std::endl;

    std::string id;
    bool correct_tam = false;

    while( !correct_tam ){
        std::cout << "\nCódigo del producto a crear (7 digitos): ";
        std::cin >> id;
        if( id.size() == 7 ){
            ( stock->existsProduct( id ) ) ?
                correct_tam = true:
                printf("Este producto ya existe.\n");
        } else {
            std::cout << "\nTiene que tener exactamente 7 digitos." << std::endl;
        }
    }

    std::cout << "\nNombre del producto a crear: ";
    std::string name;
    std::cin >> name;
    std::cout << "\nTipo del producto a crear: ";
    std::string type;
    std::cin >> type;
    std::cout << "\nPrecio del producto a crear: ";
    float cost;
    std::cin >> cost;
    std::cout << "\nCantidad del producto a crear: ";
    int quantity;
    std::cin >> quantity;

    Product product( name, type, cost, quantity );
    ( stock->createProduct( id, product ) ) ?
        std::cout << "Se creó el grupo correctamente." << std::endl:
        std::cout << "El grupo ya existe." << std::endl;

    std::cout << "¿Desea crear otro?" << std::endl;
    char opcion;
    std::cin >> opcion;
    return opcion;
}

/**
 * @brief Muestra el menú de destrucción
 * 
 * @param stock Referencia de objeto Stock
 * @return char Opción de salida
 */
char deleteGroupMenu( Stock* stock ){
    system("clear");
    
    std::cout << "\nELIMINAR PRODUCTO" << std::endl;
    
    std::cout << "\nID del grupo a eliminar: ";
    std::string id;
    std::cin >> id;

    ( stock->deleteProduct( id ) )?
        std::cout << "Se eliminó correctamente." << std::endl:
        std::cout << "No se pudo eliminar el producto." << std::endl;

    std::cout << "¿Desea eliminar otro?" << std::endl;
    char opcion;
    std::cin >> opcion;
    return opcion;
}

/**
 * @brief Mustra el menú de adición
 * 
 * @param stock Referencia de objeto Stock
 * @return char Opción de salida
 */
char addProductMenu( Stock* stock ){
    system("clear");
   
    std::cout << "\nAGREGAR PRODUCTO" << std::endl;
   
    std::cout << "\nID del producto: ";
    std::string id;
    std::cin >> id;
    std::cout << "\nCantidad de producto a agregar: ";
    int quantity;
    std::cin >> quantity;

    ( stock->addProduct( id, quantity ) )?
        std::cout << "Se agregó con éxito.\n" << std::endl:
        std::cout << "No se pudo agregar.\n" << std::endl;

    std::cout << "¿Desea volver a agregar?" << std::endl;
    char opcion;
    std::cin >> opcion;
    return opcion;
}

/**
 * @brief Muestra el menú de disminución
 * 
 * @param stock Referencia de objeto Stock
 * @return char Opción de salida
 */
char removeProductMenu( Stock* stock ){
    system("clear");
    
    std::cout << "\nRETIRAR PRODUCTO" << std::endl;
    
    std::cout << "\nID del producto:";
    std::string id;
    std::cin >> id;
    std::cout << "\nCantidad del producto a retirar:";
    int quantity;
    std::cin >> quantity;

    ( stock->removeProduct( id, quantity ) )?
        std::cout << "Se retiró con éxito." << std::endl:
        std::cout << "No se pudo retirar." << std::endl;

    std::cout << "¿Desea volve a retirar?" << std::endl;
    char opcion;
    std::cin >> opcion;
    return opcion;
}

int main(){

    Stock stock( HASH_SIZE );
    stock.deserialize();

    for(;;){
        principalMenu();

        int opcion;
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                stock.print();
                clear_screen();
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
                stock.serialize();
                break;
            default:
                std::cout << "Opción inválida." << std::endl;
                continue;
        }
        break;
    }
}
