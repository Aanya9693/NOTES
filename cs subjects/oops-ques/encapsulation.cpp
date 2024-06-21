#include <bits/stdc++.h>
using namespace std;

class Student
{
private:
	string name;
	int roll;
	char grade;
public:
	//setter
	void setName(string name){
		this->name=name;
	}
	void setRollnumber(int rn){
		roll=rn;
	}
	void setGrade(char g){
		grade=g;
	}
	
	//getters
	int getRollnumber(){
		return roll;
	}
	char getGrade(){
		return grade;
	}
	string getName(){
		return name;
	}
	
};

int main(){
	Student student;
	
	student.setName("aanya");
	student.setRollnumber(101);
	student.setGrade('A++');
	
	cout<<"Name: "<<student.getName()<<endl;
	cout<<"Roll number: "<<student.getRollnumber()<<endl;
	cout<<"Grade: "<<student.getGrade()<<endl;
	
}