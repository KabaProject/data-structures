#include "pile.h"
#include <iostream>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) {
	Pile pile;
	bool flag = false;
	int number;
	int option;
	char letter;

	do{

		system("CLS");

		cout << "Acciones disponibles \n\n";
		cout << "1) Insertar \n2) Extraer \n\nIngresa tu opcion: ";
		cin >> option;
		
		switch(option){
			case 1:
				cout << "\n\nNumero a insertar: ";
				cin >> number;
				cout << "\n\n";
				
				pile.push(number);
				pile.print();
				break;
			case 2:
				try{
					cout << "\n\n";
					number = pile.pop();
					cout << "Valor extraido: " << number << "\n";
				}catch(string error){
					cout << error;
				}

				pile.print();
				break;
			default:
				cout << "\n\n";
				cout << "Valor desconocido";
		}

		cout << "\n\nDesea continuar? (y/n): ";
		cin >> letter;

		if(letter != 'y') flag = true;

	}while(!flag);

	cout << "Datos finales: \n";
	pile.print();
	cout << "\n\nGracias por su visita :)";
}
