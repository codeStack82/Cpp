 /*
*   Tyler Hunt
*   Advanved C++
*   OCCC Fall 2017
*   Due: 10/27/17
*   Details: Bag Homework
*/

#include <iostream>
#include <typeinfo>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <fstream>
#include <map>
#include <utility>
#include <string>
#include <algorithm>
#include <ctype.h>
using namespace std;

struct BagNode{
    int dataCount;
    string dataValue;
    struct node *next;
};

struct BagNode *newNode(string dataValue){
    struct BagNode *temp =  (struct BagNode *)malloc(sizeof(struct BagNode));
    temp->dataValue = dataValue;
    temp->dataCount = 1;
    temp->next = NULL;
    return temp;
}

ifstream infile;
ofstream outfile;

int main(int argc, char * argv[]){
    cout << "\n~~~~~~~~~~~~ Bag Homework - Advanced C++ Week 7 ~~~~~~~~~~~~~~" << endl;
    string inputFileName = "", outputFileName = "";

    if(argc == 3){                      // Get file names from cmd line
        inputFileName = argv[1];
        outputFileName = argv[2];
        cout << "\nInput File name "    << inputFileName << endl;
        cout << "\nOutput File name "   << outputFileName << endl;
    }else if(argc == 2){                // Else prompt for file names
        inputFileName = argv[1];
        cout << "\nInput File name: " << inputFileName << endl;
    }

    if(inputFileName.size() == 0){      // Check if input file name is zero
        cout << "\nPlease, enter input file name. (ex: list1.txt) " << endl;
        cout << "File name: ";
        cin >> inputFileName;
        cout << "\nInput File Name: " << inputFileName << endl;
    }

    try{                                // try/catch if input file name good
        infile.open(inputFileName,fstream::in);
        if(!infile.good()){
            throw 404;
        }
    }catch(int e){
        cout << "Unable to open input file."<< endl;
        cout << "Exiting Program." << endl;
        return 0;
    }

    //Create instance of map bag and iterator
    map<string,struct BagNode*> bagMap;
    map<string,struct BagNode*>::iterator it;
    string str;

    // Process input file
    while(infile >> str){

        // Remove Punctuation
        for (int i = 0, len = str.size(); i < len; i++){
            if (ispunct(str[i])){
                str.erase(i--, 1);
                len = str.size();
            }
        }

        // Store to map
        string lower = str;
        transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
        it = bagMap.find(lower);

        if (it != bagMap.end()){
            bagMap[lower]->dataCount += 1;
        }else{
            BagNode *tmp = newNode(str);
            bagMap.insert(pair<string,struct BagNode*>(lower,tmp));
        }
    }
    // Input file clean up
    infile.close();

    // Process output file
    if(outputFileName.size()==0 && argc !=2){
        cout << "\nPlease, enter output file name. (ex: list1.txt) " << endl;
        cout << "File name: ";
        cin >> outputFileName;
        cout << "\nOutput File Name: " << outputFileName << endl;
    }

    if(outputFileName.size() > 0){
        outfile.open(outputFileName,fstream::out);
        // Write to file
        for (map<string,struct BagNode*>::iterator it=bagMap.begin(); it!=bagMap.end(); ++it){
            outfile << it->second->dataValue << " ";
            if(it->second->dataCount > 1){
                outfile << "(" <<it->second->dataCount << ")";
            }
            outfile << endl;
        }
        // Output file clean up
        //cout << "Output File Name: " << outputFileName << endl; 
        outfile.close();
        cout << "\nData written to " << outputFileName << "."<<endl;
    }
    else{
        for (map<string,struct BagNode*>::iterator it=bagMap.begin(); it!=bagMap.end(); ++it){
            cout << it->second->dataValue << " ";
            if(it->second->dataCount > 1 ){
                cout << "("<<it->second->dataCount<<")";
            }
            cout << endl;
        }
    }

    return 0;
}
