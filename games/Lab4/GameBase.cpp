// GameBase.cpp
// Steve Li (zhaoqi.li@wustl.edu), Xiaowen Ma (maxiaowen@wustl.edu), Claire Zhang (zhangbin@wustl.edu)
// This is the source file for GameBase. It contains the function definitions of class GameBase.
// The functions defined here include a GameBase constructor, prompt, check, play, and usageMessage.

#include "GameBase.h"
#include "TicTacToeGame.h"
#include "Gomoku.h"

GameBase::GameBase(unsigned int in_horizontalDim, unsigned int in_verticalDim, string in_display, vector<string> in_gameBoard, vector<pair<unsigned long, unsigned long>> in_moveX, vector<pair<unsigned long, unsigned long>> in_moveO, string in_gameName, unsigned int in_maxLength, int in_winNum)
	:horizontalDim(in_horizontalDim), verticalDim(in_verticalDim), display(in_display), gameBoard(in_gameBoard), moveX(in_moveX), moveO(in_moveO), gameName(in_gameName), maxLength(in_maxLength), winNum(in_winNum)
{}

int GameBase::prompt(unsigned & xCoordinate, unsigned & yCoordinate)
{
	string input;
	cout << "Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers). ";

	cout << endl;
	getline(cin, input);		// get the user's input
	cout << endl;
	int commaCount = 0;

	if (input == "quit") {	// if the user enters "quit", return the appropriate enum state
		return state::endGameByUser;
	}

	int spaceCount = 0;				// check number of spaces
	for (auto begin = input.begin(); begin != input.end(); ++begin) {
		if (*begin == 32) {			
			spaceCount++;
			if (spaceCount != 0) {
				cout << "Invalid input: please enter two valid coordinates separated by a comma." << endl;
				return state::endGameInvalidInput;
			}
		}
		if (*begin == ',') {	// change the comma to a space
			*begin = ' ';
			commaCount++;
		}
	}

	if (commaCount != 1) {	// if there is no comma, return the appropriate enum state
		cout << "Invalid input: please enter two valid coordinates separated by a comma." << endl;
		return state::endGameInvalidInput;
	}

	istringstream iss(input);	// wrap the input in istringstream
	if (gameName == "TicTacToe") {
		if (iss >> xCoordinate && xCoordinate >= 1 && xCoordinate <= horizontalDim-2) {		// check the validity of the input
			if (iss >> yCoordinate && yCoordinate >= 1 && yCoordinate <= horizontalDim-2) {
				return state::success;
			}
			else {
				cout << "Invalid input: please enter two valid coordinates separated by a comma." << endl;
				return state::endGameInvalidInput;
			}
		}
		else {
			cout << "Invalid input: please enter two valid coordinates separated by a comma." << endl;
			return state::endGameInvalidInput;
		}
	}
	else if (gameName == "Gomoku") {
		if (iss >> xCoordinate && xCoordinate >= 1 && xCoordinate <= horizontalDim) {		// check the validity of the input
			if (iss >> yCoordinate && yCoordinate >= 1 && yCoordinate <= horizontalDim) {
				return state::success;
			}
			else {
				cout << "Invalid input: please enter two valid coordinates separated by a comma." << endl;
				return state::endGameInvalidInput;
			}
		}
		else {
			cout << "Invalid input: please enter two valid coordinates separated by a comma." << endl;
			return state::endGameInvalidInput;
		}
	}
	else {
		cout << "Invalid input: please enter two valid coordinates separated by a comma." << endl;
		return state::endGameInvalidInput;
	}
}


