 /*
* Tyler Hunt
* Advanved C++
* OCCC Fall 2017
* Class code examples
*/
//Notes:    // C++ has a singe pass compiler
			// Java has a double pass compiler
			// C++ does not know the size of its array so u must send it's size'
			//data structure are all about order and structurre in


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Prototype functions
void vswap(int a, int b);		// value of
void rswap(int & a, int & b); 	// address of
void pswap(int * a, int * b); 	// dereference of
void displayArray(int * theArray, int theArraySize);

int main(){

	//Intro message
	cout << "Welcome to Pointer Demo!" << endl;
	cout << "";

	int a = 10;
	int b = 20;
	cout << "\tOriginal - a is " << a << " b is " << b << endl;
	vswap(a,b);
	cout << endl;
	cout << "\tBy Value swap - a is " << a << " b is " << b << endl;
	rswap(a,b);
	cout << "\tBy Reference - a is " << a << " b is " << b << endl;
	pswap(&a, &b);  //send the address of the var   - pointers recieve addresses &
	cout << "\tBy Pointer - a is " << a << " b is " << b << endl;

	//primitaves
		// identity - is what and where it is
		// state - the 0's and 1's - the actual data at that location

	//Objects
		// identity - is what and where it is
		// state - the 0's and 1's - the actual data at that location
		// behavior - what and how it acts

		// & - reference of
		// * -  derefernce of

	//Test material

	cout << endl;
	int     i	= 	10;
	int   * pi 	= 	&i;         	//read as pi points to an int by reference of i
	int ** ppi	=  	&pi;			//read as 
	
	cout << "\ti is " << i << endl;
	cout << "\t&i is " << &i << endl;
	cout << "\tpi is " << pi << endl;
	cout << "\t&pi is " << &pi << endl;
	cout << "\t*pi is " << *pi << endl;

	cout << endl;
	cout << "\tppi is " << ppi << endl;
	cout << "\t*ppi is " << *ppi << endl;
	cout << "\t**ppi is " << **ppi << endl;

	cout << endl;
	cout << "\tpi + 1 is " << pi+1 << endl;  			// pointer knows the size of the things it points too
	cout << "\tsize of int " << sizeof(int) << endl;  	// print the size of int in the system

	// int c [10];
	// for(int i = 0; i < 10; ++i){
	// 	c[i] = i;
	// }
	
	// displayArray(c, 10);

	// int * d = new int[10];		//dynamic array 
	// int j = 0;
	// while(j < 10){
	// 	*(d+j)=j++;
	// }

	// displayArray(d, 10);

	// c[5] = 99;			//change index 5 to 99
	// *(c+5) = 88;		//change in 5 to 88
	// displayArray(c, 10);

	// int  e [10];
	// cout << "diff between a and b is" << (c - e) << endl;
	// displayArray(e, 10);

	int i1[] = {1,2,3,4,5};  //prints address
	cout << i1 << endl;

	char s1 []= {'H', 'e','l','l','o',0}; //specially print char arrays as string
	cout << s1 << endl;

	char s2[] = "Good Bye";
	cout << s2 << endl;

	*(s2+0) = 'X';
	cout << s2 << endl;

	char s3[] = {'h', 'e','l','l','o'}; //surpise
	cout << s3 << endl;

	string s4 = "I love C++"; //surpise
	cout << s4 << endl;

	s4[7] = 'J';
	cout << s4 << endl;

	

	return EXIT_SUCCESS; 
}


//Pass by value example - for primitaves
void vswap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

//Pass by Reference example - for primitaves  & = pronounced -> address of
void rswap(int & a, int &  b)
{
	int temp = a;
	a = b;
	b = temp;
}

//Pass by Reference example - for primitaves  & = pronounced -> address of
void pswap(int * a, int *  b)
{
	int temp =  * a;
	*a = *b;
	*b = temp;
}

void displayArray(int * theArray, int theArraySize)
{
	for(int i = 0; i < theArraySize; ++i){
		cout << theArray[i] << " ";
	}

	//	Old school C code
	// int i = 0;
	// while( i < theArraySize){
	// 	cout << *(theArray+i++) << " ";
	// }

	cout << endl;
}


