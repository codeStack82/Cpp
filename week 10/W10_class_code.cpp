// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

// usage: Datafilemaker {fileName}{number}{upperLimit}
int main(int argc, char * argv[])
{
	srand((unsigned)time(0));
	//cout << "You gave me " <<  argc << " parameter"<<endl;
	
	//for (int i = 0; i < argc; i++) {
	//	cout << ": " << argv[i] << endl;
	//}

	string fileName;
	int numElements;
	int upperLimits;

	if (argc == 1) {
		cout << "Please enter file name: ";
		getline(cin, fileName);
		cout << "Please enter number of elements: ";
		cin >> numElements;
		cout << "Please enter upperLimit: ";
		cin >> upperLimits;
	}
	else if (argc == 2) {
		cout << "Please enter number of elements: ";
		cin >> numElements;
		cout << "Please enter upperLimit: ";
		cin >> upperLimits;
	}
	else if (argc == 3) {
		fileName = argv[1];
		numElements = atoi(argv[2]);
		upperLimits = 1000;
	}
	else if (argc == 4) {
		fileName = argv[1];
		numElements = atoi(argv[2]);
		upperLimits = atoi(argv[3]);
	}
	else {
		cout << "Please read the document" << endl;
	
	}

	cout << "Writting " << numElements << " elements in range [0, " << upperLimits << "] to file " << fileName << endl;

	ofstream fout;
	fout.open(fileName);

	//if file is open
	if (!fout) {
		cout << "Error opening file : " << fileName << endl;
		exit(0);
	}

	fout << numElements << endl;
	for(int i = 0; i < numElements; i++) {
		//if (i % 10 == 0) cout << endl;
		fout << rand() % upperLimits << " ";
	}
	fout << endl;

    return 0;
}

