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
#include <stdout>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <exception>
#include <vector>
using namespace std;

//Prototype functions

int main(){

	//Intro message
	cout << "Welcome to Vector Demo!" << endl;
	cout << "Please enter array size: ";

	//declare a vector
	vector<int> v1;			//declare
	vector<int> v2(10);		// declare initialize w/10

	for(int i = 0; i < 10; ++i){
		v2.push_back(i);
	}

	for(int i = 0; i < 10; ++i){
		cout << i << ": " << v2[i] << endl; 
	}

	return EXIT_SUCCESS; //default successful execution
}
