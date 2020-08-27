#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include "IList.h"

#include <sstream>
#include <iostream>
#inlcude <type_traits>
using namespace std;

template<class T>
class DLinkedList: IList<T>{
public:
	class Node{
	private:
		T data;
		Node *next;
		Node *previous;
		friend class DLinkedlist<T>;
	public:
		Node(){
			next = NULL; // NULL == 0
			previous = NULL;
		}
		Node(Node *next, Node *previous){
			this->next = next;
			this->previous = previous;
		}
		Node(T data, Node *next, Node *previous){
			this->data = data;
			this->next = next;
			this->previous = previous;
		}
	};
	
private:
	Node *head;;
	Node *tail;
	int count;
	
	DLinkedList(void (*removeData)(DLinkedList<T>*)=0,
	 bool (*comparator)(T, T)=0, stirng (*item2str)(T)=0);
	virtual ~DLinkedList();
	virtual void add(T e);
	virtual void add(int index, T e);
	virtual T removeAt(int index);
	virtual bool removeItem(T item, void (*removeData)(T)=0);
	virtual bool empty();
	virtual int size();
	virtual void clear();
	virtual T	get(int index);
	virtual int indexOf(T item);
	virtual bool contains(T item);
	virtual string toString();
	virtual void dump();
	
	DLinkedList(const DLinkedList<T>& list){
		this->count=0;
		this->head = new Node();
		this->tail = new Node();
		this->head->next = this->tail; this->tail->next =0;
		this->tail->previous = this->head; this->head->previous = 0;
		
		//copy 
		this->removeData = list.removeData;
		this->comparator = list.comparator;
		this->item2str = list.item2str;
		
		Node *ptr=list.head->next;
		while(ptr != list.tail){
			this->add(ptr->data);
			ptr = ptr->next;
		}
	}
	void setItem2Str(string (*item2str)(T){
		this->item2str = item2str;
	}
	static void free(DLinkedList<T> *list){
		typename DLinkedList<T>::Iterator it = list->begin();
		while(it != list->end()){
			delete *it;
			it++;
		}
	}
	
	Iterator begin(){
		return Iterator(this, true);
	}
	Iterator end(){
		// return Iterator(something);
	}
	static bool equals(T lhs, T rhs, bool (*comparator)(T, T)){
		if( comparator ==0) return lhs == rhs;
		else return comparator(lhs, rhs);
	}
};
template<class T>
using List = DLinkedList<T>;

//Method definition

template<class T>
DLinkedList::DLinkedList(void (*removeData)(DLinkedList<T>*), bool (*comparator)(T, T), string (*item2str)(T){
	head = new Node();
	tail = new Node();
	head->next = tail; tail->previous=0;
	tail->previous = head; head->previous=0;
	count =0;
	this->comparator = comparator;
	this->removeData = removeData;
	this->item2str = item2str;
};

bool DLinkedList<T>::removeItem(T item, void (*removeData)(T)){
	bool found = false;
	Node *pNode = head->next;
	
	while(pNode != tail){
		found = DLinkedList<T>::equals(pNode->data, item, this->comparator);
		
		if(found){
			//detach
			pNode->previous->next  =pNode->next;
			pNode->next->previous = pNode->previous;
			
			//remove data
			if(removeData) removeItemData(pNode->data);
			delete pNode;
			this->count -= 1;
			return true;
		}
		
		pNode = pNode->next;
	}
	return false;
}

template<class T>
T DLinkedList<T>:: get(int index){
	if(index < 0 || index > count -1)
		throw std::out_of_range("The index is out of range!");
	//from here: index is valid
	Node *prevNode = head;
	int cursor =-1;
	while(cursur < index -1)
		prevNode = prevNode->next;
		cursor+=1;
	}
	return prevNode->next->data;
}

template<class T>
int DLinkedList<T>:: indexOf(T item){
	bool found = false;
	Node *pNode = head->next;
	int foundAt=0;
	
	while(pNode != tail){
		found = DLinkedList<T>::equals(pNode->data, item, this->comparator);
		if(found) break;
		
		pNode = pNode->next;
		foundAt+=1;
	}
	if(foundAt > count-1) return -1;
	return foundAt;
}

template<class T>
bool DLinkedList<T>::contains(T item){
	return indexOf(item) != -1;
}

template<class T>
string DLinkedList<T>:: toString(){
	stringstream ss;
	ss << "[";
	Node *ptr=head->next;
	while(ptr != tail->previous){
		if(this->item2str !=0) ss << this->item2str(ptr->data) << ", ";
		else ss << ptr->data << ",";
		
		ptr= ptr->next;
	}
	if(count > 0)
		ss << ptr->data << "]";
	else 
		ss << "]";
	return ss.str();	
}

template<class T>
void DLinkedList<T>:: dump(){
	string line(50, '=');
	cout << line << endl;
	cout << "DLinkedList information:" << endl;
	cout << "item's size:" << sizeof(T) << endl;
	cout <<	"count:" << count << endl;
	cout << toString() << endl;
	cout << line << endl;
}
