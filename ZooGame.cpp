/*
* Team Members
*   Tyler Hunt - Dice Game
*   Zabrina Antry
*   Tam Pham
*   Prashant Panth
* Advanved C++ Group Project -OCCC Fall 2017
*   Due: XX?/XX?/17
*
*Reference Material
*   C++ Reference - https://www.tutorialspoint.com/cplusplus/passing_parameters_by_references.htm
*   Dice Rules - https://en.wikipedia.org/wiki/Dice_10000#Play
*/
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <string>
#include <exception>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <iterator>
using namespace std;
//Prototypes
void greetingMsg();
int getGameSelection();
void goToGame(int gameSelection);
int getPlayersnumber();
void playersName(int);
void diceGame();
void guessAnimal();
void useYourBrain();
string name[2];



//Tyler
void DiiceGame(int scores[], string players[]);
void diceHeader();
void diceLogos();
void diceRules();
void diceHowTo();
void resetFlags();
void rollDice(int arr[], int freq_arr[], int n);
int scorePointDice(int arr[], int n);
int printPointDice(int arr[], int n);
void mainMenu();
void subMenu();
string getLogo(int dice);


bool is_straight = false;
bool is_triples = false;
bool in_noPointDices(int dice);
int noPointDices[] = { 2, 3, 4, 6 };

//Zabrina
void displayVector(vector<char> vector);
bool isInVector(vector<char> vector, char character);
vector<char> getUsedLetters(string word);
map<char, vector<int> > getCharPosition(string word);



//Prashant's Main
int main(int argc, char** argv)
{
	//Display greeting message
	greetingMsg();
	//Get game selection
	int gameselection = getGameSelection();
	// Get Number of Players
	int numberofPlayers = getPlayersnumber();
	//Get Players Name and store into Array
	playersName(numberofPlayers);
	//Go to user selected game
	goToGame(gameselection);
	return 0;
}

