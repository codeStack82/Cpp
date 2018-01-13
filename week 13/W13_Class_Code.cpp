/*
* Tyler Hunt
* C++
* OCCC Fall 2017
* 
*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <exception>
#include <vector>

using namespace std;

class myException : public exception {
private:
    string s;
public:
    virtual const char * what() const throw(){
        return s.c_str();
    }

    myException(): exception() {
        s = "Default Message";
    }

    myException(const string & msg): exception( msg.c_str()){
        s = msg;
    }
};

//main
int main(int argc, char** argv)
{

    bool exception_happened  = false;
    int n;
    cout << "Phase 1" << endl;
    while(true){
        try{
            cout << "Enter and Integer. 0 to exit, -1 to exception: ";
                cin >> n;
                if(n ==0)break;
                if(n < 0){
                    logic_error le("Value less than zero");
                    throw le;
                }else {
                    cout << "You gave me :" << n << endl;
                }
        }catch(const logic_error & le){
            cout << "Got an exception!" << endl;
            cout << le.what() << endl;
        }
    }
    int m;
    cout << "Phase 2" << endl;
    while(true){
        try{
            cout << "Enter and Integer. 0 to exit, -1 to exception: ";
                cin >> m;
                if(m == 0)break;
                if(m < 0){
                    throw m;
                }else {
                    cout << "You gave me :" << m << endl;
                }
        }catch(int e){
            cout << "Got an exception! " << e << endl;
        }
    }

    int p;
    cout << "Phase 3" << endl;
    while(true){
        try{
            cout << "Enter and Integer. 0 to exit, -1 to exception: ";
                cin >> p;
                if(p == 0)break;
                if(p < 0){
                    throw &p;
                }else {
                    cout << "You gave me :" << p << endl;
                }
        }catch(int * e){
            cout << "Got an exception! " << endl;
            *e *= -1;
            exception_happened = true;

            if(exception_happened){
                cout << "You gave me"  << p << endl;
            
            }
                
        }
    }

    int x;
    cout << "Phase 4" << endl;
    while(true){
        try{
            cout << "Enter and Integer. 0 to exit, -1 to exception: ";
                cin >> x;
                if(x == 0)break;
                if(x < 0){
                    throw myException("Oh no ");
                }else {
                    cout << "You gave me :" << p << endl;
                }
        }catch(const myException & me){
            //throw "Got an exception! " << me << endl;   
        }

        if(exception_happened){
            cout << "You gave me"  << x << endl;
        
        }
    }




	return 0;
}
