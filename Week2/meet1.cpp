#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

/*1. array
 * 2. STL containers
 * 3. Create a list data type  by yourself  and use it !!! compulsory to use in this course
 */


class Point{
private:
	float_x,y;
public:
	Point(float x, float y){
		this->x = x;
		this->y = y;
	}
	Point(float x=0.0, float y=0.0){
		this->x = x;
		this->y = y;
	}
	
	//getter, setter
	
	void setX(float x){
		this->x =x;
	};
	float getX() const{
		return x;
	};
	
};

template<class T>
class MyArrayList{
	Point data[100];
	T data[100];
	----------
private:
	T *data; // data
	int capacity; // maximum element
	int count; // current number of elements
public:
	MyArrayList(){
		capacity =100;
		count =0;
		data = new Point(capacity);
		data = new T(capacity);
	}
	~MyArrayList(){
		
		if(data != NULL) delete []data;
	}
	void push_back(T item){
		if(count >= capacity){
			cout << "in future version: reallocate data (homework)" << endl; // slide: dynamic array
		}
		else{
			data[count] = item;
			count++;
			
		}
			
	}
	T get(int index){
		if((index < 0) || (index >= count)){
			//check invalid
			//throw exeception (homework)
			throw string("invalid index");
		}
		return data[index];
	}
	// override operator[] to support assesing method
	int size(){
		return count;
	}
	
	//homework
	//Dynamic Array
};

void println(Point p[], int size){
	for(int idx =0; idx < size;idx++){
		cout << "(" << p[idx].getX() << ", " << p[idx].getY() << ")" << endl;
	}
}

void println(vector<Point> v){
	for(int idx =0; idx < size;idx++){
		cout << "(" << v[idx].getX() << ", " << v[idx].getY() << ")" << endl;
	}
}

void println(MyArrayList<Point> ma){
	for(int idx =0; idx < ma.size();idx++){
		cout << "(" << ma.get(idx).getX() << ", " << ma.get(idx).getY() << ")" << endl;
	}
}
int main()
{
	Point points[100] ={Point(2.3f,12,3f), Point(2.3f,12,3f)};
	points[] = Point(2.4f. 2.3f);
	
	
	println(points, 3);
	
	vector<Point> vec;
	vec.push_back(Point(1.1f, 1.2f));
	vec.push_back(Point(1.1f, 1.2f));
	vec.push_back(Point(1.1f, 1.2f));
	vec.push_back(Point(1.1f, 1.2f));
	println(vec);

	MyArrayList<Point> ma;
	ma.push_back(Point(1.1f, 1.2f));
	ma.push_back(Point(1.1f, 1.2f));
	ma.push_back(Point(1.1f, 1.2f));
	ma.push_back(Point(1.1f, 1.2f));
	println(ma);
	
	return 0;

}
