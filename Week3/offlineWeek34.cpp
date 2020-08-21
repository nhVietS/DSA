#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
/*
 * inner class Node inside the DLL
 */


template<class T>
class DLinkedlist: IList<T>{
private:
	Node *head;
	Node *tail;
	int count;
	
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
}
template<class T>
DLinkedList<T>::DLinkedList(){
	head=new Node();
	tail=new Node();
	count=0;
	head->next = tail; tail->next =0;
	tail->previous = head; head->previous=0;
}
template<class T>
DLinkedList<T>::~DLinkedList(){
	/* remove node pointed by ptr
	 * clients: must remove their data
	 */
	 if(removeData !=0) removeData(this); // remove pointer to object
	 
	 Node *ptr = head->next;
	 while(ptr != tail){
		 Node *next = ptr->next;
		 delete ptr;
		 ptr = next;	 
}
template<class T>
void DLinkedList::add(T e){
	Node node = new Node(e, tail, tail->previous);
	tail->previous->next = node;
	tail->previous= node;
	count==1;
}
template<class T>
void DLinkedList::add(int index, T e){
	if(index < 0 || index >count)
		throw std::out_of_range("The index is out of range");
	// index in [0, count]
	Node* newNode = new Node(e,0,0);
	Node* prevNode = head;
	int cursor =-1;
	while(cursor < index -1){ // cursor largest =2, index=3
		prevNode = prevNode->next;
		cursor+=1;
	}
	
	//add newNode
	Node *curNode = prevNode->next;
	// prevNode = newNode;
	newNode->next = curNode;
	newNode->previous = prevNode;
	prevNode->next = newNode;
	curNode->previous = newNode;
	
	//change tail->next if needed
	if(index == count)
		tail->previous= newNode;
	count +=1;
}
template<class T>
T DLinkedList::remove(int index){
	if(index < 0 || index >count-1)
		throw std::out_of_range("The index is out of range");
		
	//from here: index is valid
	Node* prevNode = head;
	int cursor =-1;
	while(cursor < index -1){ // cursor largest =2, index=3
		prevNode = prevNode->next;
		cursor+=1;
	}
	Node *curNode = prevNode->next;
	prevNode->next = curNode->next;
	curNode->next->previous = prevNode;
	curNode->next=0;
	curNode->prev=0;
	T data= curNode->data;
	delete curNode;
	if(index == count-1)
		tail->previous= prevNode;
	count -=1;
	return data;
}
template<class T>
T DLinkedList::get(int index){
	if(index < 0 || index >count-1)
		throw std::out_of_range("The index is out of range");
		
	//from here: index is valid
	Node* prevNode = head;
	int cursor =-1;
	while(cursor < index -1){ // cursor largest =2, index=3
		prevNode = prevNode->next;
		cursor+=1;
	}
	Node *curNode = prevNode->next;
	prevNode->next = curNode->next;
	curNode->next->previous = prevNode;
	curNode->next=0;
	curNode->prev=0;
	T data= curNode->data;
	delete curNode;
	if(index == count-1)
		tail->previous= prevNode;
	count -=1;
	return data;
}
	
int main()
{
	
	return 0;
}
