// TicTacToeGame.h
// Steve Li (zhaoqi.li@wustl.edu), Xiaowen Ma (maxiaowen@wustl.edu), Claire Zhang (zhangbin@wustl.edu)
// This is the header file for TicTacToeGame. It contains the declaration of class TicTacToeGame.

#pragma once
#include "GameBase.h"

class TicTacToeGame: public GameBase {
	friend ostream& operator<<(ostream& out, const TicTacToeGame& game);	// friend the operator<< function so that this function could
																// access member variables
private:
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
	TicTacToeGame(unsigned int in_horizontalDim, unsigned int in_verticalDim, string in_display, vector<string> in_gameBoard, vector<pair<unsigned long, unsigned long>> in_moveX, vector<pair<unsigned long, unsigned long>> in_moveO, string gameName, unsigned int in_maxLength, int in_winNum);	// constructor
	virtual bool done() override;
	virtual bool draw() override;
	virtual int turn() override;
	virtual void print() override;
};

ostream& operator<<(ostream &out, const TicTacToeGame& game);
