#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <exception>
#include <vector>
#include <unistd.h>
using namespace std;

//Main Prototype section
void greetingMsg();
int getGameSelection();
void goToGame(int gameSelection);

//Tyler Prototype Section
void diceLogos();
void DiceGame();
void diceHeader();

//test Class - not working
class Player{
    public:
        Player(int pId, string pName);
        // void setpId(int id);
        // void setpName(string pName);
    private:
        int pId;
        string pName;
        int score;
        bool isWinner;
};