GameBase* GameBase::check(int a, char* b[]) {
	if (a == commandCt::two) {
		string thisName = b[arrInd::inputFileName];
		if (thisName == "TicTacToe") {
			// initiate game
			try {
				vector <string> vec(25, "");
				vector <pair<unsigned long, unsigned long>> moveX(5);	// create two vectors of length equal to the dimension
				vector <pair<unsigned long, unsigned long>> moveO(5);
				GameBase* currentGame = new TicTacToeGame(5, 5, "X", vec, moveX, moveO, "TicTacToe", 1, 3);	// dynamically allocate a new TicTacToeGame 
																								// initiated with predefined variables
				return currentGame;
			}
			catch (std::bad_alloc& ba) {
				std::cerr << "bad_alloc caught: " << ba.what() << endl;
				return nullptr;
			}
		}
		else if (thisName == "Gomoku") {

			try {
				vector <string> vec(20 * 20 + 1, "");	
				vector <pair<unsigned long, unsigned long>> moveX(0);	// Bmove
				vector <pair<unsigned long, unsigned long>> moveO(0); // Wmove
				GameBase* currentGame = new Gomoku(19, 19, "B", vec, moveX, moveO, "Gomoku", 2, 5);
				return currentGame;
			}
			catch (std::bad_alloc& ba) {
				std::cerr << "bad_alloc caught: " << ba.what() << endl;
				return nullptr;
			}
		}
		else {
			usageMessage(b[arrInd::prgmName], "<Game Name(TicTacToe or Gomoku)>", "<Board Dimension(optional, an integer greater than 4)>", "<Number of Connecting Pieces to Win(optional, an integer greater than 4 and less than or equal to the board dimension)>");
			GameBase* currentGame = nullptr;
			return currentGame;
		} 

	}
	else if (a == commandCt::three) {
		string thisName = b[arrInd::inputFileName];
		string boardDim_str = b[arrInd::boardDim];
		int count = 0;
		bool isNum = true;
		for (auto begin = boardDim_str.cbegin(); begin != boardDim_str.cend(); ++begin) {	// iterate through the string representing the board dimension
			++count;
			if (!isdigit(*begin)) {
				isNum = false;
			}
		}
		if (!isNum) {	// if not a number, return nullptr
			usageMessage(b[arrInd::prgmName], "<Game Name(TicTacToe or Gomoku)>", "<Board Dimension(optional, an integer greater than 4)>", "<Number of Connecting Pieces to Win(optional, an integer greater than 4 and less than or equal to the board dimension)>");
			return nullptr;
		}
			
		istringstream iss(boardDim_str);
		unsigned int boardDim = 0;
		if (!(iss >> boardDim)) {
			usageMessage(b[arrInd::prgmName], "<Game Name(TicTacToe or Gomoku)>", "<Board Dimension(optional, an integer greater than 4)>", "<Number of Connecting Pieces to Win(optional, an integer greater than 4 and less than or equal to the board dimension)>");
			return nullptr;
		}
		if (boardDim <= 0) {
			usageMessage(b[arrInd::prgmName], "<Game Name(TicTacToe or Gomoku)>", "<Board Dimension(optional, an integer greater than 4)>", "<Number of Connecting Pieces to Win(optional, an integer greater than 4 and less than or equal to the board dimension)>");
			return nullptr;
		}


		if (thisName != "Gomoku") {
			usageMessage(b[arrInd::prgmName], "<Game Name(TicTacToe or Gomoku)>", "<Board Dimension(optional, an integer greater than 4)>", "<Number of Connecting Pieces to Win(optional, an integer greater than 4 and less than or equal to the board dimension)>");
			return nullptr;
		}
		else {
			if (boardDim < 5) {
				usageMessage(b[arrInd::prgmName], "<Game Name(TicTacToe or Gomoku)>", "<Board Dimension(optional, an integer greater than 4)>", "<Number of Connecting Pieces to Win(optional, an integer greater than 4 and less than or equal to the board dimension)>");
				return nullptr;
			}
			else {
				try {
					vector <string> vec(((size_t)boardDim + 1) * ((size_t)boardDim + 1) + 1, "");
					vector <pair<unsigned long, unsigned long>> moveX(0);	// Bmove
					vector <pair<unsigned  long, unsigned long>> moveO(0); // Wmove
					GameBase* currentGame = new Gomoku(boardDim, boardDim, "B", vec, moveX, moveO, "Gomoku", count, 5);
					return currentGame;
				}
				catch (std::bad_alloc& ba) {
					std::cerr << "bad_alloc caught: " << ba.what() << endl;
					return nullptr;
				}
			}
		}
	}
	else if (a == commandCt::four) {
		string thisName = b[arrInd::inputFileName];
		string boardDim_str = b[arrInd::boardDim];
		string winNum_str = b[arrInd::winningCt];
		int count = 0;
		bool isNum = true;
		for (auto begin = boardDim_str.cbegin(); begin != boardDim_str.cend(); ++begin) {
			++count;
			if (!isdigit(*begin)) {
				isNum = false;
			}
		}
		if (!isNum) {	// check if boardDim is a number
			usageMessage(b[arrInd::prgmName], "<Game Name(TicTacToe or Gomoku)>", "<Board Dimension(optional, an integer greater than 4)>", "<Number of Connecting Pieces to Win(optional, an integer greater than 4 and less than or equal to the board dimension)>");
			return nullptr;
		}
		
		istringstream iss(boardDim_str);
		unsigned int boardDim = 0;
		if (!(iss >> boardDim)) {
			usageMessage(b[arrInd::prgmName], "<Game Name(TicTacToe or Gomoku)>", "<Board Dimension(optional, an integer greater than 4)>", "<Number of Connecting Pieces to Win(optional, an integer greater than 4 and less than or equal to the board dimension)>");
			return nullptr;
		}
		if (boardDim <= 0) {
			usageMessage(b[arrInd::prgmName], "<Game Name(TicTacToe or Gomoku)>", "<Board Dimension(optional, an integer greater than 4)>", "<Number of Connecting Pieces to Win(optional, an integer greater than 4 and less than or equal to the board dimension)>");
			return nullptr;
		}

		if (thisName != "Gomoku") {
			usageMessage(b[arrInd::prgmName], "<Game Name(TicTacToe or Gomoku)>", "<Board Dimension(optional, an integer greater than 4)>", "<Number of Connecting Pieces to Win(optional, an integer greater than 4 and less than or equal to the board dimension)>");
			return nullptr;
		}
		else {
			if (boardDim < 5) {
				usageMessage(b[arrInd::prgmName], "<Game Name(TicTacToe or Gomoku)>", "<Board Dimension(optional, an integer greater than 4)>", "<Number of Connecting Pieces to Win(optional, an integer greater than 4 and less than or equal to the board dimension)>");
				return nullptr;
			}
			else {
				for (auto begin = winNum_str.cbegin(); begin != winNum_str.cend(); ++begin) {
					++count;
					if (!isdigit(*begin)) {
						isNum = false;
					}
				}
				if (!isNum) {
					usageMessage(b[arrInd::prgmName], "<Game Name(TicTacToe or Gomoku)>", "<Board Dimension(optional, an integer greater than 4)>", "<Number of Connecting Pieces to Win(optional, an integer greater than 4 and less than or equal to the board dimension)>");
					return nullptr;
				}
				istringstream iss(winNum_str);
				int winNum = 0;
				if (!(iss >> winNum)) {
					usageMessage(b[arrInd::prgmName], "<Game Name(TicTacToe or Gomoku)>", "<Board Dimension(optional, an integer greater than 4)>", "<Number of Connecting Pieces to Win(optional, an integer greater than 4 and less than or equal to the board dimension)>");
					return nullptr;
				}
				if (winNum < 5 || winNum > boardDim) {
					usageMessage(b[arrInd::prgmName], "<Game Name(TicTacToe or Gomoku)>", "<Board Dimension(optional, an integer greater than 4)>", "<Number of Connecting Pieces to Win(optional, an integer greater than 4 and less than or equal to the board dimension)>");
					return nullptr;
				}
				else {
					try {
						vector <string> vec(((size_t)boardDim + 1) * ((size_t)boardDim + 1) + 1, "");
						vector <pair<unsigned long, unsigned long>> moveX(0);	// Bmove
						vector <pair<unsigned long, unsigned long>> moveO(0); // Wmove
						GameBase* currentGame = new Gomoku(boardDim, boardDim, "B", vec, moveX, moveO, "Gomoku", count, winNum);
						return currentGame;
					}
					catch (std::bad_alloc& ba) {
						std::cerr << "bad_alloc caught: " << ba.what() << endl;
						return nullptr;
					}
				}
			}
		}
	}
	else {
		usageMessage(b[arrInd::prgmName], "<Game Name(TicTacToe or Gomoku)>", "<Board Dimension(optional, an integer greater than 4)>", "<Number of Connecting Pieces to Win(optional, an integer greater than 4 and less than or equal to the board dimension)>");
		GameBase* currentGame = nullptr; // wrong number of arguments
		return currentGame;
	}
}

