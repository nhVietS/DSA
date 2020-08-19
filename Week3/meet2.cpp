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
		tail->next ->next = node;
		tail->next = node;
		count+=1;
	};
	void add(int index, T e){
		if(index < 0 || index > count)
			throw ("The index is out of bound");
		// index in [0, count]
		Node<T>* newNode = new Node(e, 0);
		Node<T>* pRev = head;
		int cursor = -1;
		// 
		while(cursor < index -1){
			pRev = pRec->next;
			cursor+=1;
		}
		// add newNode
		Node<T>* curNode = pRev->next;
		pRev->next = newNode;
		newNode->next = curNode;
		//missing ? change tail->next if needed (at none or full list)
		if(index == count)
			tail->next = newNode;
			
		count +=1;
	};
	T remove(int index){
		if(index < 0 || index > count -1)
			throw ("The index is out of bound");
		Node<T>* pRev = head;
		int cursor = -1;
		// 
		while(cursor < index -1){
			pRev = pRec->next;
			cursor+=1;
		}
		//here: prevNode points to previous item at index -1
		Node<T> *curNode = pRev->next;
		pRev->next= curNode->next;
		curNode->next =0;
		if(index == count)
			tail->next = pRev;
		
		return curNode->data;
		
	};
	T get(int index){
		if(index < 0 || index > count -1)
			throw ("The index is out of bound");
		
	};
	
	bool empty(){
		return count == 0;
	}
	int size(){
		return count;
	};
	void println(){
		Node<T> *ptr = head;
		while(ptr->next != tail){
			cout << ptr->data << " ";	
			ptr = ptr->next;		 
		}
		cout << end;
	}
};
int main()
{
	Slinkedlist<int> list;
	for(int i=0; i<=5; i++)
		list.add(i, i*i);
	
	list.println();
	
	
	return 0;
}
