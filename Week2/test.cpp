#include <iostream>
#include <vector>

using namespace std;

class Point {
private:
    float x,y;
public:
    Point(float x=0.0f, float y=0.0f) {
        this->x = x;
        this->y = y;
    }
    void setX(float x){
        this->x=x;
    }
    float getX(){
        return x;
    }
    void setY(float y){
        this->y=y;
    }
    float getY(){
        return y;
    }
};

//parameter the data type!!!
template<class T>
class MyArrayList{
private:
    T *data; //store data
    int capacity; //max number of elements
    int count; // current number
public:
    MyArrayList(){
        capacity = 100;
        count = 0;
        data = new T[capacity];
    }
    ~MyArrayList(){ //destructor
        if(data!= 0) delete []data;
    }
    void push_back(T item){
        //check the memory
        if(count >= capacity){
            cout << "In future version: reallocate data (homework)" << endl;
        }
        else {
            data[count] = item;
            count +=1;
        }
    }
    T get(int index){
        if(index >= count || index < 0){
            //invalid
            //throw exception (homework)
        	throw "";
        }
        return data[index];
    }
    //override operator [] to support assessing the elements look like vector (homework)
    int size(){
        return count;
    }
};

void print(Point p[], int size){
    for(int i = 0; i < size; i++) {
        cout << "(" << p[i].getX() << ", " << p[i].getY() << ")" << endl;
    }
}
void print(vector<Point> v){
    for(int i = 0; i < v.size(); i++) {
        cout << "(" << v[i].getX() << ", " << v[i].getY() << ")" << endl;
    }
}
void print(MyArrayList<Point> ma){
    for(int i = 0; i < ma.size(); i++) {
        cout << "(" << ma.get(i).getX() << ", " << ma.get(i).getY() << ")" << endl;
    }
}

int main()
{

    Point point_array[100] = {Point(2.5f, 3.5f), Point(4.6f, 7.8f)};
    point_array[2] = Point(2.1f, 5.6f); //add item to array
    cout << "\nArray p: \n";
    print(point_array,3);

    vector<Point> point_vector;
    point_vector.push_back(Point(3.4f, 1.2f));
    point_vector.push_back(Point(2.1f, 2.3f));
    point_vector.push_back(Point(3.0f, 1.1f));
    cout << "\nVector V: \n";
    print(point_vector);

    MyArrayList<Point> ma;
    ma.push_back(Point(3.4f, 1.2f));
    ma.push_back(Point(2.1f, 2.3f));
    ma.push_back(Point(3.0f, 1.1f));
    cout << "\nVector MA: \n";
    print(ma);

    return 0;
}
