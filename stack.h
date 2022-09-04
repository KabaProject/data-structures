#include <iostream>

using namespace std;

template <class T>
class Stack {
	public:
		Stack(){};
		void push(T);
		T pop();
		bool is_filled();
		bool is_empty();
		void print();
		
	private:
		int MAX = 7;
		T arr[7];
		int pos = -1;
};

template <class T>
bool Stack<T>::is_empty(){
	return (this->pos <= -1);
}

template <class T>
bool Stack<T>::is_filled(){
	return (this->pos >= this->MAX - 1);
}

template <class T>
void Stack<T>::print(){
	
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

template <class T>
void Stack<T>::push(T data){
	if(this->is_filled()){
		throw (string) "Pila desbordada, dato no agregado.\n";
	}
	
	this->arr[this->pos + 1] = data;
	this->pos++;
	
	cout << "Dato agregado.\n";
	
	return;
}

template <class T>
T Stack<T>::pop(){
	if(this->is_empty()){
		throw (string) "Pila subdesbordada, dato no agregado.\n";
	}
	
	T data = this->arr[this->pos];
	this->pos--;
	
	cout << "Dato removido.\n";
	return data;
}

