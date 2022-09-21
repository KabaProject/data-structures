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
		/**
		 * Points the first element
		 */
		int head = -1;
		/**
		 * Points the last element
		 */
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

/**
 * Prints the Queue elements located in its array
 */
template <class T>
void Queue<T>::print(){
	
	cout << "Cola: [";

	for(int i = 0; i < this->MAX; i++){
		
		if(i >= this->head && i <= this->tail && this->head != -1){
			cout << this->arr[i];
		}else{
			cout << "  ";
		}
		
		if(i < this->MAX - 1){
			cout << ", ";
		}else{
			cout << "] ";
		}
		
	}
	
	if(this->is_empty()){
		cout << "(Vacia).";
	}

	if(this->is_filled()){
		cout << "(Llena).";
	}

	cout << "\n\nFRENTE: " << this->head + 1;
	cout << "\nFINAL: " << this->tail + 1 << "\n";
}

/**
 * Add an element in the Queue array until its filled
 * @param data Element to add
 */
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

/**
 * Remove an element in the Queue array until its empty
 */
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

