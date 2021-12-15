#include "Objeto.hpp"
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <ctime>
#include <cstdlib>
class Caja{
    vector<Objeto*> objetos;
public:
    Caja(){
        fstream file("objetos.csv", ios::in);

		if (!file.is_open()) {
			cout << "No se pudo abrir el archivo.\n";
			exit(1);
		}

		string line;
		getline(file, line);

		while (getline(file, line)) {
			Objeto* nuevo = new Objeto();
			stringstream ss(line);
			string token;
			getline(ss, token, ',');
            stringstream ssInt;
			int auxInt;
            ssInt<<token;
			ssInt>>auxInt;
            nuevo->setId(auxInt);
			getline(ss, token, ',');
			nuevo->nombre = token;
			getline(ss, token, ',');
			nuevo->descripcion = token;
			objetos.push_back(nuevo);
		}
    }

    vector<Objeto*> getObjetos(){
        return this->objetos;
    }

	void dado(){
		srand((unsigned) time(0));
  		int randomNumber;
    	randomNumber = (rand() % 100) + 1;
		cout<<randomNumber<<endl;
		int random = (rand() % 100) + 1;
		cout<<random;
    	//return randomNumber;
	}

	void obtenerPremio(){
		srand((unsigned) time(0));
		int primerDado = (rand() % 100) + 1;
		int segundoDado = (rand() % 4) + 0;
		int tercerDado = (rand() % 9) + 5;
		int cuartoDado = (rand() % 14) + 10;
		if (primerDado < 60){
			cout<<"Tu premio es: "<<objetos.at(segundoDado)->nombre;
		}
		else if (primerDado >= 60 && primerDado <= 80){
			cout<<"Tu premio es: "<<objetos.at(tercerDado)->nombre;
		}
		else cout<<"Tu premio es: "<<objetos.at(cuartoDado)->nombre;
	}
};