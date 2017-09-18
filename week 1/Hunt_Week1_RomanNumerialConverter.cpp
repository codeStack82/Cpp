/*
* Tyler Hunt
* Advanved C++
* OCCC Fall 2017
* Assignment 1 - Roman Numerials Converter
* Due: 9/17/17
*Reference material
*	https://www.tutorialspoint.com/cplusplus/passing_parameters_by_references.htm
*	https://quizlet.com/2317378/random-roman-numerals-flash-cards/
*/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <exception>
#include <vector>

using namespace std;

//Prototypes
void greetingMsg();
int getManualInput();
int getNumInput();
string getStrInput();
string toUpper(string str);
string moreConversions();
int indexOf(char c);
bool convertRomanToDecimal(string input, int& decimalValue);
bool convertDecimalToRoman(int dec, string& romanValue);


//Main
int main(int argc, char** argv)
{
    string userSelection = "n";
    string romanValue = "";
    int decimalValue = 0;
    bool isValid = false;

    //Display greeting message
    greetingMsg();

    //Process user menu selection(s)
    do{
        //Reset values
		userSelection = "n";
		romanValue = "";
		decimalValue = 0;
		isValid = false;

        int menuSelection = getManualInput();

        if(menuSelection == 1){
        //Display directions
            cout << "\nEnter a number to convert (1 - 4999) : ";

            //Get user Input
            int num = getNumInput();

            //Test if value is value
            isValid = convertDecimalToRoman(num, romanValue);

            //Display results
            if (isValid) {
                cout << "\tThe conversion is: ";
                cout << romanValue << endl;
                cout <<"----------------------------------------------------------------"<< endl;

                //Ask user if they want to continue?
                userSelection = moreConversions();
            }

        }else if(menuSelection == 2){
            //Display directions
            cout << "\nEnter a Roman Numeral to convert : ";

            //Get user input
            string roman = getStrInput();

            //Test is value is value
            isValid = convertRomanToDecimal(roman, decimalValue);

            //Display results
            if (isValid) {
                cout << "\tThe conversion is: ";
                cout << decimalValue << endl;
                cout <<"----------------------------------------------------------------"<< endl;

                //Ask user if they want to continue?
                userSelection = moreConversions();
            }

        }else if(menuSelection == 3 || menuSelection <= 0){
            cout << "You have decided to exit the progam, Thanks!" << endl;

        }else{
            cout << "\tYou have made an illegal menu selection! " << endl;
            cout << "\tPlease read the instructions next time!" << endl;
            cout << "\tThe progam will now close!"<< endl;
        }
    }while(userSelection == "y");

    return 0;
}//eoMain

void greetingMsg()
{   //Contract:
        //Program header
	cout << "\n~~~~~~~~~~~~ Roman Numeral Conversion Utility - Advanced C++ Week 1 ~~~~~~~~~~~~" << endl;

}

int getManualInput()
{   //Contract 
        //  @notes:     Display options, prompt user to make selection 
        //  @params     int, result
        //  @return     int, user selection

 cout << "\nSelect an option: " << endl;
	cout << "\t-Enter (1) to convert from Decimal to Roman numerial " << endl;
	cout << "\t-Enter (2) to convert from Roman numerial to Decimal" << endl;
	cout << "\t-Enter (3) to exit the program" << endl;
	cout << "Please, make a selection: ";

    int input = getNumInput();

	return input;
}

int getNumInput()
{   //Contract 
        //  @notes:     get user number, test value 
        //  @param      int input, input num
        //  @return     int, number

    string in = "";    
    int input = 0;

	try {
		//Get user input
		cin >> in;

		//Convert to integer
		input = atoi(in.c_str());

	}
	catch (exception e) {
		//Handle exception
		cout << "\tApparently, you didn't read the instructions....?" << endl;
		cout << "\tPlease try again....or not!" << endl;
	}
	return input;

}

