#include <iostream>
#include <string>
using namespace std;

class Objeto{
    int id;
public:
    string nombre;
    string descripcion;
    Objeto(){id = 0; nombre = ""; descripcion="";}
    void setId(int n){
        this->id = n;
    }
};