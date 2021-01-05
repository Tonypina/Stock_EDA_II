#include <string>

using namespace std;

class Product {

    private:

        std::string id;
        std::string name;
        std::string type;
        float       cost;
        int         quantity;

    public:

        Product();
        Product( string id, string name, string type, float cost );

        void setId( string id );
        void setName( string name );
        void setType( string type );
        void setCost( float cost );
        void setQuantity( int quantity );

        string getId();
        string getName();
        string getType();
        float  getCost();
        int    getQuantity();
};
