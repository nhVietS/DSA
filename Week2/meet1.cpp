#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

/* 1. array
 * 2. STL containers
 * 3. Create a list data type  by yourself  and use it !!! compulsory to use in this course
 */


class Point{
private:
	float x,y;
public:
	Point(float x, float y){
		this->x = x;
		this->y = y;
	}
	Point(){
		this->x = 0.0;
		this->y = 0.0;
	}	
	//getter, setter	
	void setX(float x){
		this->x =x;
	};
	float getX() const{
		return x;
	};
	void setY(float y){
		this->y=y;
	};
	float getY(){
		return y;
	};
};

template<class T>
class MyArrayList{
	//Point data[100];
	//T data[100];
	//----------
private:
	T *data; // data
	int capacity; // maximum element
	int count; // current number of elements
public:
	MyArrayList(){
		capacity =100;
		count =0;
		//data = new Point(capacity);
		data = new T[capacity];
	}
	MyArrayList(int capacity){
		this->capacity = capacity;
		count =0;
		data = new T[capacity];
	}
	~MyArrayList(){
		if(data != NULL) delete []data;
	}
	// override operator[] to support assesing method
	// Implemeting ...
	T& operator[](int index){
		if(index >= 0 && index < capacity);
			return data[index];	
		throw "Index out of boundary";
	}
	const T & operator[](int index)const {
		if(index >= 0 && index < capacity);
			return data[index];	
		throw "Index out of boundary";
	}
	//setCapacity() == resize()
	void setCapacity(int newCapacity){
		if (capacity < newCapacity) return;
		
		T *newData = new T[newCapacity];
		//memcpy(newData, data, sizeof(T)*count);
		for(int i=0; i < newCapacity; i++)
			newData[i] = data[i];
			
		capacity = newCapacity;
		delete[] data;
		data = newData;
	};
	void ensureCapacity(int minCapacity){
		if(minCapacity > capacity){
			int newCapacity = (capacity*3)/2 +1;
			if(newCapacity < minCapacity)
				newCapacity = minCapacity;
			setCapacity(newCapacity);
	};
	// void pack();
	// void trim();
	
	void rangeCheck(int index){
		if(index <0 || index >= count)
			throw "Exception: Index out of boundary"; 
	};
	void removeAt(int index){
		if( index <0 || index >count)//illegal
			throw "the input out of range";
		count-=1;
		
		if(capacity -1 == index){
			data[index]=0;
			return;
		}
		for(int idx= index; < count -1; idx++){
			data[idx] = data[idx+1];
		}
		data[index]=0;			
	};
	void insertAt(int index, T e){
		if( index <0 || index >count)//illegal
			throw "the input out of range";
		ensureCapacity(index);
		count+=1;// increase when add
		
		if(count == 0){
			data[index] = e;
			return;
		}
		
		for(int idx= count -1; idx >= index; idx--){
			data[idx+1] = data[idx];
		}
		data[index] = e;// assign the item into the specific index
		
	};
	
	void push_back(T item){
		if(count >= capacity){
			cout << "in future version: reallocate data (homework)" << endl; // slide: dynamic array
			capacity+=1; // could I increase more than 1 resize( 2 * theCapacity + 1 )
			setCapacity(capacity);
		}
		else{
			data[count] = item;
			count++;			
		}
	};
	// void push_back(const T &item){
		// if(count >= capacity){
			// cout << "in future version: reallocate data (homework)" << endl; // slide: dynamic array
		// }
		// else{
			// data[count] = item;
			// count++;			
		// }
	// };
	T get(int index){
		if((index < 0) || (index >= count)){//check invalid
			//throw exeception (homework)
			throw string("Index out of boundary");
		}
		return data[index];
	};
	// void set(int index, const T &value){
		// if((index < 0) || (index >= count))
			// throw string("Index out of boundary");
		// data[index] = value; 
	//};
	int size(){
		return count;
	};
	
	//homework: Dynamic Array
};

void println(Point p[], int size){
	for(int idx =0; idx < size;idx++){
		cout << "(" << p[idx].getX() << ", " << p[idx].getY() << ")" << endl;
	}
}

void println(vector<Point> v){
	for(int idx =0; idx < v.size();idx++){
		cout << "(" << v[idx].getX() << ", " << v[idx].getY() << ")" << endl;
	}
}

void println(MyArrayList<Point> ma){
	for(int idx =0; idx < ma.size();idx++){
		cout << "(" << ma.get(idx).getX() << ", " << ma.get(idx).getY() << ")" << endl;
	}
}
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
		Node<T> *node = new Node(e, tail);
		tail->next ->next = node;
		tail->next = node;
		count+=1;
	};
	void remove(){};
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
	Point points[100] ={Point(2.3f,12.3f), Point(2.3f,12.3f)};
	points[2] = Point(2.4f , 2.3f);
	
	
	println(points, 3);
	cout << "----------------------------" << endl;
	
	vector<Point> vec;
	vec.push_back(Point(1.1f, 1.2f));
	vec.push_back(Point(1.1f, 1.2f));
	vec.push_back(Point(1.1f, 1.2f));
	vec.push_back(Point(1.1f, 1.2f));
	println(vec);
	cout << "----------------------------" << endl;
	MyArrayList<Point> ma;
	ma.push_back(Point(1.2f, 2.2f));
	ma.push_back(Point(1.3f, 3.2f));
	ma.push_back(Point(1.4f, 4.2f));
	ma.push_back(Point(1.5f, 5.2f));
	println(ma);
	cout << "----------------------------" << endl;
	
	// ma[4] = Point(1.56f, 5.22f);
	// println(ma);
	// cout << "----------------------------" << endl;

	return 0;
}
