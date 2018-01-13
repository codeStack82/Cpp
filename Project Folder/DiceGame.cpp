/*
* Team Members
*   Tyler Hunt - Dice Game
*/

#include <string>
#include <iostream>
using namespace std;

void DiceGame(int scores[], string players[]);
void diceHeader();
void diceLogos();
void diceRules();
void diceHowTo();

//Main
int main(int argc, char** argv){ 

    // Examples of the player and score info to be passed in to the dice game
    int scores[2] = {0,0};
    string players[2] = {"Ty","Tom"};

    DiceGame(scores, players);

   
    return EXIT_SUCCESS;
}

void greetingMsg()
{   //Contract:
        //Program header
	cout << "\n~~~~~~~~~~~~ Welcome to the Dice Game ~~~~~~~~~~~~" << endl;
}

//Tyler's Dice Game'
void DiceGame(int * scores, string * players)
{ //Contract 
        //  @notes:     Begin playing Dice Game
        //  @return     scores and players info

    diceHeader();
        //todo: Dice Game 
        // •	Game will be a normal dice game to 10,000.
        //       This will be a 2 player game
        //     o	Each player will roll the dice and be able to select the dice they want to keep 
        //     o	Scores will be added to their overall score
        // •	There will only be 2 players
        //     o	The player info will be passed in from the main entry into the program
        //         ♣	diceGame(Int * scores, string  * player)
        //     o	at the end of the game the players scores will be passed back to the main program where they will be aggregated into a scoreboard
        // •	There will have to be a few options from menu so the players can chose to ask for help, ask for instruction, or exit the game and return to the main menu, if game is exited early (before completion) then no scores will be saved
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

  