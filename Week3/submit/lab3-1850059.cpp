#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
/*Singly Linked List
 * insertion - prepend(item),append(item),insertAt(index, item)
 * deletion - remove head(item), remove tail(item), removeAt(index, item)
 * search - get(index)->return: item, find(item)->return: index;
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
	bool append(const int& e){
		Node *node = new Node(e, tail);
		if(node == NULL) return false;
		tail->next->next = node;
		tail->next = node;
		count+=1;
		return true;
	};
	bool prepend(const int& e){
		Node *firstNode = head->next;
		Node *node = new Node(e, firstNode);
		if(node == NULL) return false;
		head->next = node;
		count+=1;
		return true;
	};
		
	bool insertAt(int index, const int& e){
		if(index < 0 || index > count)
			throw ("The index is out of bound \n");
		// index in [0, count]
		Node* newNode = new Node(e, 0); if(newNode == NULL) return false;
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
		return true;
	};

	bool removeHead(int& item){
		// in implement head pointer always ->(tail node) so not have line below
		//if(head==NULL) return false; 
		
		Node* prevNode = head;
		Node *curNode = prevNode->next;
		prevNode->next= curNode->next;
		curNode->next =0;//=NULL
		count-=1;
		item= curNode->data;
		delete curNode;		
		return true;		
	};

	bool removeTail(int& item){
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
		item = curNode->data;
		delete curNode;
		return true;		
	};		
	int remove(int index){
		if(index < 0 || index > count -1)
			throw std::out_of_range("The index is out of bound");
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
		int dum = curNode->data;
		delete curNode;
		return dum;		
	};
	bool remove(int index, int& item){
		if(index < 0 || index > count -1)
			throw std::out_of_range("The index is out of bound");
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
		item= curNode->data;
		delete curNode;
		return true;
	};
	int get(int index){
		if(index < 0 || index > count -1)
			throw std::out_of_range("The index is out of bound");
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

int main()
{	
	SLinkedlist slist1;
	
	for(int i=0; i<=5; i++)
		slist1.insertAt(i,i*i);
	slist1.println();

	// slist1.println();
	// slist1.prepend(1111);	
	// slist1.println();
	// slist1.append(9999);
	// slist1.println();
	// slist1.removeHead();
	// slist1.println();
	// slist1.removeTail();
	// slist1.println();
	// slist1.remove(2);
	// slist1.println();
	cout << slist1.find(9)<< endl;
	cout << slist1.find(91)<< endl;
	cout << slist1.get(3) << endl;
	int res=1111;
	 bool status1 = slist1.append(res);
	 (status1) ? cout <<"success append" : cout<<"fail append"; cout << endl;
	 slist1.println();
	 res=9999;
	 bool status3 = slist1.prepend(res);
	 (status3) ? cout <<"success prepend" : cout<<"fail prepend"; cout << endl;
	 slist1.println();
	 
	 bool status2 = slist1.remove(2,res);
	 (status2) ? cout <<"success remove at index" : cout<<"fail remove at index"; cout << endl;
	 slist1.println();
	
	 bool status = slist1.removeHead(res);
	 (status) ? cout <<"success remove head" : cout<<"fail remove head"; cout << endl;
	 slist1.println();
	 
	 bool status4 = slist1.removeTail(res);
	 (status4) ? cout <<"success remove tail" : cout<<"fail remove tail"; cout << endl;
	 slist1.println();	
	
	return 0;
}
