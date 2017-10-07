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
bool isOrdinaryPalindrome(char * input);
bool isStrictPalindrome(string input);

int main(int argc, char * argv[]){

    cout << "\n~~~~~~~~~~~~ Palindrome Homework - Advanced C++ Week 4 ~~~~~~~~~~~~" << endl;

    string input;       

    if(argc >= 2){     
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

    cout << "Strict:\t\t" << s_pal << endl;
    cout << "Ordinary:\t" << o_pal << endl;

    string pal;
    int i = 0;
    while(pal[i] != '\0'){
        o_pal[i] = pal[i];
        cout << o_pal[i];
        i++;
    }

    string str_pal;
    int j = 0;
    while(s_pal[j] < input.length()){
        if(isalnum(s_pal[j]) || isspace(s_pal[j])){
            if(isalpha(s_pal[j])){
                str_pal[j] = toupper(s_pal[j]);
            }else{
                str_pal[j] = s_pal[j];
            }
        }
        i++;
    }
    cout << str_pal[j];

    // Test palindromes
//     bool isStrict   = isStrictPalindrome(str_pal);
//    //bool isOrdinary = isOrdinaryPalindrome(o_pal);

//     //if is strict pal
//     if(isStrict){
//         cout << s_pal << " is a Strict palindrome" << endl;
//     }else{
//         cout << s_pal << " is not a Strict palindrome" << endl;
//     }

    //if is Ordinary pal
    // if(isOrdinary){
    //     cout << pal << " is an Ordinary palindrome" << endl;
    // }else{
    //     cout << pal << " is not an Ordinary palindrome" << endl;
    // }

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
bool isOrdinaryPalindrome(char * input) {
    int length = strlen(input);
    if (length <= 1) return true;
    
    if (input[0] != input[length - 1]) {
        return false;
    }else {
        cout << input[0] << "=" << input[length - 1] << endl;
        input[length - 1] = '\0';
        char * shorterWord = &input[1];
        cout << shorterWord << endl;
        return isOrdinaryPalindrome(shorterWord);
    }
}

//Non-destructive strict Palindrome (string)
bool isStrictPalindrome(string input) {
    int length = strlen(input.c_str());
    if (length <= 1) return true;
    
    if (input[0] != input[length - 1]) {
        return false;
    }else {
        string shorterWord = input.substr(1,input.length()-1);
        cout << shorterWord << endl;
        return isStrictPalindrome(shorterWord);
    }
}