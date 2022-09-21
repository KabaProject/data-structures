#include "circularqueue.h"
#include <iostream>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) {
	CircularQueue<int> queue;
	bool flag = false;
	bool error = false;
	int number;
	int option;
	char letter;

	do{
		
		system("CLS");
		if(cin.fail()) {
			cout << "[ERROR: Tipo de dato no valido]\n" << endl;
			cin.clear();
			cin.ignore(1, '\n');
		}

		cout << "Acciones disponibles \n\n";
		cout << "1) Insertar \n2) Extraer \n\nIngresa tu opcion: ";
		cin >> option;
		if(cin.fail()) continue;
		
		
		switch(option){
			case 1:
				do{
					if(cin.fail()) {
						cout << "[ERROR: Tipo de dato no valido]" << endl;
						cin.clear();
						cin.ignore(1, '\n');
					}
					
					cout << "\n\nNumero a insertar: ";
					cin >> number;
				}while(cin.fail());
					
				cout << "\n\n";
				
				try{
					queue.push(number);
				}catch(string s_error){
					cout << s_error;
				}
				
				queue.print();
				break;
			case 2:
				try{
					cout << "\n\n";
					number = queue.pop();
					cout << "Valor extraido: " << number << "\n";
				}catch(string s_error){
					cout << s_error;
				}

				queue.print();
				break;
			default:
				cout << "\n\n";
				cout << "Valor desconocido";
		}

		cout << "\n\nDesea continuar? (y/n): ";
		cin >> letter;

		if(letter != 'y') flag = true;

	}while(!flag);

	cout << "\nDatos finales: \n";
	queue.print();
	cout << "\n\nGracias por su visita :)";
}
