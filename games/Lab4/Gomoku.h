// Gomoku.h
// Steve Li (zhaoqi.li@wustl.edu)
// This is the header file for Gomoku. It contains the declaration for class Gomoku.

#pragma once
#include "GameBase.h"

class Gomoku :public GameBase {
	friend ostream& operator<<(ostream& o, const Gomoku& g);
private:
	unsigned int horizontalDim;	// horizontal board dimension (in-class initialization)
	unsigned int verticalDim;		// vertical board dimension (in-class initialization)
	string display;	// represent the current player; can have value either "X" or "O"
	vector<string> gameBoard;	// represent the game board
	vector<pair<unsigned long, unsigned long>> moveX;	// used to store valid moves of player X
	vector<pair<unsigned long, unsigned long>> moveO; // used to store valid moves of player O
	unsigned int maxLength;	// longest display string length
	string gameName;	// represent the name of the current game
	int winNum;		// number of connecting pieces to win
	enum stones { Black, White };
	
public:
	Gomoku(unsigned in_horizontalDim, unsigned in_verticalDim, string in_display, vector<string> in_gameBoard, vector<pair<unsigned long, unsigned long>> in_moveX, vector<pair<unsigned long, unsigned long>> in_moveO, string in_gameName, unsigned in_maxLength, int in_winNum);;		// constructor
	virtual bool done() override;
	virtual bool draw() override;
	virtual void print() override;
	virtual int turn() override;
};

ostream& operator<<(ostream& o, const Gomoku& g);