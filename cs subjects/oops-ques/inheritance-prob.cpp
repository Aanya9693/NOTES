// --------2. Implement a Simple Inheritance---
#include<bits/stdc++.h>
using namespace std;

class Animal
{
public:
	int leg;
	public:
	void makeSound(int leg){
		this->leg=leg;
		cout<<"Animal legs: "<<leg<<endl;
	}
};

class Dog : public Animal{
	string color;
	public:
	void dogcolor(string col){
		this->color=col;
		cout<<"dog color: "<<col<<endl;
	}
};

int main(){
	Animal Cats;
	Cats.makeSound(4);
	Dog mydog;
	mydog.makeSound(8);
	mydog.dogcolor("red");
}