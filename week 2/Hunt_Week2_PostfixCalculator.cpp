/*
* Tyler Hunt
* Advanved C++
* OCCC Fall 2017
* Assignment 2 - PostFix Calculator
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
#include <sstream>
#include <vector>

using namespace std;

//Prototypes
void greetingMsg();
int getMenuSelection();
int menuSelection();
string getStrInput();
string moreConversions();

int convertToInt(string num);

vector<string> addToVector(string input);
void printVector(vector<string> tokens);

void performPostfixCalc();



//Main
int main(int argc, char** argv)
{
    //Display greeting message
    greetingMsg();

    // Test input values 
    //5 4 + 3 10 * +	

    //Process user menu selection(s)
    string moreCalcs = "n";
    string input = "";
    int menuSelection = getMenuSelection();
    vector<string> tokens;


    do{
        //Reset values
		moreCalcs = "n";

        if(menuSelection == 1){

            string input = getStrInput();
            tokens = addToVector(input); 
                // printVector(tokens);

            for(string i : tokens){

                bool isOperand = isNum(i);
                bool isOperator = is
                //check token
                if(isOperand){

                }else if(isOperator){

                }
                
                cout << "tokens = " << i << endl;
            }

        }else{

        }

        //Check to see if user want to continue testing other strings
        moreCalcs = moreConversions();
       
    }while(moreCalcs == "y");

    return 0;
}//eoMain

void greetingMsg()
{   //Contract:
        //Program header
	cout << "\n~~~~~~~~~~~~ PostFix Calculator - Advanced C++ Week 2 ~~~~~~~~~~~~" << endl;
}

int getMenuSelection()
{   //Contract 
        //  @notes:     Display options, prompt user to make selection 
        //  @params     int, result
        //  @return     int, user selection

    cout << "\nSelect an option: " << endl;
	cout << "\t-Enter (1) to calculate a PostFix string" << endl;
	cout << "\t-Enter (2) to exit the program" << endl;
	cout << "Please, make a selection: ";

    int option = menuSelection();

	return option;
}

int menuSelection()
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

	try {
        cout << "\nPlease, enter your postfix calculation string: ";
     
		//Get user input
        cin.ignore();
        getline(cin, input);
        cout << endl;

	}
	catch (exception e) {
		//Handle exception
		cout << "\tApparently, you didn't read the instructions....?" << endl;
		cout << "\tPlease try again....or not!" << endl;
	}
	return input;
}

string moreConversions()
{   //Contract 
        //  @notes:     ask user if they want to perform another conversion
        //  @return     string, answer

	string in = "";
	string answer = "N";

	try {
		//Get user input
		cout << "Would you like perform another postfix calculation?" << endl;
		cout << "\t-Enter (y) to perform another postfix calculations" << endl;
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

int convertToInt(string num)
{   //Contract 
        //  @notes:     get  number, test value 
        //  @param      int input, input num
        //  @return     int, number

    int input = 0;

	try {

		//Convert to integer
		input = atoi(num.c_str());

	}
	catch (exception e) {
		//Handle exception
		cout << "\tApparently, converting to int is having trouble?" << endl;
		cout << "\tPlease try again....!" << endl;
	}
	return input;
}

int performPostfixCalc(string token)
{ //Contract 
        //  @notes:     Accepts token and 
        //  @param      int input, input num
        //  @return     int, number
        

        if(isOperand){

        }else if(isOperator){

        }

}

vector<string> addToVector(string input)
{  //Contract 
        //  @notes:     pushes string into vector as tokens
        //  @return     vector<string>, tokens

    string buffer; 
    stringstream ss(input); 
    vector<string> tokens;

    while (ss >> buffer){
        tokens.push_back(buffer);
    }

    return tokens;
}

void printVector(vector<string> tokens)
{  //Contract 
        //  @notes:     prints vector contents
        //  @return     void

    for(string i : tokens){
        cout << "tokens = " << i << endl;
    }
}
