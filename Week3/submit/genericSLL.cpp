#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
static int pointsCount =10;
/*DSA gg-meet 18/8/2020
 * Single linked list
 */
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
	void add(T e){
		Node<T> *node = new Node<T>(e, tail);
		tail->next->next = node;
		tail->next = node;
		count+=1;
	};
	void add(int index, T e){
		if(index < 0 || index > count)
			throw ("The index is out of bound");
		// index in [0, count]
		Node<T>* newNode = new Node<T>(e, 0);
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
	};
	T remove(int index){
		if(index < 0 || index > count -1)
			throw ("The index is out of bound");
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
		T dum = curNode->data;
		delete curNode;
		return dum;			
	};
	T get(int index){
		if(index < 0 || index > count -1)
			throw ("The index is out of bound");
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

class Point{
private:
	float x,y;
public:
	Point(){
		x= -100 + ((float)rand() / RAND_MAX)*200;
		y= -100 + ((float)rand() / RAND_MAX)*200;
	}
	Point(float x, float y){
		this->x = x;
		this->y = y;
	}
	Point(const Point &right){
		this->x = right.x;
		this->y = right.y;
	}
	~Point(){}
	void setX(float x){
		this->x =x;
	};
	float getX(){
		return x;
	};
	void setY(float y){
		this->y=y;
	};
	float getY(){
		return y;
	};	
};

int main()
{
	srand(time(NULL)); 
	SLinkedlist<int> slist;
	for(int i=0; i<=5; i++)
		slist.add(i, i*i);
	
	slist.println();
	slist.add(1111);
	slist.println();
	slist.remove(5);
	slist.println();
	
	Point p[pointsCount];
	SLinkedlist<Point> sl;
	for(int i=0; i<=pointsCount; i++)
		sl.add(i,p[i]);
	// print function error
	//sl.println();
	return 0;
}
