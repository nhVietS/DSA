//DSA gg-meet 18/8/2020
template<class T> class SLinkedlist;

template<class T>
class Node{
private:
	T data;
	Node<T> *next;
	friend class SLinkedlist;
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
		head->tail = head;
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
			prevNode = pRec->next;
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
		return curNode->data;
		
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
	void println(){
		Node<T> *ptr = head->next;
		while(ptr != tail){
			cout << ptr->data << " ";	
			ptr = ptr->next;		 
		}
		cout << end;
	}
};
int main()
{
	SLinkedlist<int> slist;
	for(int i=0; i<=5; i++)
		slist.add(i, i*i);
	
	slist.println();
	
	
	return 0;
}
