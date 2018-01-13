/*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   Hunt_W10_Ciphers.cpp
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
 
 
using namespace std;

// Playfair Cipher
string pEncode(string key, string message);
string pDecode(string key, string message);
 
// Vigenère Ciphers 
string vEncode(string key, string message);
string vDecode(string key, string message);

//Helper Functions
void usageMessage();
void moreActions(int &more);
void getUserInput(string &algorithm, string &action, string &input_file, string &output_file, string &key);
bool isValidParameters(string &algorithm, string &action);
bool isAlgorithm(string &algorithm);
bool isAction(string &action);
 
void parametres(string algorithm, string action, string input_file, string output_file, string key);
 
 
int main(int argc, char** argv)
{
    string algorithm, action, input_file, output_file, key;
    int more = 0;

    cout << "\n~~~~~~~~~~~~ Cipher Homework - Advanced C++ Week 10 ~~~~~~~~~~~~~~\n" << endl;

    if(argc == 2){
        string h = argv[1];
        if(h == "/?"){
            usageMessage();
        }
    }else{
        do{
            if(argc >= 2){
                //Get cmd input from user
                algorithm = argv[1];
                action = argv[2];
                input_file = argv[3];
                output_file = argv[4];
                key = argv[5];
                argc = 0;
            }else{
                //Prompt for input
                getUserInput(algorithm, action, input_file, output_file, key);
            }

            bool isValid = isValidParameters(algorithm, action);
            cout << "isValid: " << isValid << endl;
            if(isValid){
                parametres(algorithm, action, input_file, output_file, key);           
            }else{
                usageMessage();
            }

            //Check if user wants to continue
            moreActions(more);

        }while(more == 0);
        
    }
}//eoMain
 
void parametres(string algorithm, string action, string input_file, string output_file, string key)
{
    ifstream ifile(input_file);
    ofstream ofile(output_file);
    string line;
 
    if(!ifile.is_open()){
        cout << "Something wrong with input file. Please recheck or try again" << endl;
        return;
    }
 
    if(!ofile.is_open()){
        cout << "Something wrong with output file. Please recheck or try again" << endl;
        return;
    }
 
    if(algorithm == "/p") {
        if(action == "/e") {
 
            cout << "\nEncrypting using the Playfair Algorithm..." << endl;
            while ( getline (ifile,line) ) {
                string eLine = pEncode(key, line);
                ofile << eLine << endl;
            }
        } else if(action == "/d") {
 
            cout << "\nDecrypting using the Playfair Algorithm..." << endl;
            while ( getline (ifile,line) ) {
                string eLine = pDecode(key, line);
                ofile << eLine << endl;
            }
        }
 
    }else if(algorithm == "/v") {
        if(action == "/e") {
 
            cout << "\nEncrypting using the Vigenere Algorithm..." << endl;
            while ( getline (ifile,line) ) {
                string eLine = vEncode(key, line);
                ofile << eLine << endl;
            }
 
        } else if(action == "/d") {
            cout << "\nDecrypting using the Vigenere Algorithm..." << endl;
            while ( getline (ifile,line) ) {
                string eLine = vDecode(key, line);
                ofile << eLine << endl;
            }
        }
    }
 
    ifile.close();
    ofile.close();
}
 
string vEncode(string key, string message) {
 
    // cout << "*** vigenere encoding function *** " << endl;
    string alpha = "`1234567890-=~!@#$%^&*()_+qwertyuiop[]\\QWERTYUIOP{}|asdfghjkl;'ASDFGHJKL:\"zxcvbnm,./ZXCVBNM<>? ";
 
    if (message[message.length() - 1] == '\n'){
        message.erase(message.length() - 1);
    }
 
    string pairedKey = "";
    for (int i = 0, j = 0; i < message.length(); i++, j++){
        pairedKey += key[j];
        if (j == key.length() - 1){
            j = -1;
        }
    }
 
    string eMessage = "";
    string vRow = "";
    for (int i = 0; i < pairedKey.length(); i++){
        for (int j = alpha.find(pairedKey[i]); j < alpha.length(); j++){
            vRow += alpha[j];
            if (j == alpha.length()-1){
                for (int k = 0; k < alpha.find(pairedKey[i]); k++){
                    vRow += alpha[k];
                }
            }
        }
        eMessage += vRow[alpha.find(message[i])];
        vRow = "";
    }
    return eMessage;
}
 
string vDecode(string key, string message){
 
    // cout << "*** vigenere decode function *** " << endl;
    // string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alpha = "`1234567890-=~!@#$%^&*()_+qwertyuiop[]\\QWERTYUIOP{}|asdfghjkl;'ASDFGHJKL:\"zxcvbnm,./ZXCVBNM<>? ";
 
    if (message[message.length() - 1] == '\n'){
        message.erase(message.length() - 1);
    }
 
    string pairedKey = "";
    for (int i = 0, j = 0; i < message.length(); i++, j++){
        pairedKey += key[j];
        if (j == key.length() - 1){
            j = -1;
        }
    }
 
    string dMessage = "";
    string vRow = "";
    for (int i = 0; i < pairedKey.length(); i++){
        for (int j = alpha.find(pairedKey[i]); j < alpha.length(); j++){
            vRow += alpha[j];
            if (j == alpha.length() - 1){
                for (int k = 0; k < alpha.find(pairedKey[i]); k++){
                    vRow += alpha[k];
                }
            }
        }
        dMessage += alpha[vRow.find(message[i])];
        vRow = "";
    }
 
    return dMessage;
}
 
string pEncode(string key, string message){
 
    // cout << "*** playfair encode function *** " << endl;
    const int SIZE = 6;
    string alpha = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 
    for (int i = 0; i < key.length(); ++i){
        key[i] = toupper(key[i]);
    }
    for (int i = 0; i < message.length(); ++i){
        message[i] = toupper(message[i]);
    }
 
    string prepedKey = "";
    bool duplicate = false;
    for (int i = 0; i < key.length(); ++i){
        for (int j = 0; j < prepedKey.length(); ++j){
            if (key[i] == prepedKey[j]){
                duplicate = true;
            }
        }
        if (duplicate == false && isalnum(key[i])){
            prepedKey += key[i];
        }
        duplicate = false;
    }
    string prepAlpha = prepedKey;
    for (int i = 0; i < alpha.length(); ++i){
        for (int j = 0; j < prepAlpha.length(); ++j){
            if (alpha[i] == prepAlpha[j]){
                duplicate = true;
            }
        }
        if (duplicate == false){
            prepAlpha += alpha[i];
        }
        duplicate = false;
    }
    
    char table[SIZE][SIZE];
    int iterator = 0;
    for (int i = 0; i < SIZE; ++i){
        for (int j = 0; j < SIZE; ++j){
            table[i][j] = prepAlpha[iterator];
            iterator++;
        }
    }
 
    string cutMessage = "";
    for (int i = 0; i < message.length(); ++i){
        if (isalnum(message[i])){
            cutMessage += message[i];
        }
    }
     
    string prepedMessage = "";
    for (int i = 0; i < cutMessage.length(); ++i){
        if (i == 0){
            prepedMessage += cutMessage[i];
            continue;
        }
        else{
            if (cutMessage[i - 1] == cutMessage[i]){
                prepedMessage += 'X';
                prepedMessage += cutMessage[i];
            }
            else{
                prepedMessage += cutMessage[i];
            }
        }
    }
    //cout << prepedMessage << endl;
    if (cutMessage.length() % 2 == 0){
        prepedMessage += "X";
    }
    //cout << prepedMessage.length() << endl;
    //cout << prepedMessage << endl;
    int first[2] = { 0 };
    int last[2] = { 0 };
    string digraph = "";
    string eMessage = "";
    for (int i = 1; i < prepedMessage.length(); i+=2){
            digraph += prepedMessage[i-1];
            digraph += prepedMessage[i];
            for (int j = 0; j < SIZE; ++j){
                for (int k = 0; k < SIZE; ++k){
                    if (table[j][k] == digraph[0]){
                        first[0] = j;
                        first[1] = k;
                    }
                }
            }
            for (int j = 0; j < SIZE; ++j){
                for (int k = 0; k < SIZE; ++k){
                    if (table[j][k] == digraph[1]){
                        last[0] = j;
                        last[1] = k;
                    }
                }
            }
 
            for (int row = 0; row < SIZE; ++row){
                for (int col = 0; col < SIZE; ++col){
                    if (table[row][col] == digraph[0]){
                        if (row < SIZE - 1 && last[1] == col){
                            eMessage += table[row + 1][col];
                            //cout << " " << table[row + 1][col];
                        }
                        else if (row == SIZE - 1 && last[1] == col){
                            eMessage += table[0][col];
                            //cout << " " << table[0][col];
                        }
                        else{
                            eMessage += table[row][last[1]];
                            //cout << " " << table[row][last[1]];
                        }
                    }
                }
            }
            for (int row = 0; row < SIZE; ++row){
                for (int col = 0; col < SIZE; ++col){
                    if (table[row][col] == digraph[1]){
                        if (row < SIZE - 1 && first[1] == col){
                            eMessage += table[row + 1][col];
                            //cout << " " << table[row + 1][col];
                        }
                        else if (row == SIZE - 1 && first[1] == col){
                            eMessage += table[0][col];
                            //cout << " " << table[0][col];
                        }
                        else{
                            eMessage += table[row][first[1]];
                            //cout << " " << table[row][first[1]];
                        }
 
                    }
                }
            }
            //cout << " " << digraph << " " << eMessage << endl;
         
        digraph = "";
    }
    //cout << endl;
    return eMessage;
}
 
string pDecode(string key, string message){
 
    // cout << "*** playfair decode function *** " << endl;
    const int SIZE = 6;
    string alpha = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";
     
    for (int i = 0; i < key.length(); ++i){
        key[i] = toupper(key[i]);
    }
    for (int i = 0; i < message.length(); ++i){
        message[i] = toupper(message[i]);
    }
     
    string prepedKey = "";
    bool duplicate = false;
    for (int i = 0; i < key.length(); ++i){
        for (int j = 0; j < prepedKey.length(); ++j){
            if (key[i] == prepedKey[j]){
                duplicate = true;
            }
        }
        if (duplicate == false && isalnum(key[i])){
            prepedKey += key[i];
        }
        duplicate = false;
    }
 
    string prepAlpha = prepedKey;
    for (int i = 0; i < alpha.length(); ++i){
        for (int j = 0; j < prepAlpha.length(); ++j){
            if (alpha[i] == prepAlpha[j]){
                duplicate = true;
            }
        }
        if (duplicate == false){
            prepAlpha += alpha[i];
        }
        duplicate = false;
    }
    char table[SIZE][SIZE];
    int iterator = 0;
    for (int i = 0; i < SIZE; ++i){
        for (int j = 0; j < SIZE; ++j){
            table[i][j] = prepAlpha[iterator];
            iterator++;
        }
    }
     
    string cutMessage = "";
    for (int i = 0; i < message.length(); ++i){
        if (isalnum(message[i])){
            cutMessage += message[i];
        }
    }
     
    string prepedMessage = cutMessage;
 
    int first[2] = { 0 };
    int last[2] = { 0 };
    string digraph = "";
    string dMessage = "";
    for (int i = 1; i < prepedMessage.length(); i += 2){
        digraph += prepedMessage[i - 1];
        digraph += prepedMessage[i];
        for (int j = 0; j < SIZE; ++j){
            for (int k = 0; k < SIZE; ++k){
                if (table[j][k] == digraph[0]){
                    first[0] = j;
                    first[1] = k;
                }
            }
        }
        for (int j = 0; j < SIZE; ++j){
            for (int k = 0; k < SIZE; ++k){
                if (table[j][k] == digraph[1]){
                    last[0] = j;
                    last[1] = k;
                }
            }
        }
 
        for (int row = 0; row < SIZE; ++row){
            for (int col = 0; col < SIZE; ++col){
                if (table[row][col] == digraph[0]){
                    if (row < SIZE - 1 && last[1] == col){
                        dMessage += table[row + 1][col];
                        ////cout << " " << table[row + 1][col];
                    }
                    else if (row == SIZE - 1 && last[1] == col){
                        dMessage += table[0][col];
                        ////cout << " " << table[0][col];
                    }
                    else{
                        dMessage += table[row][last[1]];
                        ////cout << " " << table[row][last[1]];
                    }
                }
            }
        }
        for (int row = 0; row < SIZE; ++row){
            for (int col = 0; col < SIZE; ++col){
                if (table[row][col] == digraph[1]){
                    if (row < SIZE - 1 && first[1] == col){
                        dMessage += table[row + 1][col];
                        ////cout << " " << table[row + 1][col];
                    }
                    else if (row == SIZE - 1 && first[1] == col){
                        dMessage += table[0][col];
                        ////cout << " " << table[0][col];
                    }
                    else{
                        dMessage += table[row][first[1]];
                        ////cout << " " << table[row][first[1]];
                    }
 
                }
            }
        }
 
        digraph = "";
    }
    return dMessage;
}

//Helper Functions
bool isValidParameters(string &algorithm, string &action){
    bool isValid_Algorithm = isAlgorithm(algorithm);
    bool isValid_Action = isAction(algorithm);
    if(isValid_Algorithm && isValid_Action){
        return true;
    }else{
        return false;
    }
}

bool isAlgorithm(string &algorithm){
    if(algorithm == "vigenere"){
        return "/v";
    }else if(algorithm == "/vigenere"){
        return "/v";
    }else if(algorithm == "v"){
        return "/v";
    }else if(algorithm == "/v"){
        return "/v";
    }else if(algorithm == "playfair"){
        return "/p";
    }else if(algorithm == "/playfair"){
        return "/p";
    }else if(algorithm == "p"){
        return "/p";
    }else if(algorithm == "/p"){
        return "/p";
    }else{
        return "/?";
    }
}
     
bool isAction(string &action){
    if(action == "encrypt"){
        return "/e";
    }else if(action == "/encrypt"){
        return "/e";
    }else if(action == "e"){
        return "/e";
    }else if(action == "/e"){
        return "/e";
    }else if(action == "decrypt"){
        return "/d";
    }else if(action == "/decrypt"){
        return "/d";
    }else if(action == "d"){
        return "/d";
    }else if(action == "/d"){
        return "/d";
    }else{
        return "/?";
    }
}

void moreActions(int &more){
     cout << "\nWould you like to perform another action? (y or n): " ;
        string answer = "";
        cin >> answer;
        if(answer == "y" || answer == "Y"){
            more = 0;
        }else{
            cout << "\nThank you for using the worlds most advanced C++ encryption tool!" << endl;
            more++;
        }
        cout << endl;

}

void getUserInput(string &algorithm, string &action, string &input_file, string &output_file, string &key){
        //Prompt for input
        cout << "Note: For help use the '/?' operator\n" << endl;

        cout << "Please enter the algorithm you want to use? " << endl;
        cout << "\tExample: (vigenere or playfair) or (/v or /p): " ;
        cin >> algorithm;
 
        cout << "Please enter an action to perform?" << endl;
        cout << "\tExample: (encrypt or decrypt) or (/e or /d): " ;
        cin >> action;
 
        cout << "Please enter input file name" << endl;
        cout << "\tExample: (input.txt): " ;
        cin >> input_file;
 
        cout << "Please enter output file name " << endl;
        cout << "\tExample: (output.txt): " ;
        cin >> output_file;
 
        cout << "Please enter key " << endl;
        cout << "\tExample: (4t5): " ;
        cin >> key;
}

void usageMessage(){
    cout << "Program useage details:" << endl << endl;
    cout << "\tThe '/?' switch is used to invoke the useage menu.\n" << endl;

    cout << "\tFirst, enter the algorithm you want to use." << endl;
    cout << "\t\tExample: (vigenere or playfair) or (/v or /p)"  << endl;

    cout << "\tSecond, enter an action that you want to perform." << endl;
    cout << "\t\tExample: (encrypt or decrypt) or (/e or /d)"  << endl;

    cout << "\tThird, enter input file name" << endl;
    cout << "\t\tExample: (input.txt): "  << endl;

    cout << "\tFouth, enter output file name " << endl;
    cout << "\t\tExample: (output.txt): "  << endl;

    cout << "\tFinally, enter key or keyphrase" << endl;
    cout << "\t\tExample: (4t5):" << endl;

}
