#include<bits/stdc++.h>
using namespace std;

class Shape{
public:
	virtual double area()const=0; //pure virtual function
	virtual ~Shape(){}
};

class Circle : public Shape{
private:
	double radius;
public:
	Circle(double r) : radius(r){} //initialiser list
	
	double area() const override { //override keyword used to override a function
		return 2 * radius * radius;
	}
};

class Rectangle : public Shape{
private:
	double width;
	double height;
public:
	Rectangle(double w, double h):width(w), height(h){}
	double area() const override{
		return width*height;
	}
};

int main(){
	Circle circle(5.0);
	Rectangle rectangle(4.0, 6.0);
	
	cout<<"Circle area: "<<circle.area()<<endl;
	cout<<"Rectangle area: "<<rectangle.area()<<endl;
	
	// delete circle;
	// delete rectangle;
	return 0;
}