#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <math.h>
using namespace std;

static int pointsCount =10;
static int vectorsCount =10;
static int rectanglesCount =10;

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
	float dist(const Vector &other){
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

class Rectangle{
protected:
	Point p1, p2;
public:
	Rectangle(){};
	Rectangle(Point p1, Point p2){
		this->p1 = p1;
		this->p2 = p2;
	}
	Rectangle(const Rectangle& right){
		this->p1 = right.p1;
		this->p2 = right.p2;
	}
	~Rectangle(){};
	float getX1(){
		return this->p1.getX();
	};
	float getX2(){
		return this->p2.getX();
	};
	float getY1(){
		return this->p1.getY();
	};
	float getY2(){
		return this->p2.getY();
	};
	float getWidth(){
		return abs(this->getX1() - this->getX2()); // |x2 - x1|
	};
	float getHeight(){
		return abs(this->getY1() - this->getY2()); // |y2 - y1|
	};
};

class Square : public Rectangle{};

void printRandomPoints(Point p[], int pointsCount){//this func is for testing
	for(int idx=0; idx < pointsCount; idx++){
		cout << "(" << p[idx].getX() << ", " << p[idx].getY() << ")" << endl;
	}
}
void printNearestOriginPoint(Point p[]){ //this func is for testing
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
	cout << "Random Points already created" << endl;
}

Point nearestOrigin(Point p[]){
	float temp = p[0].dist();
	int i=0;
	for(int idx=1; idx < pointsCount; idx++){
		if( p[idx].dist() <= temp ){
			temp = p[idx].dist();
			i = idx;
		}		
	}
	return p[i];
}

Vector longestVector(Vector v[]){
	float temp = v[0].dist();
	int i=0;
	for(int idx=1; idx < pointsCount; idx++){
		if( v[idx].dist() >= temp ){
			temp = v[idx].dist();
			i = idx;
		}		
	}
	return v[i];
}

void orthoVector(Vector v[]){
	float temp;
	for(int idx=0; idx <= vectorsCount-1; idx++){
		for(int j=idx+1;j <= vectorsCount; j++){
			if( v[idx].getX()*v[j].getX() + v[idx].getY()*v[j].getY() == 0.0f)
			{ // if x1x2 + y1y2=0 => 2 orthogonal vectors
				cout << "Vector 1 (" << v[idx].getX() << ", " << v[idx].getY() << ");Vector2 (" << v[j].getX() << ", "<< v[j].getY() <<" )." << endl;
			}
			else
			{
				cout << "No orthogonal vectors found in loop:" << j << endl; // check looping
			}			
		}
	}
}

Rectangle largestRec(Rectangle rec[]){
	float tempLargestArea = rec[0].getWidth()*rec[0].getHeight(); // Area = |x2 - x1|*|y2-y1|
	int index =0;
	for(int i=1; i <= rectanglesCount; i++){
		if(rec[i].getHeight() *rec[i].getWidth() > tempLargestArea){
			tempLargestArea = rec[i].getHeight() *rec[i].getWidth();
			index = i;
		}
	}
	cout << "GET LARGEST AREA: "<< tempLargestArea << endl;
	return rec[index];
}

int main()
{
	//test dist()
	/*
	Point a,b;
	cout << "(" <<  a.getX() << "; " << a.getY() << ")" << endl;
	cout << a.dist(b) << endl;
	cout << a.dist() << endl;
	*/
	
	//print array of random points
	/*
	points[pointsCount];
	printRandomPoints(points, pointsCount); 
	cout << "End f1."<<endl;
	*/
	//func2
	/*printNearestOriginPoint(points, pointsCount);*/
	
	srand(time(NULL)); 
	
	cout << "function 1:" << endl;
	randomPoints(pointsCount);
	
	cout << "function 2:" << endl;
	Point p[pointsCount];
	cout << "Point nearest Origin:(" << nearestOrigin(p).getX() << ", " << nearestOrigin(p).getY() << ")" << endl;
	
	cout << "function 3:" << endl;
	Vector v[vectorsCount];
	cout << "Longest vector from Origin:(" << longestVector(v).getX() << ", " << longestVector(v).getY() << ")" << endl;
	
	cout << "function 4:" << endl; 
	orthoVector(v);

	cout << "function 5:" << endl;
	Rectangle rec[rectanglesCount];
	largestRec(rec);

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

