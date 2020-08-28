#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

template<class T> class SLinkedlist;

template<class T>
class Node{
private:
	T data;
	Node<T> *next;
	friend class SLinkedlist<T>;
public:
	Node(){
		this->next = NULL; // NULL == 0
	}
	Node(Node<T> *next){
		this->next = next;
	}
	Node(T data, Node<T> *next){
		this->data = data;
		this->next = next;
	}
};
template<class T>
class SLinkedlist{
private:
	Node<T> *head;
	Node<T> *tail;
	int count;
public:
	SLinkedlist(){
		head = new Node<T>();
		tail = new Node<T>();
		head->next = tail;
		tail->next = head;
		count= 0;
	}
	bool append(const T& e){
		Node<T> *node = new Node<T>(e, tail);
		if(node == NULL) return false;
		tail->next->next = node;
		tail->next = node;
		count+=1;
		return true;
	};
	bool prepend(const T& e){
		Node<T> *firstnode = head->next;
		Node<T> *node = new Node<T>(e, firstnode);
		if(node == NULL) return false;
		head->next = node;
		count+=1;
		return true;
	};
	bool insert(int index, const T& e){
		if(index < 0 || index > count)
			throw ("The index is out of bound");
		// index in [0, count]
		Node<T>* newNode = new Node<T>(e, 0); 
		if(newNode == NULL) return false;
		Node<T>* prevNode = head;
		int cursor = -1;
		// 
		while(cursor < index -1){
			prevNode = prevNode->next;
			cursor+=1;
		}
		// add newNode
		Node<T>* curNode = prevNode->next;
		prevNode->next = newNode;
		newNode->next = curNode;
		//missing ? change tail->next if needed (at none or full list)
		if(index == count)
			tail->next = newNode;
			
		count +=1;
		return true;
	};
	
	bool removeHead(T& item){
		// in implement head pointer always ->(tail node) so not have line below
		//if(head==NULL) return false; 
		
		Node<T>* prevNode = head;
		Node<T>* curNode = prevNode->next;
		prevNode->next= curNode->next;
		curNode->next =0;//=NULL
		count-=1;
		item= curNode->data;
		delete curNode;		
		return true;		
	};
	bool removeTail(T& item){
		Node<T>* prevNode = head;
		int cursor = -1;
		// 
		while(cursor < count -2){
			prevNode = prevNode->next;
			cursor+=1;
		}
		Node<T> *curNode = prevNode->next;
		prevNode->next= curNode->next;
		curNode->next =0;//=NULL
		tail->next = prevNode;
		count-=1;
		item = curNode->data;
		delete curNode;
		return true;		
	};
	bool remove(int index, T& item){
		if(index < 0 || index > count -1)
			throw std::out_of_range("The index is out of bound");
		Node<T>* prevNode = head;
		int cursor = -1;
		// 
		while(cursor < index -1){
			prevNode = prevNode->next;
			cursor+=1;
		}
		//here: prevNode points to previous item[at index -1] 
		Node<T> *curNode = prevNode->next;
		prevNode->next= curNode->next;
		curNode->next =0;//=NULL
		if(index == count)
			tail->next = prevNode;
		count -=1;
		item= curNode->data;
		delete curNode;
		return true;
	};
	
	T get(int index){
		if(index < 0 || index > count -1)
			throw std::out_of_range("The index is out of bound");
		Node<T>* prevNode = head;
		int cursor = -1;
		// 
		while(cursor < index -1){
			prevNode = prevNode->next;
			cursor+=1;
		}
		return prevNode->next->data;
	};
	
	bool empty(){
		return count == 0;
	}
	int size(){
		return count;
	};
	int indexOf(T e){
		Node<T>*ptr = head->next;
		int foundAt = 0;
		while(ptr != tail){
			if(ptr->data == e)
				break;
			ptr = ptr->next;
			foundAt+=1;
		}
		if (foundAt >count -1) return -1;
		return foundAt;
	};
	void println(){
		Node<T> *ptr = head->next;
		while(ptr != tail){
			cout << ptr->data << " ";	
			ptr = ptr->next;		 
		}
		cout << endl;
	}
};

int main()
{
	SLinkedlist<double> slist1;
	for(int i=0; i<=5; i++)
		slist1.insert(i,i*12.34);
	slist1.println();
	slist1.prepend(11.11);
	slist1.println();
	slist1.append(99.99);
	slist1.println();
	double res;
	slist1.removeHead(res);
	slist1.println();
	slist1.removeTail(res);
	slist1.println();
	cout << slist1.indexOf(12.34)<< endl;
	cout << slist1.indexOf(4.4)<< endl;
	cout << slist1.get(3) << endl;
	return 0;
}
