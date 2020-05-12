// TicTacToeGame.cpp
// Steve Li (zhaoqi.li@wustl.edu), Xiaowen Ma (maxiaowen@wustl.edu), Claire Zhang (zhangbin@wustl.edu)
// This is the sourecefile for TicTacToe game. It contains the function definitions of TicTacToeGame.
// Functions defined here include a TicTacToeGame constructor, print, << operator, done, draw and turn.

#include "TicTacToeGame.h"

TicTacToeGame::TicTacToeGame(unsigned int in_horizontalDim, unsigned int in_verticalDim, string in_display, vector<string> in_gameBoard, vector<pair<unsigned long, unsigned long>> in_moveX, vector<pair<unsigned long, unsigned long>> in_moveO, string in_gameName, unsigned int in_maxLength, int in_winNum)
	:GameBase(in_horizontalDim, in_verticalDim, in_display, in_gameBoard, in_moveX, in_moveO, in_gameName, in_maxLength, 3), horizontalDim(in_horizontalDim), verticalDim(in_verticalDim), display(in_display), gameBoard(in_gameBoard), moveX(in_moveX), moveO(in_moveO), gameName(in_gameName), maxLength(in_maxLength), winNum(3)
{}
// initialize gameBoard to have in_horizontalDim*in_horizontalDim elements with an empty string in each index
	// assume player in_display execute the first move

void TicTacToeGame::print() {
	cout << *this;
}

ostream& operator<<(ostream& out, const TicTacToeGame& game)
{
	unsigned length = game.maxLength + 1;
	for (int y = game.verticalDim - 1; y != -1; --y) {
		out << y;
		for (size_t x = 0; x != game.horizontalDim; ++x) {
			if (game.gameBoard[game.horizontalDim * x + y] == "") { // if the index is empty, print a space
				out << setw(length)<< " ";
			}
			else {	// if the index contains a string, print out the string 
				out << setw(length)<<game.gameBoard[game.horizontalDim * x + y] ;
			}
		}
		out << endl; // change to a new line after each row
	}
	out << " ";
	for (int i = 0; i != game.horizontalDim; ++i) {
		out << setw(length) << i;
	}
	out << endl;
	return out;
}

bool TicTacToeGame::done()
{	// only check the inner 9 squares 
	for (int y = 1; y != verticalDim - 1; ++y) {
		for (size_t x = 1; x != (size_t)horizontalDim - 1; ++x) {
			if (gameBoard[horizontalDim * x + y] != "") {	// only check those pieces that are occupied
				string piece = gameBoard[horizontalDim *x + y];   // represent the current element
				try {	// check horizontal 
					gameBoard.at(horizontalDim * (x - 1) + y);
					gameBoard.at(horizontalDim * (x + 1) + y);
					if (gameBoard[horizontalDim * (x - 1) + y] == piece && gameBoard[horizontalDim * (x + 1) + y] == piece) {
						print();
						if (display == "X") {
							display = "O";
						}
						else if (display == "O") {
							display = "X";
						}
						cout << "Player " << display << " won the game.";
						return true;
					}
				} 
				catch (const std::out_of_range e) {}

				try {	// check vertical
					gameBoard.at(horizontalDim * x + y - 1);
					gameBoard.at(horizontalDim * x + y + 1);
					if (gameBoard[horizontalDim * x + y - 1] == piece && gameBoard[horizontalDim * x + y + 1] == piece) {
						print();
						if (display == "X") {
							display = "O";
						}
						else if (display == "O") {
							display = "X";
						}
						cout << "Player " << display << " won the game.";
						return true;
					}
				}
				catch (const std::out_of_range e) {}

				try {	// check diagonal (upper left to lower right)
					gameBoard.at(horizontalDim * (x - 1) + y + 1);
					gameBoard.at(horizontalDim * (x + 1) + y - 1);
					if (gameBoard[horizontalDim * (x - 1) + y + 1] == piece && gameBoard[horizontalDim * (x + 1) + y - 1] == piece) {
						print();
						if (display == "X") {
							display = "O";
						}
						else if (display == "O") {
							display = "X";
						}
						cout << "Player " << display << " won the game.";
						return true;
					}
				}
				catch (const std::out_of_range e) {}

				try {	// check diagonal (upper right to lower left)
					gameBoard.at(horizontalDim * (x - 1) + y - 1);
					gameBoard.at(horizontalDim * (x + 1) + y + 1);
					if (gameBoard[horizontalDim * (x - 1) + y - 1] == piece && gameBoard[horizontalDim * (x + 1) + y + 1] == piece) {
						print();
						if (display == "X") {
							display = "O";
						}
						else if (display == "O") {
							display = "X";
						}
						cout << "Player " << display << " won the game.";
						return true;
					}
				}
				catch (const std::out_of_range e) {}
			}
		}
	}
	return false;
}

