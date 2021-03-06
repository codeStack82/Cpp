/*
* Tyler Hunt
* C++
* OCCC Fall 2017
* Assignment 1
* Due: 8/XX/17
*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <exception>
#include <vector>

using namespace std;

//TODO: to test if inputs are valid
	//add bool isValid_RN
	//add bool isValid_Decimal


//Greeting message
void greetingMsg();

//Method toUpper
string toUpper(string str);

//Get numeric input
int get_NumInput();

//Get string input
string get_StrInput();

//Get indexOf char
int indexOf(char);

//Continue conversions
string moreConversions();

//Method: Convert Roman to Decimal
bool convertRomanToDecimal(string str, int& dec);

//Method: Convert Decimal to Roman
bool convertDecimalToRoman(int dec, string& romanValue);

//Main
int main(int argc, char** argv)
{
	//Hold reference values (Roman Numerals and Decimal values)
	string romanValue = "";
	int decimalValue = 0;

	int menuSelection = 0;
	string userSelection = "n";

	if (argc > 0)
	{
		//TODO: not needed for this assn
		userSelection = argv[0];

	}


	do
	{
		//Reset values
		userSelection = "n";
		romanValue = "";
		decimalValue = 0;
		bool isValid = false;

		//Greeting message
		greetingMsg();

		//Get input 
		menuSelection = get_NumInput();

		//Process input
		if (menuSelection == 1){
			//Display directions
			cout << "Please, enter a number to convert between (1 - 3999) : ";

			//Get user Input
			int num = get_NumInput();

			//Test if value is value
			isValid = convertDecimalToRoman(num, romanValue);

			//Display results
			if (isValid) {
				cout << "The conversion is: ";
				cout << romanValue << endl;

				//Ask user if they want to continue?
				userSelection = moreConversions();
			}
		}
		else if (menuSelection == 2){
			//Display directions
			cout << "Please, enter a Roman Numeral to convert : ";

			//Get user input
			string roman = get_StrInput();

			//Test is value is value
			isValid = convertRomanToDecimal(roman, decimalValue);

			//Display results
			if (isValid) {
				cout << "The conversion is: ";
				cout << decimalValue << endl;

				//Ask user if they want to continue?
				userSelection = moreConversions();
			}
		}
		else if (menuSelection == 3){
			//Display directions
			cout << "Thanks for using the Roman Numerial Coversion calculator! " << endl;
			userSelection = "n";
		}
		else{
			cout << "Apparently, you didn't read the instructions....?" << endl;
			cout << "Please try again....or not!" << endl;
		}
	} while (userSelection == "y");

	return 0;
}

//Prompt ~helper method
void greetingMsg()
{
	cout << "~~~~~~~~~~~~ Roman Numeral Conversion Utility - Advanced C++ Week 1 ~~~~~~~~~~~~" << endl;
	cout << "\nSelect an option: " << endl;
	cout << "\tEnter (1) to convert from Roman numerial to Decimal " << endl;
	cout << "\tEnter (2) to convert from Decimal to Roman numerial" << endl;
	cout << "\tEnter (3) to exit the program\n " << endl;
	cout << "Please, make a selection: ";
}

//Prompt for boolean ~helper method
string moreConversions()
{
	//Contract 
		//Get user input
		//Catch error if not valid and exit

	string in = "";
	string answer = "N";

	try {
		//Get user input
		cout << "\nWould you like perform another conversion?" << endl;
		cout << "\tEnter (y) to perform another conversion" << endl;
		cout << "\tEnter (n) to exit the program" << endl;
		cout << "Please, make your selection: ";

		cin >> in;

		if (in == "n" || in == "N") {
			answer = "n";
		}
		else if (in == "y" || in == "Y") {
			answer = "y";
		}
		cout << endl;
		cout <<"------------------------------------------------"<< endl;
		cout << endl;
	}
	catch (exception e) {
		//Handle exception
		cout << "\tApparently, you didn't read the instructions....?" << endl;
		cout << "\tPlease try again....or not!" << endl;
	}
	return answer;
}

//Prompt for integer ~helper method
int get_NumInput(){
	//Contract 
		//Get user number input
		//Catch error if not valid and exit
		//@return 

	string in = "";
	int input = 0;

	try {
		//Get user input
		cin >> in;

		//Convert to integer
		input = atoi(in.c_str());

	}
	catch (Exception e) {
		//Handle exception
		cout << "\tApparently, you didn't read the instructions....?" << endl;
		cout << "\tPlease try again....or not!" << endl;
	}
	return input;
}

//Prompt fro string ~helper method
string get_StrInput(){
	//Contract 
	//Get user number input
	//Catch error if not valid and exit

	string input = "";
	string output = "";

	try {
		//Get user input
		cin >> input;

		output = toUpper(input);
		//cout << output << endl;

	}
	catch (exception e) {
		//Handle exception
		cout << "\tApparently, you didn't read the instructions....?" << endl;
		cout << "\tPlease try again....or not!" << endl;
	}
	return output;
}

//Method  ~helper method
int indexOf(char c) {
	int i = 0;
	char roman[] = { 'I','V','X','L','C','D','M' };

	for (i = 0; i < 7; ++i) {
		if (roman[i] == c) {
			return i;
		}
	}
	return -1;
}

//Method ~helper method
string toUpper(string str) {

	string result;
	//Get only Alpha
	for (int i = 0; i < str.size(); ++i) {
		if (isalpha(str[i])) {
			result += str[i];
		}
	}

	//convert to Upper case
	for (int i = 0; i < result.size(); ++i) {
		if (isalpha(result[i])) {
			result.at(i) = toupper(result.at(i));
		}
	}
	return result;
}

//Method: Convert value from Decimal to Roman
bool convertDecimalToRoman(int dec, string& romanValue){
	//Contract: 
	//Input -> decimal value and string value
	//Check values for validity
	//Find values in array
	//Return boolean if is valid and pass string back via reference

	bool isValid = false;
	string result = "";

	const int SIZE = 13;
	int decVal[SIZE] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	string romanStr[SIZE] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

	int num = dec;

	if (num > 3999 || num < 1) {
		isValid = false;
		cout << "The number you entered is not a valid input!" << endl;
	}
	else {
		int work = num;
		while (work > 0) {  //while work to do and > 0                        
			for (int i = 0; i<SIZE; i++) {
				if (work >= decVal[i]) {
					if (decVal[i] > 1000) {
						result += romanStr[i];
					}
					else {
						result += romanStr[i];
					}
					work -= decVal[i];
					break;
				}
			}
		}
		romanValue = result;
		isValid = true;
	}
	return isValid;
}

//Method: Convert value from Roman to Decimal
bool convertRomanToDecimal(string input, int& decimalValue){
	//Contract: 
	//Input -> decimal value and string value
	//Return boolean if is valid and pass string back via reference

	//TODO: need to perform caps checks --Done
	//TODO: Need to fix return statement -- Done

	bool isValid = false;

	int decVal[] = { 1,5,10,50,100, 500, 1000 };
	char roman[] = { 'I','V','X','L','C','D','M' };

	int n = 0, i, j;

	//Start at end & ignore the escape seq! That bug got me for a while (input[1]-1) not (input[1])
	i = input.length() -1;
	n += decVal[indexOf(input[i])];
	j = i;
	i--;

	while (i >= 0) {
		//cout << input[i] << " >=?  "<< input[j] << endl ;
		if (indexOf(input[i]) >= indexOf(input[j])) {
			//cout << "+" << decVal[indexOf(input[i])] << endl;
			n += decVal[indexOf(input[i])];
		}
		else {
			//cout << "-"<< decVal[indexOf(input[i])] << endl;
			n -= decVal[indexOf(input[i])];
		}
		//cout << n;
		i--;
		j--;
	}

	if (n  < 4000) {
		decimalValue = n;
		isValid = true;
	}
	else {
		isValid = false;
		cout << "There must have been an error!" << endl;
	}
	return isValid;
}