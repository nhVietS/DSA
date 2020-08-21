#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
/*Singly Linked List
 * insertion - prepend(item),append(item),insertAt(index, item)
 * deletion - remove head(item), remove tail(item), removeAt(index, item)
 * search - get(index)->return: item, find(item)->return: index;
 */
 
 /*Create random value in some data type to test excution time
  * 100 -1000 - 10000
  * in main()
  * Node<int>a;
  * Node<float>b;
  * Node<Student>c;
  * 
  */

class SLinkedlist;
class Node{
private:
	int data;
	Node *next;
	friend class SLinkedlist;
public:
	Node(){
		this->next = NULL; // NULL == 0
	}
	Node(Node *next){
		this->next = next;
	}
	Node(int data, Node *next){
		this->data = data;
		this->next = next;
	}
};
class SLinkedlist{
private:
	Node *head;
	Node *tail;
	int count;
public:
	SLinkedlist(){
		head = new Node();
		tail = new Node();
		head->next = tail;
		tail->next = head;
		count= 0;
	}
	void addEnd(int e){
		Node *node = new Node(e, tail);
		tail->next->next = node;
		tail->next = node;
		count+=1;
	};
	void addHead(int e){
		Node *firstNode = head->next;
		Node *node = new Node(e, firstNode);
		head->next = node;
		count+=1;
	};
		
	void add(int index, int e){
		if(index < 0 || index > count)
			throw ("The index is out of bound \n");
		// index in [0, count]
		Node* newNode = new Node(e, 0);
		Node* prevNode = head;
		int cursor = -1;
		// 
		while(cursor < index -1){
			prevNode = prevNode->next;
			cursor+=1;
		}
		// add newNode
		Node* curNode = prevNode->next;
		prevNode->next = newNode;
		newNode->next = curNode;
		//missing ? change tail->next if needed (at none or full list)
		if(index == count)
			tail->next = newNode;
			
		count +=1;
	};
	int removeHead(){
		Node* prevNode = head;
		Node *curNode = prevNode->next;
		prevNode->next= curNode->next;
		curNode->next =0;//=NULL
		count-=1;
		int dum = curNode->data;
		delete curNode;
		return dum;		
	};
	int removeTail(){
		Node* prevNode = head;
		int cursor = -1;
		// 
		while(cursor < count -2){
			prevNode = prevNode->next;
			cursor+=1;
		}
		Node *curNode = prevNode->next;
		prevNode->next= curNode->next;
		curNode->next =0;//=NULL
		tail->next = prevNode;
		count-=1;
		int dum = curNode->data;
		delete curNode;
		return dum;		
	};
	
	int remove(int index){
		if(index < 0 || index > count -1)
			throw ("The index is out of bound");
		Node* prevNode = head;
		int cursor = -1;
		// 
		while(cursor < index -1){
			prevNode = prevNode->next;
			cursor+=1;
		}
		//here: prevNode points to previous item[at index -1] 
		Node *curNode = prevNode->next;
		prevNode->next= curNode->next;
		curNode->next =0;//=NULL
		if(index == count)
			tail->next = prevNode;
		count -=1;
		return curNode->data;		
	};
	int get(int index){
		if(index < 0 || index > count -1)
			throw ("The index is out of bound");
		Node* prevNode = head;
		int cursor = -1;
		// 
		while(cursor < index -1){
			prevNode = prevNode->next;
			cursor+=1;
		}
		return prevNode->next->data;
	};
	int find(int element){
		Node*ptr = head->next;
		int foundAt = 0;
		while(ptr != tail){
			if(ptr->data == element)
				break;
			ptr = ptr->next;
			foundAt+=1;
		}
		if (foundAt >count -1) return -1;
		return foundAt;
	};
	
	bool empty(){
		return count == 0;
	}
	int size(){
		return count;
	};
	void println(){
		Node *ptr = head->next;
		while(ptr != tail){
			cout << ptr->data << " ";	
			ptr = ptr->next;		 
		}
		cout << endl;
	}
};
class Student{
private:
	int id;
	double gpa;
public:
	
};
int main()
{
	//srand(time(NULL)); 
	
	// SLinkedlist slist;
	// for(int i=0; i<=5; i++)
		// slist.addEnd(i);
	// slist.println();
	
	SLinkedlist slist1;
	for(int i=0; i<=5; i++)
		slist1.add(i,i*i);
	slist1.println();
	//slist1.removeHead();
	//slist1.removeTail();
	//slist1.println();
	cout << slist1.find(9)<< endl;
	cout << slist1.find(91)<< endl;
	
	return 0;
}
