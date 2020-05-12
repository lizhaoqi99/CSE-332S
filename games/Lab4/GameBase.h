// GameBase.h
// Steve Li (zhaoqi.li@wustl.edu), Xiaowen Ma (maxiaowen@wustl.edu), Claire Zhang (zhangbin@wustl.edu)
// This is the header file for GameBase. It contains declaration of class GameBase.
// It also contains the enumeration that is used in the program.

#pragma once
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;

enum arrInd {
	prgmName,	// index 0 in argv[] is the program name
	inputFileName,	// index 1 in argv[] is the input file name
	boardDim,	// the second argument in argv representing the board dimension 
	winningCt	// number of connecting pieces to win
};

enum commandCt {
	two = 2,		// file name, game name
	three = 3,		// file name, game name, dimension
	four = 4		// file name, game name, dimension, number of connecting pieces to win
};

enum state {	// enum state to represent appropriate returning values corresponding to success or different cases of failure
	success,	// 0
	endGameByUser, //1
	endGameInvalidInput, //2
	endGameExtractionError, //3
	endGameNoWinningMovesRemain, //4
	usageCalled, //5
	positionOccupied //6
	
};

class GameBase {

protected:
	unsigned int horizontalDim;	// horizontal board dimension (in-class initialization)
	unsigned int verticalDim;		// vertical board dimension (in-class initialization)
	string display;	// represent the current player; can have value either "X" or "O"
	vector<string> gameBoard;	// represent the game board
	vector<pair<unsigned long, unsigned long>> moveX;	// used to store valid moves of player X
	vector<pair<unsigned long, unsigned long>> moveO; // used to store valid moves of player O
	unsigned int maxLength;	// longest display string length
	string gameName;	// represent the name of the current game
	int winNum;	// number of connecting pieces to win
	
public:
	GameBase(unsigned int in_horizontalDim, unsigned int in_verticalDim, string in_display, vector<string> in_gameBoard, vector<pair<unsigned long, unsigned long>> in_moveX, vector<pair<unsigned long, unsigned long>> in_moveO, string in_gameName, unsigned int in_maxLength, int in_winNum);
	virtual bool done() = 0;	// pure virtual
	virtual bool draw() = 0;
	virtual void print() = 0;
	virtual int turn() = 0;
	int play();
	virtual int prompt(unsigned& xCoordinate, unsigned& yCoordinate);
	static GameBase* check(int a, char* b[]);
};
state usageMessage(const string& prgmName, const string& remInfo1, const string& remInfo2, const string& remInfo3);