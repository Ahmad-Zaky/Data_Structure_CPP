// Pointers_Sec_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
	//// Fig. 5.4: fig05_04.cpp
	//// Using the & and * operators.
 //     #include <iostream>
 //     
 //     using std::cout;
 //     using std::endl;
 //     
 //     int main()
 //     {
 //      int a;      // a is an integer
 //      int *aPtr;  // aPtr is a pointer to an integer
 //   
 //      a = 7;
 //      aPtr = &a;  // aPtr assigned address of a
 //   
 //      cout << "The address of a is " << &a
 //           << "\nThe value of aPtr is " << aPtr;
 //   
 //      cout << "\n\nThe value of a is " << a
 //           << "\nThe value of *aPtr is " << *aPtr;
 //   
 //      cout << "\n\nShowing that * and & are inverses of "
 //           << "each other.\n&*aPtr = " << &*aPtr
 //           << "\n*&aPtr = " << *&aPtr << endl;



	//   return(0);
	//  
	//  }


////----------------------------------------------=+=---------------------
////Example 1:
//
//int main()
//{
//	int Count = 10, X;
//	int *ptrCount;
//	ptrCount=&Count;
//	X=*ptrCount;
//	cout << "The value of Count= " << Count 
//		 << "\nThe value of X = " << X<<endl;
//	return 0;
//}


////----------------------------------------------=+=---------------------
////Example 2:
//
//int main()
//{
//	int value1 , value2;
//	int Var;
//	int *ptrVar;
//	Var=2;
//	value1 = 4 * (Var +3);
//	ptrVar=&Var;
//	value2=4*(*ptrVar +3);
//	cout << "The Value of value1= " << value1
//	     <<"\nThe Value of value2 = " << value2<<endl;
//	return 0;
//}
//
//
////----------------------------------------------=+=---------------------
////Example 3:
//
//int main()
//{
//	int Count;
//	int *ptrCount;
//	
//	Count=0;
//	ptrCount=&Count;
//
//	cout << "The first value of Count= " << Count
//	     << "\nThe first value of *ptrCount = " << *ptrCount ;
//
//	*ptrCount=1;
//
//	cout << "\n\nThe second value of Count= " << Count
//	     << "\nThe second value of *ptrCount = " << *ptrCount<<endl;
//
//	return 0;
//}
//
//
////----------------------------------------------=+=---------------------
////Example 4:
//
//int main()
//{
//	int Count;
//	int *ptrCount=&Count;
//	Count=0;
//
//	cout << "The first value of Count= " << Count
//	     << "\nThe first value of *ptrCount = " << *ptrCount ;
//
//	*ptrCount=1;
//
//	cout << "\n\nThe second value of Count= " << Count
//	     << "\nThe second value of *ptrCount = " << *ptrCount<<endl;
//
//	return 0;
//}
//
////----------------------------------------------=+=---------------------
////Example 5:
//
//int main()
//{
//	int Count;
//	int &RefCount=Count;
//	Count=0;
//
//	cout << "The first value of Count= " << Count
//	     << "\nThe first value of RefCount = " << RefCount ;
//
//	RefCount=1;
//
//	cout << "\n\nThe second value of Count= " << Count
//	     << "\nThe second value of  RefCount= " << RefCount<<endl;
//
//	return 0;
//}
//

////----------------------------------------------=+=---------------------
////example 6:
//
//
//void func(int xx, int yy)
//{	cout << "\n\nthe first value of xx = " << xx<< "\nthe first value of yy= " << yy;
//	xx=xx+10;
//	yy=yy+10;
//	cout << "\n\nthe second value of xx = " << xx<< "\nthe second value of yy= " << yy;
//}
//
//int main()
//{	int x=2 , y=3;
//	 cout << "the value of x before function call= " << x<< "\nthe value of y before function call= " << y;
//	func(x, y);
//	cout << "\n\nthe value of x after function call= " << x<< "\nthe value of y after function call= " << y<<endl;
//	return 0; 
//}
//



//----------------------------------------------=+=---------------------
//Example 7

//void func(int *Px, int *Py)
//{	int XX, YY;
//	 XX=*Px;
//	 YY=*Py;
//	 cout << "\n\nThe first value of XX = " << XX<< "\nThe first value of YY= " << YY;
//	*Px=*Px+10;
//	*Py=*Py+10;
//	XX=*Px;
//	YY=*Py;
//	cout << "\n\nThe second value of XX = " << XX<< "\nThe second value of YY= " << YY;}
//
//int main()
//{	int X=2 , Y=3;
//	 cout << "The value of X before function call= " << X<< "\nThe value of Y before function call= " << Y;
//	func(&X, &Y);
//	cout << "\n\nThe value of X after function call= " << X<< "\nThe value of Y after function call= " << Y <<endl;
//	return 0; }


//
//
////----------------------------------------------=+=---------------------
////Example 8:
//
//void swap(int x, int y)
//{	int temp;
// 	cout << "\n\nThe first value of X = "<< x << "	and The first value of Y before swap= " << y;
//	temp=x;
//	 x=y;
//	y=temp;
//	cout << "\n\nThe second value of X = " << x << "	and The second value of Y = "<< y;
//}
//
//int main()
//{	int A=5 , B=7;
//	 cout << "The value of A before swap= " << A<< "	and The value of B before swap= " << B;
//	swap(A, B);
//	cout << "\n\nThe value of Aafter swap= " << A<< "	and The value of B after swap= " << B<<endl;
//	return 0; 
//}
//
//
//

////----------------------------------------------=+=---------------------
////Example 9:
//
//void swap(int *Px, int *Py)
//{	int temp;
//	temp=*Px;
//	 *Px=*Py;
//	*Py=temp;
//}
//
//
//int main()
//{	int X=5 , Y=7;
//	cout << "The value of X before swap= " << X<< "\nThe value of Y before swap= " << Y;
//	swap(&X, &Y);
//	cout << "\n\nThe value of X after swap= " << X<< "\nThe value of Y after swap= " << Y<<endl;
//	return 0; 
//}
//
//


//--------------------------------------------------


//// Fig. 5.6: fig05_06.cpp
//// Cube a variable using pass-by-value.
//
//int cubeByValue( int );   // prototype
//      
//    int main()
//    {
//       int number = 5;
//    
//       cout << "The original value of number is " << number;
//    
//       // pass number by value to cubeByValue
//       number = cubeByValue( number );
//    
//       cout << "\nThe new value of number is " << number << endl;
//    
//       return 0;  // indicates successful termination
//    
//    } // end main
//// calculate and return cube of integer argument               
//    int cubeByValue( int n )                                       
//    {                                                              
//       return n * n * n; // cube local variable n and return result
//                                                                   
//    } // end function cubeByValue                                  
//
//


//	//------------------------------------------------------
//
//  // Cube a variable using pass-by-reference 
//  // with a pointer argument.
//
//     void cubeByReference( int * );   // prototype
//    
//    int main()
//    {
//       int number = 5;
//    
//       cout << "The original value of number is " << number;
//    
//       // pass address of number to cubeByReference
//       cubeByReference( &number );
//    
//       cout << "\nThe new value of number is " << number << endl;
//    
//       return 0;  // indicates successful termination
//    } // end main
//
//
//	// calculate cube of *nPtr; modifies variable number in main
//    void cubeByReference( int *nPtr )                           
//    {                                                           
//       *nPtr = *nPtr * *nPtr * *nPtr;  // cube *nPtr            
//                                                                
//	} // end function cubeByReference
//

