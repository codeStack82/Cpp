/*
* Tyler Hunt
* Advanved C++
* OCCC Fall 2017
* Assignment 2 - PostFix Calculator
* Due: 9/17/17
*Reference material
*	http://www.cs.nthu.edu.tw/~wkhon/ds/ds10/tutorial/tutorial2.pdf
*   http://www.cs.csi.cuny.edu/~zelikovi/csc326/data/assignment5.htm
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
void printVector(vector<int> tokens);

bool checkToken(string nextToken);


int performPostfixCalc(int res1, int res2, char operand);



//Main
int main(int argc, char** argv)
{
    //Display greeting message
    greetingMsg();

    // Test input values 
    // 5 4 + 3 10 * +	

    //Process user menu selection(s)
    string moreCalcs = "n";
    string input = "";
    int menuSelection = getMenuSelection();
    vector<string> tokens;
    vector<int> results;


    do{
        //Reset values
		moreCalcs = "n";

        if(menuSelection == 1){

            string input = getStrInput();
            tokens = addToVector(input); 
            //printVector(tokens);
         
            for(int i = 0; i < tokens.size(); i++){
                //Get nextToken
                string nextToken = tokens[i];

                bool isOperator = checkToken(nextToken);

                if(isOperator){ // + - * / %
                    cout << "isOperator: " << isOperator << " : " << nextToken << endl;
                    char nextOperator = nextToken[0];

                    // Test Cases 
                        // 5 4 + 3 10 * +            39
                        // +5 -4 + 3 10 * +          31
                        // 4 5 7 2 + - *            -16
                        // 3 4 + 2  * 7 /             2
                        // 5 7 + 6 2 -  *            48
                        // 4 2 3 5 1 - + * +         18
                        // 4 2 + 3 5 1 -  * +        18
                        // 2 3 4 + * 6 -              8
                        // 10 5 % 2 +                 4

                    if(results.size() >= 2){
                        int res1 = results.back();
                            results.pop_back();
                            cout << "\ttoken popped: " << res1 << endl;

                        int res2 = results.back();
                            results.pop_back();
                            cout << "\ttoken popped: " << res2 << endl;

                        int result = performPostfixCalc(res1, res2, nextOperator);
                        cout << "\tCalc'd: " << res1 << " " << nextOperator << " " << res2 <<  " = " << result << endl;
                        results.push_back(result);
                        printVector(results);
                    }
                }else if(!isOperator){
                    cout << "isOperator: " << isOperator << " : " << nextToken << endl;

                    //convert and push token
                    int token = convertToInt(nextToken);
                    results.push_back(token);               //push token
                }

            }//eoFor

           cout << "Final result: " << results[0] << endl;
            results.clear();
           cout << endl;
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
		cout << "Would you like perform another postfix calculation? (y or n): ";
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

bool checkToken(string nextToken)
{ //Contract 
    //  @notes:     checks if is Operand
    //  @return     bool, token

    bool isValid = false;

    //Test if string length is > 1 (i.e. not a -9, +16, 50)
    if(nextToken.length() > 1){
        isValid = false;
        return isValid;
    }

    char testToken = nextToken[0];

    switch(testToken){
        case '+' : isValid = true; 
            break;
        case '-' : isValid = true; 
            break;
        case '*' : isValid = true; 
            break;
        case '/' : isValid = true; 
            break;
        case '%' : isValid = true; 
            break;
        default :
            isValid = false; 
    }

    return isValid;
}

int performPostfixCalc(int res1, int res2, char operand)
  {//Contract 
    //  @notes:     performs math logic on results
    //  @return     int, result

    int result = 0;

    switch(operand){
        case '+' :  result = res2 + res1;
            break;
        case '-' :  result = res2 - res1;
            break;
        case '*' :  result = res2 * res1;
            break;
        case '/' :  result = res2 / res1;
            break;
        case '%' :  result = res2 % res1;
            break;
        default :
            result = 0; 
    }
    return result;
}

void printVector(vector<string> tokens)
{  //Contract 
        //  @notes:     prints vector contents
        //  @return     void

    for(int i =0; i < tokens.size(); i++){
        cout << "tokens = " << tokens[i] << endl;
    }
}

void printVector(vector<int> tokens)
{  //Contract 
        //  @notes:     prints vector contents
        //  @return     void
    cout << "\ttokens = ";
    for(int i =0; i < tokens.size(); i++){
        cout << tokens[i] << " ";
    }
     cout << endl;
}
