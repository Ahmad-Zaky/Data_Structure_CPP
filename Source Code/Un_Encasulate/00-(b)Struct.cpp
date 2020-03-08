// Struct.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <String>

using namespace std;


struct GroceryStore{
	string productName;
	float weight;
	int price;
}Oil,Sugar,Rice; //method to creating objects from the struct(User Defined Data Type)



struct Student{
	int id;
	string Name;
	string department;
	float grades;
};


int main()
{
	//---------------------------------
	Oil.price = 5;
	Oil.productName = "Abbad El Shams";
	Oil.weight = 400;
	


	cout<<"The Price of Oil is "<<Oil.price
		<<"\nThe Product Name of this oil is "<<Oil.productName
		<<"\nThe weight of this oil is "<<Oil.weight;
	//----------------------------------


	
	//-----------------------------------------------------------
	//Method of Entering data
	Student st1 = {1,"Ahmed","CS",100};
	
	cout<<"The student ID is"<<st1.id
			<<"\nThe student Name is"<<st1.Name
			<<"\nThe student Department is"<<st1.department
			<<"\nThe student grade is"<<st1.grades;
	
	

	Student st2;
	//Another method of Entering data
	st2.id = 2;
	st2.Name = "Mohamed";
	st2.department = "Engineering";
	st2.grades = 100;

	cout<<"The student ID is"<<st2.id
		<<"\nThe student Name is"<<st2.Name
		<<"\nThe student Department is"<<st2.department
		<<"\nThe student grade is"<<st2.grades;
	//-----------------------------------------------------------

	return 0;
}

