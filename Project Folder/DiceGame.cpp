/*
* Team Members
*   Tyler Hunt - Dice Game
*   Zabrina Antry
*   Tam Pham
*   Prashant Panth

* Advanved C++ Group Project -OCCC Fall 2017
*   Due: 12/09/17

*Reference Material
*   C++ Reference - https://www.tutorialspoint.com/cplusplus/passing_parameters_by_references.htm
*   Dice Rules - https://en.wikipedia.org/wiki/Dice_10000#Play
*/

#include "MainMenu.h"

String DiceGame();
int numberOfPlayers();
void diceHeader();
void diceLogos();
void diceRules();
void diceHowTo();

using namespace std;

//Main
int main(int argc, char** argv){

    String winnerInfo = "";
    DiceGame();
   

    return EXIT_SUCCESS;
}

void greetingMsg()
{   //Contract:
        //Program header
	cout << "\n~~~~~~~~~~~~ Welcome to the Dice Game ~~~~~~~~~~~~" << endl;
}

int numberOfPlayers()
{   //Contract 
        //  @notes:     Display options, prompt user to make selection 
        //  @return     int, user selection

    cout << "\nPlease enter the number of players that wish to play: " << endl;

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


//Tyler's Dice Game'
string DiceGame()
{ //Contract 
        //  @notes:     Begin playing Dice Game
        //  @return     void

    diceHeader();
    //Player p1 = new Player(1,"Ty");
        //todo: start game message
            //todo: in <- get number of players
            //todo: create scoreboard 
        //todo: begin game
            //todo: roll dice -> funct
            //todo: get user dice selection <-> funct
            //todo: accumulate score for user -> funct
            //todo: go to next player....
            // create winner board....and snarky messages as game progresses....

}

void diceHeader()
{ //Contract 
        //  @notes:     print Dice Game header
        //  @return     void
    cout << "\n";
    diceLogos();
    cout << "  Welcome to the Dice game  ";
    diceLogos();
    cout << "\n\n";
}

void diceLogos()
{ //Contract 
        //  @notes:     get Dice Unicode symbols
        //  @return     void

    //Unicode Dice logos
    const char * s  = "\u2680";
    const char * s1  = "\u2681";
    const char * s2 = "\u2682";
    const char * s3  = "\u2683";
    const char * s4  = "\u2684";
    const char * s5 = "\u2685";
    
    cout << s << " ";
    cout << s1 << " ";
    cout << s2 << " ";
    cout << s3 << " ";
    cout << s4 << " ";
    cout << s5 << " ";
}

void diceRules()
{ //Contract 
        //  @notes:     print dice rules
        //  @return     void

    //Dice Rules
    string rule_1 =  "Rule 1)  No cheating";
    
    cout << rule_1 << endl;
}

void diceHowTo()
{ //Contract 
        //  @notes:     print dice rules
        //  @return     void

    //Dice Rules
    string howTo_1 =  "Step 1) Roll the Dice";
    
    cout << howTo_1 << endl;
}

  