void greetingMsg()
{   //Contract:
	//Program header
	cout << "\n~~~~~~~~~~~~ Welcome to Gamezoo App ~~~~~~~~~~~~" << endl;
	cout << "\n ~~~~~~~~~~~ Game Producers ~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\n Prashant Panth -- Page Designer " << "\n Tyler Hunt-- Master of Dice " << 
				"\n Zabrina Antry -- Queen of Animal Game " << "\n Sean Pham-- Math Guru " << endl;
	cout << "\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}
int getGameSelection()
{   //Contract 
	//  @notes:     Display options, prompt user to make selection 
	//  @params     int, result
	//  @return     int, user selection
	cout << endl;
	cout << "*********** THE GAME STARTS NOW ***********" << endl;
	cout << "\nSelect a game to play: " << endl;
	cout << "\n Enter - " << endl;
	cout << "\t (1) to Play a multi-player game Dice!" << endl;
	cout << "\t (2) to Play Guess the Animal !" << endl;
	cout << "\t (3) to Play the Gussing Game Game!" << endl;
	cout << "\t (4) to exit the program\n " << endl;
	cout << "Which game would you like to play?: ";
	cout << endl;
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

int getPlayersnumber() {
	cout << "Please Enter the number of players you would like to play with: " << endl;
	int n;
	cin >> n;
	return n;

}

void playersName(int n) {

	
		for (int i = 0; i <= n-1; i++) {
			cout << " Please enter name for players " << (i+1) << endl;
			cin >> name[i];
		}

}
void goToGame(int gameNum)
{  //Contract 
   //  @notes:     Display options, prompt user to make selection 
   //  @params     int, result
   //  @return     int, user selection
   //temp code
	cout << endl << endl << endl;
	cout << " Welcome ";
	for (int i = 0; i <= 2; i++) {
		cout << " "  << name[i] ;
	}
	cout << "\nYou have chosen to ";
	if (gameNum == 1) {
		cout << "play Tyler's Dice Game" << endl;
        string winner = diceGame(int * score, string user);
        
		//go to game code here
	}
	else if (gameNum == 2) {
		cout << "play Zabrina's Guess the Animal " << endl;
		guessAnimal();
	}
	else if (gameNum == 3) {
		cout << "play Sean's Math Game" << endl;
		useYourBrain();
	}
	else if (gameNum == 4) {
		cout << "exit the program." << endl;
	}
	else {
		cout << "An error has occured" << endl;
	}
}



//Tyler's Dice Game'
void diceGame()
{
	cout << "Welcome to the Dice game!" << endl;
	srand((unsigned)time(NULL));
	// Examples of the player and score info to be passed in to the dice game
	int bank[2] = { 0,0 };
	int option;
	string players[2];
	for (int i = 0; i < 2; i++) {
		players[i] = name[i];
	}

	while (1) {
		mainMenu();
		while (!(cin >> option)) {
			cout << "Bad input!\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		switch (option) {
		case 1:
			diceHowTo();
			break;
		case 2:
			DiiceGame(bank, players);
			break;
		case 3:
			cout << players[0] << " : " << bank[0] << '\n';
			cout << players[1] << " : " << bank[1] << '\n';
			break;
		case 4:
			cout << "Good Bye!\n";
			getGameSelection();
			exit(0);
		default:
			cout << "Please between 1 to 3.\n";

		}
	}
	//return EXIT_SUCCESS;

	system("pause");
	//exit(0);
}

void DiiceGame(int * scores, string * players)
{
	int p = 1;
	bool on_table[2] = { false };

	while (1) {
		int num_dice = 6;
		int player_score = 0;
		cout << "\n\n_____Total Score of players_____\n";
		cout << players[0] << "\t\t\t\t" << players[1] << '\n';
		cout << scores[0] << "\t\t\t\t" << scores[1] << '\n';
		cout << "\n\nPlayer " << players[p] << " has rolled the dice with sore: " << scores[p] << "\n";

		//Player has to get at least 1000 pts to get on board
		if (scores[p] < 1000)
			cout << "You are off the table. Player must score 1000 points in single turn to get on the table.\n";

		//Begin game loop
		while (true) {
			//Check to ensure that there are still enough dice left to roll
			if (num_dice <= 0) {
				cout << "\nYou rolled all the dices. Next player will play\n";
				break;
			}

			resetFlags();

			cout << "\nYour score in this turn : " << player_score << "\n";
			int rolls[6] = { 0 };
			int roll_freq[6] = { 0 };
			int farkle = 0;

			// Roll dices
			rollDice(rolls, roll_freq, num_dice);

			// Print Dice
			for (int i = 0; i < num_dice; i++) {
				string logo = getLogo(rolls[i]);
				cout << "\t" << rolls[i] << " " << logo << '\n';
			}

			int s = scorePointDice(roll_freq, 6);
			if (is_straight) {
				player_score += s;
				// is_straight = false;
				cout << "\nYou got straight! 1500 points!!";
				cout << "\nYour score in this turn : " << player_score << "\n";
				cout << "Would you like to continue to roll again (y/n)?: \n";
				char ch;
				cin >> ch;
				if (ch == 'n') {
					break;
				}
				continue;
			}
			else if (s == 0) {
				cout << "\nNo point dice appeared. A farkle occured.\n\n";
				// Penalty
				farkle++;
				if (scores[p] > 0 && farkle == 3)
					scores[p] -= 500;
				break;
			}
			else {
				if (is_triples) {
					if (roll_freq[0] == 0 && roll_freq[5] == 0) {
						cout << "\nA triple occured. Next player will play\n";
						cout << "\nYour score in this turn : " << player_score << "\n";
						player_score += s;
						if (scores[p])
							scores[p] += player_score;
						break;
					}
				}

				bool is_selected = false;
				int selectedDice;
				int selectedPointDice[6] = { 0 };
				int pointDiceCount = printPointDice(roll_freq, 6);

				cout << "You have to keep at least one point dice and roll the rest.\n";

				while (pointDiceCount) {
					cout << "Select your dice (press 0 to stop selection): ";

					while (!(cin >> selectedDice)) {
						cout << "Bad value!\n";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Select your dice (press 0 to stop selection): ";
					}

					if (selectedDice == 0 && !is_selected) {
						cout << "You have to keep at least one point dice and roll the rest.\n";
						continue;
					}
					else if (selectedDice == 0 && is_selected) {
						break;
					}
					else if (in_noPointDices(selectedDice) && roll_freq[selectedDice - 1] >= 3) {
						selectedPointDice[selectedDice - 1] = roll_freq[selectedDice - 1];
						num_dice -= roll_freq[selectedDice - 1];
						pointDiceCount -= roll_freq[selectedDice - 1] - 1;
					}
					else {
						if (roll_freq[selectedDice - 1] == 0 || in_noPointDices(selectedDice)) {
							cout << "Select only among point dices appeared on the screen\n";
							continue;
						}
						selectedPointDice[selectedDice - 1] += 1;
						num_dice -= 1;
					}
					pointDiceCount--;
					is_selected = true;
				}
				player_score += scorePointDice(selectedPointDice, 6);
				//resetFlags();

				char ch;
				subMenu();
				while (!(cin >> ch)) {
					cout << "Bad input!\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}

				if (ch == 'q') {
					scores[0] = 0;
					scores[1] = 0;
					return;
				}
				else if (ch == 'n') {
					//if(scores[p])
					//scores[p] += player_score;
					break;
				}
			} // end else

		} // end inner while

		if (player_score >= 1000 && !on_table[p]) {
			cout << "Your score is " << player_score << ". You are now on the table.\n";
			scores[p] += player_score;
			// player_score = 0;
			on_table[p] = true;

		}
		else {
			if (scores[p])
				scores[p] += player_score;
			//player_score = 0;
			cout << "This turn score of player " << players[p] << " is " << player_score;
		}

		// Change player
		if (p == 0) {
			p = 1;
		}
		else {
			p = 0;
		}

        if (scores[0] >= 10000 || scores[1] >= 10000)
			break;
	} // end outer while
}

int scorePointDice(int *arr, int n) {
	int hundred = 100;
	int count1 = 0;
	int count2 = 0;
	int ones = 1;
	int score = 0;

	for (int i = 0; i < n; i++) {

		if (arr[i] == 2) { // Three pairs
			count2++;
			if (i == 0) {
				score += 2 * hundred;
			}
			if (i == 4) {
				score += hundred;
			}
		}
		if (arr[i] == 1) { // Straight
			count1++;
			if (i == 0) {
				score += hundred;
			}
			if (i == 4) {
				score += hundred / 2;
			}
		}

		if (arr[i] == 3) { // 3 of a kind
			if (i == 0) {
				ones = 10;
			}
			score += (i + 1)*hundred*ones;
			ones = 1;
			// is_3OfAKind = true;
		}
		else if (arr[i] == 4) { // 4 of a kind
			if (i == 0) {
				ones = 10;
			}
			score += 2 * (i + 1)*hundred*ones;
			ones = 1;
			// is_4OfAKind = true;
		}
		else if (arr[i] == 5) { // 5 of a kind
			if (i == 0) {
				ones = 10;
			}
			score += 4 * (i + 1)*hundred*ones;
			ones = 1;
			// is_5OfAKind = true;
		}
		else if (arr[i] == 6) { // 6 of a kind
			if (i == 0) {
				ones = 10;
			}
			score += 8 * (i + 1)*hundred*ones;
			ones = 1;
			//            is_6OfAKind = true;
		}
	}

	if (count1 == 6) {
		score = 1500;
		is_straight = true;
	}
	else if (count2 == 3) {
		score = 500;
		is_triples = true;
	}
	return score;
}

void resetFlags() {
	is_straight = false;
	is_triples = false;
}

int printPointDice(int roll_freq[], int n) {
	int numPointDice = 0;
	cout << "Your point dice are: ";
	for (int i = 0; i < n; i++) {
		if (roll_freq[i] == 1) {
			if (i == 0 || i == 4) {
				cout << i + 1 << ' ';
				numPointDice += roll_freq[i];
			}
		}
		else if (roll_freq[i] == 2) {
			if (i == 0 || i == 4) {
				cout << i + 1 << ' ' << i + 1 << ' ';
				numPointDice += roll_freq[i];
			}
		}
		else if (roll_freq[i] == 3) {
			cout << i + 1 << ' ' << i + 1 << ' ' << i + 1 << ' ';
			numPointDice += roll_freq[i];
		}
		else if (roll_freq[i] == 4) {
			cout << i + 1 << ' ' << i + 1 << ' ' << i + 1 << ' ' << i + 1 << ' ';
			numPointDice += roll_freq[i];
		}
		else if (roll_freq[i] == 5) {
			cout << i + 1 << ' ' << i + 1 << ' ' << i + 1 << ' ' << i + 1 << ' ' << i + 1 << ' ';
			numPointDice += roll_freq[i];
		}
		else if (roll_freq[i] == 6) {
			cout << i + 1 << ' ' << i + 1 << ' ' << i + 1 << ' ' << i + 1 << ' ' << i + 1 << ' ' << i + 1 << ' ';
			numPointDice += roll_freq[i];
		}
	}
	cout << "\n\n";
	return numPointDice;
}

void rollDice(int rolls[], int roll_freq[], int n) {
	for (int i = 0; i < n; i++) {
		rolls[i] = rand() % 6 + 1;
		// Count how many of each of 1-6 came in each roll
		roll_freq[rolls[i] - 1]++;
	}
}

bool in_noPointDices(int dice) {
	for (int i = 0; i< 4; i++) {
		if (dice == noPointDices[i])
			return true;
	}
	return false;
}

void diceHeader()
{
	cout << "\n";
	diceLogos();
	cout << "  Welcome to the Dice game  ";
	diceLogos();
	cout << "\n\n";
}

void diceLogos()
{
	//Unicode Dice logos
	const char * s = "\u2680";
	const char * s1 = "\u2681";
	const char * s2 = "\u2682";
	const char * s3 = "\u2683";
	const char * s4 = "\u2684";
	const char * s5 = "\u2685";

	cout << s << " ";
	cout << s1 << " ";
	cout << s2 << " ";
	cout << s3 << " ";
	cout << s4 << " ";
	cout << s5 << " ";
}

string getLogo(int dice) {
	if (dice == 1) {
		return "\u2680";
	}
	else if (dice == 2) {
		return "\u2681";
	}
	else if (dice == 3) {
		return "\u2682";
	}
	else if (dice == 4) {
		return "\u2683";
	}
	else if (dice == 5) {
		return "\u2684";
	}
	else if (dice == 6) {
		return "\u2685";
	}
}

void diceHowTo()
{
	//Dice Rules
	string howToPlay = "\"HOW TO PLAY GUIDE\":\n"
		"\tFarkle is played by two or more players, with each player in succession having a turn at \n"
		"\tthrowing he dice. Each player's turn results in a score, and the scores for each player accumulate to \n"
		"\tsome winning otal (usually 10,000).\n"
		"\n\n"
		"\t\t1) At the beginning of each turn, the player throws all the dice at once.\n"
		"\t\t2) After each throw, one or more scoring dice must be set aside (see sections on scoring below).\n"
		"\t\t3) In order to get \"on the table,\" a player must score at least 1000 points in a single turn (but not\n"
		"\t\t   necessarily in one roll). Once a player is \"on the table,\" they are on for the duration of the game.\n"
		"\t\t4) The player may then either end their turn and bank the score accumulated so far, or continue to throw\n"
		"\t\t   the remaining dice.\n"
		"\t\t5) If the player has scored all six dice, they have \"hot dice\" and may continue their turn with a new\n"
		"\t\tthrow of all six dice, adding to the score they have already accumulated. There is no limit to the\n"
		"\t\tnumber of \"hot dice\" a player may roll in one turn.\n"
		"\t\t6) If none of the dice score in any given throw, the player has \"farkled\" and all points for that turn\n"
		"\t\t   are lost.\n"
		"\t\t7) At the end of the player's turn, the dice are handed to the next player in succession (usually in\n"
		"\t\t   clockwise rotation), and they have their turn.\n"
		"\t\tOnce a player has achieved a winning point total, each other player has one last turn to score enough\n"
		"\t\tpoints to surpass that high-score.\n";

	string scoring = "SCORING RULES:\n"
		"These are the base methods of scoring:\n"
		"\n"
		"\t\t1) Single fives are worth 50 points\n"
		"\t\t2) Single ones are worth 100 points\n"
		"\t\t3) Three of a kind are worth 100 points times the number rolled, except for three ones which are worth\n"
		"\t\t   1000 points\n"
		"\t\t4) If four, five, or six of a kind are rolled, each additional die is worth double the three of a kind\n"
		"\t\t   score\n"
		"\t\t5) This makes the highest possible score in a single roll 8000 for six ones (1000 for three ones, doubled\n"
		"\t\t   3 times. (the fourth one doubles the 1000 to 2000, the fifth one doubles the 2000 to 4000, and the\n"
		"\t\t   sixth one doubles the 4000 to 8000).\n"
		"\t\t6) A straight from 1 to 6 is worth 1500 points. If a player fails to roll a straight they may make one\n"
		"\t\t   attempt to complete the straight. If the desired number(s) does not turn up on the next roll that\n"
		"\t\t   round is a \"crap out\" even if there are scoring dice on the table i.e. 1's or 5's.\n"
		"\t\t7) Three pairs is worth 500 points. For instance 2+2, 4+4, 5+5. This rule does not count if you roll a\n"
		"\t\t   quadruple and a pair 2+2, 2+2, 6+6.\n"
		"\t\t8) If a player fails to roll a three of a kind they may make one attempt to complete the three of a kind.\n"
		"\t\t9) If the desired number(s) does not turn up on the next roll that round is a \"crap out\" even if\n"
		"\t\t   there are scoring dice on the table i.e. 1's or 5's.\n"
		"\t\t10) Dice are scored at the time they are rolled, so three or more of a kind must be rolled simultaneously,\n"
		"\t\t   and dice from later rolls do not \"stack\" for the higher score.\n"
		"\n"
		"\t\t11) Players have the options to call what they roll or call chance. if a player calls a roll and is\n"
		"\t\t   successful that player will receive an addition 50 points to add to that score. If the player\n"
		"\t\t   \"craps-out\" that he loses the 50 points.\n"
		"\n"
		"\"Example: Player 1 rolls all six dice, and chooses to score three fours for 400 points. She rolls the\n"
		"remaining three dice for a 2, 4, 5; the additional 4 does not multiply the previous three of a kind,\n"
		"and she can only score 50 points for the lone 5. If she rolls two more 5's with the remaining dice,\n"
		"they will only score 50 points each, and do not form a three of a kind with the other 5.\"\n";
	cout << howToPlay << "\n\n";
	cout << scoring << "\n\n";
}

void mainMenu() {
	diceHeader();
	cout << "Please select one of below options:" << endl;
	cout << "\tOption (1) How to\n";
	cout << "\tOption (2) Start the game\n";
	cout << "\tOption (3) Player scores\n";
	cout << "\tOption (4) Quit\n";
	cout << "Enter you option: ";
}
void subMenu() {
	cout << "\n\n";
	cout << "Return to main menu (q): \n";
	cout << "Would you like to continue to roll again (y/n)?: ";

}

//Sean's Brain Game'
void useYourBrain() {
	cout << "Welcome to the Math Game!" << endl;

}

int getOperator(int ranNum, int ranNum1, int& answer) {

	char operator1;
	int Ope = rand() % 4 + 1;

	if (Ope == 1) {
		operator1 = '+';
	}
	else if (Ope == 2) {
		operator1 = '-';
	}
	else if (Ope == 3) {
		operator1 = '*';
	}
	else if (Ope == 4) {
		operator1 = '/';
	}
	cout << "The equation for you is : " << ranNum << " " << operator1 << " " << ranNum1 << endl;
	cout << "Enter your answer: " << endl;
	cin >> answer;

	return Ope;
}


void calculate(int  ranNum, int  ranNum1, int answer, int v) {
	int rightAnswer;
	int score = 0;
	int wrongguess = 0;
	int rightguess = 0;

	if (v == 1) {
		rightAnswer = ranNum + ranNum1;
	}
	else if (v == 2) {
		rightAnswer = ranNum - ranNum1;
	}
	else if (v == 3) {
		rightAnswer = ranNum * ranNum1;
	}
	else if (v == 4) {
		rightAnswer = ranNum / ranNum1;
	}

	//while (answer == rightAnswer) {

	if (answer != rightAnswer) {
		cout << " Wrong answer " << endl;
		wrongguess++;
		score -= 10;
		cout << "Your score is : " << score << endl;
	}
	else {
		cout << " Congratulation !!!" << endl;
		cout << "You have the right answer" << endl;
		rightguess++;
		score += 10;
		cout << "Your score is : " << score << endl;
	}
}


//Zabrina's Animal Game'

void displayVector(vector<char> vector) {
	for (auto it = vector.begin(); it != vector.end(); ++it) {
		cout << *it;
		if (it != vector.end() - 1)
			cout << " , ";
	}
	cout << endl;
}

bool isInVector(vector<char> vector, char character) {
	auto found = std::find(vector.begin(), vector.end(), character);
	return found != vector.end();
}

vector<char> getUsedLetters(string word) {
	vector<char> letters;
	for (char character : word) {
		if (!isInVector(letters, character)) {
			letters.push_back(character);
		}
	}
	return letters;
}

map<char, vector<int> > getCharPosition(string word) {
	vector<char> wordVector(word.begin(), word.end());
	vector<char> currentLetter = getUsedLetters(word);
	map<char, vector<int> > charPositions;
	int position;
	vector<int> positions;

	for (char character : currentLetter) {
		position = 0;
		for (char letter : wordVector) {
			if (letter == character) {
				positions.push_back(position);
			}
			position++;
		}
		charPositions.insert(std::pair<char, vector<int> >(character, positions));
		positions.clear();
	}
	return charPositions;
}
void guessAnimal(int * argc[], char * argv[]) {
	cout << "Welcome to the guess the animal game!" << endl;

	int scorePlayerOne = 0;
	int scorePlayerTwo = 0;

	cout << "Welcome to Guess the Animal!" << endl;
	cout << "Player 1, please enter your name: " << endl;
	string playerOne;
	cin >> playerOne;

	cout << "Player 2, please enter your name: " << endl;
	string playerTwo;
	cin >> playerTwo;
	cout << playerOne << " and " << playerTwo << ", you have 10 chances a piece to guess the animal!" << endl << endl;

	vector<string> Animals;

	ifstream animalFile("Animal.txt");
	copy(istream_iterator<string>(animalFile),
		istream_iterator<string>(),
		back_inserter(Animals));

	srand(time(0));
	int randomIndex = rand() % Animals.size();

	const string ANSWER = argv[1] ? argv[1] : Animals[randomIndex];
	vector<char> wordVector(ANSWER.begin(), ANSWER.end());
	vector<char> guessStatus(ANSWER.size(), '*');
	vector<char> lettersUsed;
	map<char, vector<int> > letterPositions = getCharPosition(ANSWER);
	char currentGuess;
	int chances = 20;

	cout << "Lets begin!" << endl;
	cout << "Chances: " << chances << endl << endl;
	displayVector(guessStatus);
	while (true) {
		if (chances == 0) {
			cout << "Oh no, you used all your chances.  Game Over!" << endl;
			cout << "The animal word was: " << ANSWER << endl;
			break;
		}

		cout << "\n" << playerOne << " guess a  letter: ";
		std::cin >> currentGuess;
		if (!isInVector(lettersUsed, currentGuess)) {
			if (isInVector(wordVector, currentGuess)) {
				for (auto it = letterPositions.begin();
					it != letterPositions.end();
					++it) {
					if (currentGuess == it->first) {
						for (int position : it->second) {
							guessStatus.at(position) = currentGuess;
							scorePlayerOne += 5000;
							if (wordVector == guessStatus) {
								cout << "Congratulations! You guessed the animal!!!" << endl;
								cout << "Final Scores: " << endl;
								cout << "Player One: " << scorePlayerOne << endl;
								cout << "Player Two: " << scorePlayerTwo << endl;
								//return 0;

							}
						}
					}
				}
				displayVector(guessStatus);

			}
			else {
				cout << "\nThe letter " << currentGuess << " is not in the animal word. " << endl;
				chances--;
				cout << "Chances remaining: " << chances << "\n\n";
			}
		}
		else {
			cout << "You already used that letter, please choose a different one. " << endl;
			lettersUsed.push_back(currentGuess);
		}

		cout << "\n" << playerTwo << " guess a  letter: ";
		std::cin >> currentGuess;
		if (!isInVector(lettersUsed, currentGuess)) {
			if (isInVector(wordVector, currentGuess)) {
				for (auto it = letterPositions.begin();
					it != letterPositions.end();
					++it) {
					if (currentGuess == it->first) {
						for (int position : it->second) {
							guessStatus.at(position) = currentGuess;
							scorePlayerTwo += 5000;
							if (wordVector == guessStatus) {
								cout << "\nCongratulations! You guessed the animal!!!" << endl;
								cout << "Final Scores: " << endl;
								cout << "Player One: " << scorePlayerOne << endl;
								cout << "Player Two: " << scorePlayerTwo << endl;
								//return 0;
							}
						}
					}
				}
				displayVector(guessStatus);
			}
			else {
				cout << "\nThe letter " << currentGuess << " is not in the animal word. " << endl;
				chances--;
				cout << "Chances remaining: " << chances << endl << endl;
			}
		}
		else {
			cout << "You already used that letter, please choose a different letter next time. " << endl;
			lettersUsed.push_back(currentGuess);
		}

	}
	system("pause");

}