#ifndef STACK_H
#define STACK_H

#include <list>

#include "DLinkedList.h"

template<class T>
class Stack{
private:
	DLinkedList<T> list;
	void (*removeData)(DLinkedList<T>*);
	bool (*comparator)(T lhs, T rhs);
public:
	Stack(void (*removeData)(DLinkedList<T>*)=0, bool (*comparator)(T, T)=0){
		this->comparator = comparator;
		this->removeData = removeData;
	}
	void push(T item){
		list.add(0, item); // at the begin, at the end use: list.size() -1;
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
	bool remove(T item){
		int index = this->list.indexOf(item);
		if(index != -1){
			this->list.remove(index);
			return true;
		}
		else return false;
	}
	bool contains(T item){
		bool found = false;
		typename DLinkedList<T>::Iterator it = list.begin();
		while(it != list.end()){
			found = equals(*it, item, this->comparator);
			if(found) break;
			it++;
		}
		return found;
	}
private:
	static bool equals(T lhs, T rhs, bool (*comparator)(T, T){
		if(comparator == 0) return lhs == rhs;
		else return comparator(lhs, rhs);
	}
};
		
#endif