string getStrInput()
{   //Contract 
        //  @notes:     get user input, test value, convert to upper
        //  @return     string, output


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

string moreConversions()
{   //Contract 
        //  @notes:     ask user if they want to perform another conversion
        //  @return     string, answer

	string in = "";
	string answer = "N";

	try {
		//Get user input
		cout << "Would you like perform another conversion?" << endl;
		cout << "\t-Enter (y) to perform another conversion" << endl;
		cout << "\t-Enter (n) to exit the program" << endl;
		cout << "Please, make your selection: ";

		cin >> in;

		if (in == "n" || in == "N") {
			answer = "n";
		}
		else if (in == "y" || in == "Y") {
			answer = "y";
		}else{
            cout << "Incorrect input. System" << endl;
        }
		cout <<"----------------------------------------------------------------"<< endl;
	}
	catch (exception e) {
		//Handle exception
		cout << "\tApparently, you didn't read the instructions....?" << endl;
		cout << "\tPlease try again....or not!" << endl;
	}
	return answer;
}

string toUpper(string str) 
{   //Contract 
        //  @notes:     toUpper
        //  @param      string, input string
        //  @return     string, uppercased string

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

bool convertDecimalToRoman(int dec, string& romanValue)
{   //Contract 
        //  @notes:     convert decimal to Roman 
        //  @param      int dec, input dec to convert from
        //  @param      string ref, romanValue
        //  @return     bool, isValid roman value

	bool isValid = false;
	string result = "";

	const int SIZE = 13;
	int decVal[SIZE] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	string romanStr[SIZE] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

	int num = dec;

	if (num > 5000 || num < 1) {
		isValid = false;
		cout << "The number you entered is not a valid input!" << endl;
	}
	else {
		int doWork = num;
		while (doWork > 0) {                       
			for (int i = 0; i < SIZE; i++) {

				if (doWork >= decVal[i]) {
					if (decVal[i] > 1000) {
						result += romanStr[i];
					}else {
						result += romanStr[i];
					}
					doWork -= decVal[i];
					break;
				}
			}
		}
        //set reulst into roman value by ref
		romanValue = result;
		isValid = true;
	}
	return isValid;
}

int indexOf(char c) 
{  //Contract 
        //  @notes:     get user number, test value 
        //  @param      int input, input num
        //  @return     int, number
	int i = 0;
	char roman[] = { 'I','V','X','L','C','D','M' };

	for (i = 0; i < 7; ++i) {
		if (roman[i] == c) {
			return i;
		}
	}
	return -1;
}

bool convertRomanToDecimal(string input, int& decimalValue)
{   //Contract 
        //  @notes:     convert roman to dec 
        //  @param      string input, input roman num
        //  @param      int ref dec value, converted from roman value 
        //  @return     bool, isValid dec value

	bool isValid = false;
	for(int i = 0; i < input.length(); i++){

		char numerial = input[i];

		//Switch values
		switch (numerial){ 
			case 'M': 	decimalValue += 1000;
				break;
			case 'D':	decimalValue += 500;
				break;
			case 'C': 	if(i < input.length() && input[i+1] == 'M'){		//test for CM += 900
							decimalValue += 900;
							i++;	//skip numerial
						}else if(i < input.length() && input[i+1] == 'D'){ //test for CD += 400
							decimalValue += 400;
							i++; 	//skip numerial
						}
						else{ decimalValue += 100;} 								//default C += 100
				break;
			case 'L': 	decimalValue += 50;	
				break;
			case 'X': 	if( i < input.length() && input[i+1] == 'C'){		//test for XC += 90
							decimalValue += 90;
							i++;	//skip numerial
						}else if(i < input.length() && input[i+1] == 'L'){ //test for XL += 40
							decimalValue += 40;
							i++; 	//skip numerial
						}
						else{ decimalValue += 10;} 									//default X += 50
				break;
			case 'V': 	decimalValue += 5;
				break;
			case 'I': 	if(i < input.length() && input[i+1] == 'X'){		//test for IX += 9
							decimalValue += 9;
							i++;	//skip numerial
						}else if(i < input.length() && input[i+1] == 'V'){ //test for IV += 4
							decimalValue += 4;
							i++; 	//skip numerial
						}
						else{ decimalValue += 1;} 	 								//default I += 1
				break;
			default:
				cout << "Roman numerial input error\n";
				decimalValue = 0;
				return isValid = false;
		}//eoSwitch
		//cout << decimalValue << endl;

		if (decimalValue < 5000) {
			isValid = true;
		}else {
			isValid = false;
			cout << "There must have been an error!" << endl;
		}
	}//eoFor
	return isValid;
}//eoFunc
