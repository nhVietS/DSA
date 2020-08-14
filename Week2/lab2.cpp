#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <math.h>
using namespace std;

//int: rand() % (max – min + 1) + min
// double fRand(double fMin, double fMax)
// {
    // double f = (double)rand() / RAND_MAX;
    // return fMin + f * (fMax - fMin);
// }

static int pointsCount =10;
//static float dist(Point x, Point y);

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
	Point &operator=(const Point &right){
		this->x=right.x;
		this->y=right.y;
	}
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
	float dist(const Point &other){
		float n=powf((this->x - other.x),2.0);
		float m=powf((this->y - other.y),2.0);
		return sqrt(n+m);
	};
	float dist(){
		float n=powf((this->x ),2.0);
		float m=powf((this->y ),2.0);
		return sqrt(n+m);
	};
		
};

void printPoints(Point p[], int pointsCount){
	for(int idx=0; idx < pointsCount; idx++){
		cout << "(" << p[idx].getX() << ", " << p[idx].getY() << ")" << endl;
	}
}
void printNearestOriginPoint(Point p[], int pointsCount){
	float temp = p[0].dist();
	int i=0;
	for(int idx=1; idx < pointsCount; idx++){
		if( p[idx].dist() < temp ){
			temp = p[idx].dist();
			i = idx;
		}		
	}
	cout << "Point nearest Origin:(" << p[i].getX() << ", " << p[i].getY() << ")" << endl;
}
void randomPoints(int pointsCount){
	Point p[pointsCount];
}
Point randomPoints(Point *&p, int pointsCount){
	p = new Point[pointsCount];
	return p;
}
Point nearestOrigin(Point p[], int pointsCount){
	float temp = p[0].dist();
	int i=0;
	for(int idx=1; idx < pointsCount; idx++){
		if( p[idx].dist() < temp ){
			temp = p[idx].dist();
			i = idx;
		}		
	}
	return p[i];
}

class Vector{
private:
	float x,y;
public:
	Vector(){
		x = -100 + ((float)rand() / RAND_MAX)*200;
		y = -100 + ((float)rand() / RAND_MAX)*200;
	}
	Vector(const Vector& right){
		this->x = right.x;
		this->y = right.y;
	}
	Vector(float x, float y){
		this->x = x;
		this->y = y;
	}
	~Vector(){};
	//overide = operator
	Vector &operator=(const Vector &right){
		this->x=right.x;
		this->y=right.y;
	}
	//get , set
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

class Rectangle{
protected:
	Point p1, p2;
public:
	Rectangle(){
		
	}
	Rectangle(Point p1, Point p2){
		this->p1 = p1;
		this->p2 = p2;
	}
	Rectangle(const Rectangle& right){
		this->p1 = right.p1;
		this->p2 = right.p2;
	}
	~Rectangle(){};
};


class Square : public Rectangle{
public:
};

int main()
{
	//2147483647 gnu c++ compiler from 0 to RAND_MAX
	//meaning when use rand(), srand()
	srand(time(NULL)); 
	// Point a,b;
	// cout << "(" <<  a.getX() << "; " << a.getY() << ")" << endl;
	// cout << a.dist(b) << endl;
	// cout << a.dist() << endl;
	
	//func1
	//Point points[pointsCount];
	// printPoints(points, pointsCount); 
	// cout << "End f1."<<endl;
	
	//function1-test
	//Point *p = NULL;
	randomPoints(pointsCount);
	//func2
	// printNearestOriginPoint(points, pointsCount);
	// cout << "End f2." << endl;
	cout << p[0].getX() << endl;
	
	return 0;
}
// Implement function:
// 1. input: quantity of points
	// output: array of points randomly
// 2. input: Array of points
	// output: point nearest O_origin
// 3. input: Array of vectors
	// output: longest vector
// 4. input: Array of vectors
// (print)	output: ortho vectos ( vector truc giao, hay in tat ca cap vector vuong goc vs nhau)
// 5. input: Array of rectangle
// (return all)	output: largest rectangle
