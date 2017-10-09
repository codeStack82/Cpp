 /*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   Due: 10/7/17
*   Details: Palindromes
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <regex>

using namespace std;

void pal_String_Copy(char * source, char * destination);
bool isPalindrome(char * input);

int main(int argc, char * argv[]){

    cout << "\n~~~~~~~~~~~~ Palindrome Homework - Advanced C++ Week 4 ~~~~~~~~~~~~" << endl;
    string input;       

    if(argc >= 2){     
        for(int i = 1; i < argc; i++){
            input.append(argv[i]);
            input.append(" ");
        }
    }else{
        cout << "Please, enter a palindrome: ";
        getline(cin, input);
    }

    //Create char *[] for ordinary strings and strict strings 
    char * o_pal = new char[input.length() + 1];
    char * s_pal = new char[input.length() + 1];
    strcpy(s_pal, input.c_str());

    pal_String_Copy(s_pal, o_pal);

    bool isPal = isPalindrome(o_pal);
    if(isPal){
        cout <<"\t" << s_pal << " is a palindrome" << endl;
    }else{
        cout <<"\t"  << s_pal << " is not a palindrome" << endl;
    }

    return 0;
}

void pal_String_Copy(char * source, char * destination){
    int sourceIndex = 0;
    int destIndex = 0;

    while(source[sourceIndex] != '\0'){
        while(!isalnum(source[sourceIndex]) && source[sourceIndex] != '\0' ){
            sourceIndex++;
        }
        if(source[sourceIndex] == '\0') break;

        if(isalpha(source[sourceIndex])){
            destination[destIndex] = toupper(source[sourceIndex]);
        }
        if(isdigit(source[sourceIndex])){
            destination[destIndex] = source[sourceIndex];
        }
        sourceIndex++;
        destIndex++;
    }
     destination[destIndex] = '\0';
}

//Destructive ordinary Palindrome
bool isPalindrome(char * input) {
    int length = strlen(input);
    if (length <= 1) return true;
    
    if (input[0] != input[length - 1]) {
        return false;
    }else {
        //cout << input[0] << "=" << input[length - 1] << endl;
        input[length - 1] = '\0';
        char * shorterWord = &input[1];
        //cout << shorterWord << endl;
        return isPalindrome(shorterWord);
    }
}