bool TicTacToeGame::draw()
{
	bool isEmpty = false;
	size_t ctX = 0;
	int ctY = 0;
	// loop throught the inner 9 squares to check if there is an empty index (there are still valid moves remaining)
	for (int y = 1; y != verticalDim - 1; y++) {
		for (size_t x = 1; x != (size_t)horizontalDim - 1; x++) {
			if (gameBoard[horizontalDim * x + y] == "") {
				isEmpty = true;
				break;
			}
		}
	}
	if (isEmpty) {
		return false;
	}
	else {
		return true;
	}
}


int TicTacToeGame::turn() {

	print();		
	// switch players in each turn
	if (display == "X") {
		cout << "It is player X's turn." << endl;
	}
	else if (display == "O") {
		cout << "It is player O's turn." << endl;
	}
	unsigned x;
	unsigned y;

	vector<pair<unsigned long, unsigned long>>& moves = (display == "X") ? moveX : moveO;	// a reference to the collection of valid moves
																				// of the current player

	int result = prompt(x, y);

	// check if the point is already occupied
	if (result == state::success && gameBoard[horizontalDim * (size_t)x + y] == "") {		// valid input
		moves.push_back(make_pair(x, y));
	}
	else if (result == state::success) {
		while (gameBoard[horizontalDim * (size_t)x + y] != "") {	// if the point is already occupied, reprompt the user to keep 
																	// entering inputs untill it's valid
			cout << "This point is already occupied." << endl;
			int result = prompt(x, y);
			if (result == state::success && gameBoard[horizontalDim * (size_t)x + y] == "") {
				moves.push_back(make_pair(x, y));
				break;
			}
			if (result == state::endGameByUser) {
				return result;
			}
		}
	}
	else if (result == state::endGameByUser) {	// if the user enters "quit", return the appropriate enum state
		return result;
	}
	else if (result == state::endGameInvalidInput || result == state::endGameExtractionError) {
		while (result == state::endGameInvalidInput || result == state::endGameExtractionError) { // if the user input is invalid or there is an extraction error,
																							// reprompt the user to keep entering inputs untill it's valid
		int result = prompt(x, y);						
		if (result == state::success) {
			moves.push_back(make_pair(x, y));
			break;
		}
		if (result == state::endGameByUser) {
			return result;
		}
		}
	} 
	gameBoard[(size_t)horizontalDim * x + y] = display;


	// print the valid moves made by the current player
	cout << "Player " << display << ": ";
	int ct = 0;
	for (int begin = 0; begin != moves.size(); begin++) {
		if (moves[begin].first != 0 && moves[begin].second != 0) {
			if (ct == 0) {
				cout << moves[begin].first << "," << moves[begin].second;
			}
			else {
				cout << "; " << moves[begin].first << "," << moves[begin].second;
			} 
			ct++;
		}
	}
	cout << endl << endl;

	// change the turn of the player
	if (display == "X") {
		display = "O";
	}
	else if (display == "O") {
		display = "X";
	}
	return state::success;
}