int GameBase::play() {
	int turnsCount = 0;	// records the total number of turns played
	int turnTrack = 0;
	bool doneTrack = false;
	bool drawTrack = false;
	while (turnTrack == state::success && !doneTrack && !drawTrack)	// the game doesn't end until turn() returns 1, or done() returns false,
																	// or draw returns false
	{	
		turnTrack = turn();
		doneTrack = done();
		drawTrack = draw();
		turnsCount++;
	}
	if (turnTrack != state::success) {	// catch the case where the user quits the game
		turnsCount--;
		cout << turnsCount << " turns were played. The user quits.";
		return state::endGameByUser;
	}
	
	if (doneTrack) {	// catch the case where one of the player wins the game
		return state::success;
	} 
	if (drawTrack) {	// catches the case where no winning moves remain
		cout << turnsCount << " turns were played. No winning moves remain.";
		return state::endGameNoWinningMovesRemain;
	}
	return state::success;
}

state usageMessage(const string& prgmName, const string& remInfo1, const string& remInfo2, const string& remInfo3) {
	cout << "Usage: Please have at least one input but not more than three inputs" << endl;
	cout << "1 input usage: " << prgmName << " " << remInfo1 << endl;
	cout << "2 inputs usage: " << prgmName << " " << remInfo1 << " " << remInfo2 << endl;
	cout << "3 inputs usage: " << prgmName << " " << remInfo1 << " " << remInfo2 << " " << remInfo3 << endl;
	return state::usageCalled;
}
