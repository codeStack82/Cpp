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

using namespace std;

void pal_String_Copy(char * source, char * destination);
void isPalindrome(string input);

int main(int argc, char * argv[]){

    cout << "\n~~~~~~~~~~~~ Palindrome Homework - Advanced C++ Week 4 ~~~~~~~~~~~~" << endl;

    string input;       // strict palindrome

    if(argc >= 2){      // TODO: fix cmd line input  
        for(int i = 1; i < argc; i++){
            input.append(argv[i]);
            input.append(" ");
        }
    }else{
        cout << "Enter a palindrome: ";
        getline(cin, input);
    }
    //Create char *[] for ordinary strings and strict strings 
    char * o_pal = new char[input.length() + 1];
    char * s_pal = new char[input.length() + 1];
    strcpy(s_pal, input.c_str());

    pal_String_Copy(s_pal, o_pal);

    cout << s_pal << endl;
    cout << o_pal << endl;

    string pal;
    for(int i = 0; i != '\0'; i++){
        pal[i] = o_pal[i];
    }
    cout << "pal: " << pal << endl;

    isPalindrome(pal);

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

void isPalindrome(string input){
    //int length = input.length();
    //if(length <= 1) return true;
    //cout << length << endl;
    
}