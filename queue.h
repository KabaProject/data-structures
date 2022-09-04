#include <iostream>

using namespace std;

template <class T>
class Queue {
	public:
		Queue(){};
		void push(T);
		T pop();
		bool is_filled();
		bool is_empty();
		void print();
		
	private:
		static const int MAX = 7;
		T arr[MAX];
		int head = -1;
		int tail = -1;
};

template <class T>
bool Queue<T>::is_empty(){
	return (this->head == -1);
}

template <class T>
bool Queue<T>::is_filled(){
	return (this->tail >= this->MAX - 1);
}

template <class T>
void Queue<T>::print(){
	
	cout << "Cola: [";

	if(this->is_empty()){
		cout << "] (Vacia).\n";
		return;
	}

	for(int i = this->head; i <= this->tail; i++){
		if(i < this->tail){
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
void Queue<T>::push(T data){
	if(this->is_filled()){
		throw (string) "Cola desbordada, dato no agregado.\n";
	}
	
	this->arr[++this->tail] = data;

	if(this->tail == 0) this->head = 0;
	if(this->head == -1 && this->tail != -1) this->head = this->tail;
	
	cout << "Dato agregado.\n";
	
	return;
}

template <class T>
T Queue<T>::pop(){
	if(this->is_empty()){
		throw (string) "Cola subdesbordada, dato no agregado.\n";
	}
	
	T data = this->arr[this->head++];

	if(this->head > this->tail) this->head = -1;
	
	cout << "Dato removido.\n";
	return data;
}

