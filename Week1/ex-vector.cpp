#include <iostream>

using namespace std;

class Vector3d{
private:
	float x,y,z;
public:
	Vector3d(){
		x = 0;
		y = 0;
		z = 0;
	}
	Vector3d(const Vector3d& right){
		this->x = right.x;
		this->y = right.y;
		this->z = right.z;
	}
	Vector3d(float x, float y, float z){
		this->x = x;
		this->y = y;
		this->z = z;
	}
	
	void setPoint(int x, int y,int z){
		this->x = x;
		this->y = y;
		this->z = z;
	};
	void getPoint(){
		cout << "(" << x << " ; " << y  <<" ; " << z << " )" << endl;
	};
	void add2Vector(Vector3d &vector){
		this->x = this->x + vector.x;
		this->y = this->y + vector.y;
		this->z = this->z + vector.z;
	};
	void multiply(int k){ // multiply k to a vector
		this->x = x*k;
		this->y = y*k;
		this->z = z*k;
	};
	void dot(Vector3d &vector){
		this->x = this->x * vector.x;
		this->y = this->y * vector.y;
		this->z = this->z * vector.z;
	};
};
class Vector2d{
private:
	float x,y;
public:
	Vector2d(){
		x = 0;
		y = 0;
	}
	Vector2d(const Vector2d& right){
		this->x = right.x;
		this->y = right.y;
	}
	Vector2d(float x, float y){
		this->x = x;
		this->y = y;
	}
	
	void setPoint(int x, int y){
		this->x = x;
		this->y = y;
	};
	void getPoint(){
		cout << "(" << x << " ; " << y  <<" )" << endl;
	};
	void add2Vector(Vector2d &vector){
		this->x = this->x + vector.x;
		this->y = this->y + vector.y;
	};
	void multiply(int k){ // multiply k to a vector
		this->x = x*k;
		this->y = y*k;
	};
	void dot(Vector2d &vector){
		this->x = this->x * vector.x;
		this->y = this->y * vector.y;
	};
};

int main(){
	cout << "Please choose the type of vector you want to calculate:" << endl;
	cout << "Press 1 to choose Vector in 2D:" << endl; 
	cout << "Press 2 to choose Vector in 3D:" << endl;
	int a;
	cin >> a;
	cout << endl;
	
	switch (a){ 
       case 1:{
		   Vector3d v1(1,1,1);
		   Vector3d v2(2,2,2);
		   
		   v1.setPoint(3,4,5);
		   v1.getPoint();
		   
		   
		   //test add func 
		   v1.setPoint(1,1,1); // reset for easy checking
		   v1.add2Vector(v2);
		   v1.getPoint();
		   
		   //test multiply
		   v1.setPoint(1,1,1);
		   v1.multiply(9);
		   v1.getPoint();
		   
		   //test dot
		   v1.setPoint(1,1,1);
		   v1.dot(v2);
		   v1.getPoint();
           
           break; 
       }
       case 2:{
		   
		   Vector2d v1(1,1);
		   Vector2d v2(2,2);
		   
		   v1.setPoint(3,4);
		   v1.getPoint();
		   
		   //test add func 
		   v1.setPoint(1,1); // reset for easy checking
		   v1.add2Vector(v2);
		   v1.getPoint();
		   
		   //test multiply
		   v1.setPoint(1,1);
		   v1.multiply(9);
		   v1.getPoint();
		   
		   //test dot
		   v1.setPoint(1,1);
		   v1.dot(v2);
		   v1.getPoint();
		   
               break; 
       }
       default: cout << "Input must be 1 or 2 only" << endl; 
                break;   
   } 
   cout << "this is end." << endl;
	
	
	return 0;
}
