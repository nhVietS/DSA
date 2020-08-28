#ifndef QUEUE_H
#define QUEUE_H

#include "DLinkedList.h"

template<class T>
class Queue{
private:
	DLinkedList<T> list;
public:
	Queue(){};
	void push(T item){
		list.add(item); // queue opposite side is used 
	}
	T pop(){
		return list.remove(0);
	}
	T peek(){
		return list.get(0);
	}
	bool empty(){
		return list.empty();
	}
	int size(){
		return list.size();
	}
};
#endif	
