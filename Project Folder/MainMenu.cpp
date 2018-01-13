/*
* Team Members
*   Tyler Hunt - Dice Game
*   Zabrina Antry
*   Tam Pham
*   Prashant Panth

* Advanved C++ Group Project -OCCC Fall 2017
*   Due: XX?/XX?/17

*Reference Material
*   C++ Reference - https://www.tutorialspoint.com/cplusplus/passing_parameters_by_references.htm
*   Dice Rules - https://en.wikipedia.org/wiki/Dice_10000#Play
*/

//Add prototypes/classes MainMenu.h
#include "MainMenu.h"

using namespace std;

//Main
int main(int argc, char** argv)
{
    //Display greeting message
    greetingMsg();

    //Get game selection
    int gameselection = getGameSelection();

    //Go to user selected game
    goToGame(gameselection);

    return 0;
}

void greetingMsg()
{   //Contract:
        //Program header
	cout << "\n~~~~~~~~~~~~Group Project - Fall 2017 ~~~~~~~~~~~~" << endl;
}

int getGameSelection()
{   //Contract 
        //  @notes:     Display options, prompt user to make selection 
        //  @return     int, user selection

    cout << "\nSelect a game to play: " << endl;
	cout << "\t-Enter (1) to Play a multi-player Dice Game!" << endl;
	cout << "\t-Enter (2) to Play the Numbers Game!" << endl;
    cout << "\t-Enter (3) to Play the Hang-Man Game!" << endl;
    cout << "\t-Enter (4) to Play the Guessing Game Game!" << endl;
	cout << "\t-Enter (5) to exit the program" << endl;
	cout << "Please, which game would you like to play?: ";

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

void goToGame(int gameNum)
{  //Contract 
        //  @notes:     User Selects whicch game they want
        //  @params     int, game number selection
        //  @return     void

        //temp code
        if(gameNum == 1){
            //Start Dice Game
            DiceGame();
        }else if(gameNum == 2){
            cout << "play Zabrina's Word Game" << endl;
        }else if(gameNum == 3){
            cout << "play Sean's Hang-man Game" << endl;
        }else if(gameNum == 4){
            cout << "play Prashant's Guessing Game" << endl;
        }else if(gameNum == 5){
            cout << "exit the program." << endl;
        }else{
            cout << "An error has occured" << endl;
        }
}

//Tyler's Dice Game'
void DiceGame(int * scores, string players)
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

  