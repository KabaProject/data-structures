#include <iostream>

using namespace std;

template <class T>
class CircularQueue {
	public:
		CircularQueue(){};
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
bool CircularQueue<T>::is_empty(){
	return (this->head == -1 && this->tail == -1);
}

template <class T>
bool CircularQueue<T>::is_filled(){
	int diff = this->tail - this->head;

	return (diff == (this->MAX - 1) || diff == -1);
}

/**
 * Prints the CircularQueue elements located in its array
 */
template <class T>
void CircularQueue<T>::print(){
	
	cout << "Cola: [";

	for(int i = 0; i < this->MAX; i++){
		
		if(
			((this->head <= i && this->tail >= i && this->head <= this->tail) || 
			((this->head <= i || this->tail >= i) && this->head > this->tail)) &&
			!(this->is_empty())
		){
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
 * Add an element in the CircularQueue array until its filled
 * @param data Element to add
 */
template <class T>
void CircularQueue<T>::push(T data){
	if(this->is_filled()){
		throw (string) "Cola desbordada, dato no agregado.\n";
	}

	if((this->tail >= this->head && this->tail < (this->MAX - 1)) || (this->tail < this->head)){
		this->arr[++this->tail] = data;
	} else {
		this->tail = 0;
		this->arr[this->tail] = data;
	}
	
	if(this->head == -1) this->head = 0;
	// if(this->tail >= this->head && this->tail == (this->MAX - 1)){
	// 	this->tail = 0
	// 	this->arr[this->tail] = data;
	// }


	cout << "Dato agregado.\n";
	
	return;
}

/**
 * Remove an element in the CircularQueue array until its empty
 */
template <class T>
T CircularQueue<T>::pop(){
	if(this->is_empty()){
		throw (string) "Cola subdesbordada, dato no agregado.\n";
	}
	T data;

	if((this->tail > this->head && this->head < (this->MAX - 1)) || (this->tail < this->head && this->head < (this->MAX - 1))){
		data = this->arr[this->head++];
	}else if(this->tail == this->head){
		data = this->arr[this->head];
		this->head = -1;
		this->tail = -1;
	}else{
		data = this->arr[this->head];
		this->head = 0;
	}
	
	cout << "Dato removido.\n";
	return data;
}

