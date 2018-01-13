//Zabrina Antry
//Singly linked list demo
//C++
//OCCC Fall 2017
//Resource: Tyler Hunt

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//Create Bag Class
class BagClass {
	//Private data members 
private:

	//Struct declaration
	struct BagNode {
		string dataValue;
		int dataCount;

		//Points to next node in bag node.
		BagNode *next;
		BagNode(string);
	};

	// Node declaration 
	BagNode *root;

public:
	//Class Constructor
	BagClass() {
		root = NULL;
	}

	//Function definition for reading the file
	void readFile(string ifile, string ofile) {
		ifstream infile;
		infile.open(ifile.c_str());

		//Check if file is good.
		if (!infile.good()) {
			//Display Message if not good
			cout << "Input file not opening." << endl;
			return;
		}

		// Reads the content from text file line by line
		string line;
		while (getline(infile, line)) {
			//Used stringstream library for specific format
			stringstream lineStream(line);
			string token = "";
			while (lineStream >> token) {
				//Calls the insert data function after removing the punctuations from word
				insertData(removeTrailingsPunctuations(token));
			}
		}
		//Close the file after all processing of reading
		infile.close();
		traverseContent();
		cout << endl << "File processed successfully." << endl;
	}

	//Function definition for removing the punctuations and trailings from text
	string removeTrailingsPunctuations(string data) {
		int length = data.size();
		for (int i = 0; i < length; i++)
		{
			if (ispunct(data[i])) {
				data.erase(i--, 1);
				length = data.size();
			}
		}
		return data;
	}

	//Function definition to remove data from list
	void removeDataFromList(string data) {
		//Create 2 bagnode objects
		BagNode *temp = root;
		BagNode *prev = NULL;

		// If the word is same
		if (root->dataValue.compare(data) == 0) {
			//Decrement the count until it is 1
			if (root->dataCount > 1) {
				//Decrements the count of that word
				root->dataCount--;
			}
			else {
				//Delete the complete node if count is < 1
				delete root;
				root = NULL;
			}
			//Display the message of data removal
			cout << "Data removed successfully." << endl;
			return;
		}
		//If we have a list of words
		while (temp != NULL) {
			//If the word is same
			if (temp->dataValue.compare(data) == 0) {
				//Decrement the count until it is 1
				if (temp->dataCount > 1) {
					//Decrements the count of that word
					temp->dataCount--;
				} else {
					prev->next = temp->next;
					delete temp;
					temp = NULL;
				}
				cout << "Data successfully removed!" << endl;
				return;
			}
			prev = temp;
			temp = temp->next;
		}
		cout << "No match found!" << endl;
	}

	void traverseContent() {
		// If the list is empty 
		if (root == NULL) {
			// Displays the message
			cout << "There is no data!" << endl;
			return;
		}

		//Declare the Bagnode object
		BagNode *temp = root;

		//Traverse the complete list
		while (temp != NULL) {
			//If count of any specific word is > 1
			if (temp->dataCount > 1) {
				//Display the content with word and with word count > 1
				cout << temp->dataValue << " (" << temp->dataCount << ")" << endl;
			}
			else {
				//Display the word only
				cout << temp->dataValue << endl;
			}
			//Move to the next node
			temp = temp->next;
		}
	}

	//Function definition to convert the text into lower case
	string convertToLowerCase(string data) {
		for (int i = 0; data[i]; i++) {
			//Calls the tolower function to convert the alphabets into lower case
			data[i] = tolower(data[i]);
		}
		//Returns the full string
		return data;
	}

	// Function definition to insert the data
	void insertData(string data) {
		//Create a new node
		BagNode *n = new BagNode(data);

		//If the list is empty
		if (root == NULL) {
			root = n;
			return;
		}

		//Create 2 node objects
		BagNode *temp = root;
		BagNode *prev = NULL;

		string tdata;
		data.assign(convertToLowerCase(data));
		while (temp != NULL) {
			tdata.assign(temp->dataValue);
			tdata.assign(convertToLowerCase(tdata));

			//If the word is same
			if (tdata.compare(data) == 0) {
				//Increments its count only
				temp->dataCount++;
				return;
			}
			else {
				//If the word is different or unique
				if (data.compare(tdata) < 0) {
					//If it is the first element
					if (temp == root) {
						n->next = temp;
						root = n;
						return;
					}
					//If it is not the first elemen
					else {
						n->next = temp;
						prev->next = n;
						return;
					}
				}
			}
			prev = temp;
			temp = temp->next;
		}

		n->next = temp;
		prev->next = n;
	}


};

//Definition for struct BagNode of Class Bag
BagClass::BagNode::BagNode(string data)
{
	//Sets the data for node
	dataValue.assign(data);
	//Sets the counter to 1 for specific word
	dataCount = 1;
	//Sets the next link as null
	next = NULL;
}

int main(int argc, char *argv[]) {
	bool outputConsole = false;
	string infile, outfile = "\0";
	cout << "Welcome to the Bag Program!" << endl;
	int option = -1;
	do {
		//Command line arguments
		if (argc == 1 || option == 1) {
			cout << "Please enter an input file: ";
			cin >> infile;
			cout << "Please enter an output file: ";
			cin >> outfile;
		}
		else
		{
			infile.assign(argv[1]);
			if (argc == 3) {
				outfile.assign(argv[2]);
			}
		}

		BagClass b;
		b.readFile(infile, outfile);

		//Asks the user if he/she wants to continue or not
		cout << endl << "If you want to input another file press 1 or 2 to quit: ";
		cin >> option;
	} while (option != 2);

	return 0;
}