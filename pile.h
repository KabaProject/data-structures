#include <iostream>

using namespace std;

class Pile {
	public:
		Pile(){};
		void push(int);
		int pop();
		bool is_filled();
		bool is_empty();
		void print();
		
	private:
		int MAX = 7;
		int arr[7];
		int pos = -1;
};

bool Pile::is_empty(){
	return (this->pos <= -1);
}

bool Pile::is_filled(){
	return (this->pos >= this->MAX - 1);
}

void Pile::print(){
	
	cout << "Pila: [";

	if(this->is_empty()){
		cout << "] (Vacia).\n";
		return;
	}

	for(int i = 0; i <= this->pos; i++){
		if(i < this->pos){
			cout << this->arr[i] << ", ";
		}else{
			cout << this->arr[i] << "] ";
		}
	}

	if(this->is_filled()){
		cout << "(Llena).\n";
	}
}

void Pile::push(int data){
	if(this->is_filled()){
		throw (string) "Pila desbordada, dato no agregado.\n";
	}
	
	this->arr[this->pos + 1] = data;
	this->pos++;
	
	cout << "Dato agregado.\n";
	
	return;
}

int Pile::pop(){
	if(this->is_empty()){
		throw (string) "Pila subdesbordada, dato no agregado.\n";
	}
	
	int data = this->arr[this->pos];
	this->pos--;
	
	cout << "Dato removido.\n";
	return data;
}

