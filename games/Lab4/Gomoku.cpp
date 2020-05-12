// Gomoku.cpp
// Steve Li (zhaoqi.li@wustl.edu)
// This is the source file for Gomoku. It contains the function definitions of class Gomoku.
// The functions defined here include a Gomoku constructor, print, << operator, done, draw and turn.

#include "Gomoku.h"


Gomoku::Gomoku(unsigned in_horizontalDim, unsigned in_verticalDim, string in_display, vector<string> in_gameBoard, vector<pair<unsigned long, unsigned long>> in_moveX, vector<pair<unsigned long, unsigned long>> in_moveO, string in_gameName, unsigned in_maxLength, int in_winNum)
	:GameBase(in_horizontalDim, in_verticalDim, in_display, in_gameBoard, in_moveX, in_moveO, in_gameName, in_maxLength, in_winNum), horizontalDim(in_horizontalDim), verticalDim(in_verticalDim), display(in_display), gameBoard(in_gameBoard), moveX(in_moveX), moveO(in_moveO), gameName(in_gameName), maxLength(in_maxLength), winNum(in_winNum)
{}

void Gomoku::print() {
	cout << *this;
}

ostream& operator<<(ostream& o, const Gomoku& g) {
	unsigned length = g.maxLength + 1;
	for (unsigned j = g.horizontalDim; j >= 1; j--) {
		o << setw(length) << j ;			// print the vertical coordinate
		for (size_t i = 1; i <= g.horizontalDim; i++) {
			if (g.gameBoard[g.horizontalDim * i + j] == "") {  // if empty, print a space
				o << setw(length) << " ";
			}
			else {
				o << setw(length) << g.gameBoard[g.horizontalDim * i + j];	// else, print out the display
			}
		}
		o << endl;
	}
	o << setw(length) << "X";
	for (unsigned i = 1; i <= g.horizontalDim; i++) {
		o << setw(length) << i;			// print the horizontal coordinate
	}
	cout << endl;
	return o;
}

bool Gomoku::done() {
	enum stones winner;
	
	for (unsigned i = 1; i <= horizontalDim; i++) { // iterate through row
		for (unsigned j = 1; j <= horizontalDim; j++) { // iterate through column
			unsigned k = j;//horizontal
			unsigned m = i;//vertical
			unsigned p = i;//diagonal
			unsigned q = j;//diagonal
			if (this->gameBoard[(size_t)horizontalDim * i + j] == "B") {
				//check if horizontal
				while (gameBoard[(size_t)horizontalDim * i + k] == "B" && k < j + winNum && k <= horizontalDim) {
					k++;
					winner = Black;
				}
				if (k == j + winNum) {
					cout << "winner is Black" << endl;
					this->print();
					return true;
				}

				// check if vertical
				while (gameBoard[(size_t)horizontalDim * m + j] == "B" && m < i + winNum && m <= horizontalDim) {
					m++;
					winner = Black;
				}
				if (m == i + winNum) {
					cout << "winner is Black" << endl;
					this->print();
					return true;
				}

				// check if diagonal
				while (gameBoard[(size_t)horizontalDim * p + q] == "B" && p < i + winNum && p <= horizontalDim && q < j + winNum && q <= horizontalDim) {
					p++;
					q++;
					winner = Black;
				}
				if (p == i + winNum || q == j + winNum) {
					cout << "winner is Black" << endl;
					this->print();
					return true;
				}
			}


			else if (this->gameBoard[(size_t)horizontalDim * i + j] == "W") {
				unsigned k = j;
				// check if horizontal
				while (gameBoard[(size_t)horizontalDim * i + k] == "W" && k < j + winNum && k <= horizontalDim) {
					k++;
					winner = White;
				}
				if (k == j + winNum) {
					cout << "winner is White" << endl;
					this->print();
					return true;
				}

				// check if vertical
				while (gameBoard[(size_t)horizontalDim * m + j] == "W" && m < i + winNum && m <= horizontalDim) {
					m++;
					winner = White;
				}
				if (m == i + winNum) {
					cout << "winner is White" << endl;
					this->print();
					return true;
				}

				// check if diagonal
				while (gameBoard[(size_t)horizontalDim * p + q] == "W" && p < i + winNum && p <= horizontalDim && q < j + winNum && q <= horizontalDim) {
					p++;
					q++;
					winner = White;
				}
				if (p == i + winNum || q == j + winNum) {
					cout << "winner is White" << endl;
					this->print();
					return true;
				}
			}

		}
	} 
	return false;
}

bool Gomoku::draw() {

	for (unsigned i = 1; i <= horizontalDim; i++) {
		for (unsigned j = 1; j <= horizontalDim; j++) {
			unsigned k = j;//horizontal
			unsigned m = i;//vertical
			unsigned p = i;//diagonal
			unsigned q = j;//diagonal
			if (this->gameBoard[(size_t)horizontalDim * i + j] == "B") {  //current is black
				// check if horizontal
				while ((gameBoard[(size_t)horizontalDim * i + k] == "B" || gameBoard[(size_t)horizontalDim * i + k] == "") && k < j + winNum && k <= horizontalDim) {
					k++;
				}
				if (k == j + winNum) {
					return false;
				}

				// check if vertical
				while ((gameBoard[(size_t)horizontalDim * m + j] == "B" || gameBoard[(size_t)horizontalDim * m + j] == "") && m < i + winNum && m <= horizontalDim) {
					m++;
				}
				if (m == i + winNum) {
					return false;
				}

				// check if diagonal
				while ((gameBoard[(size_t)horizontalDim * p + q] == "B" || gameBoard[(size_t)horizontalDim * p + q] == "") && p < i + winNum && p <= horizontalDim && q < j + winNum && q <= horizontalDim) {
					p++;
					q++;
				}
				if (p == i + winNum || q == j + winNum) {
					return false;
				}
			}


			else if (this->gameBoard[(size_t)horizontalDim * i + j] == "W") {//current is white
				// check if horizontal
				while ((gameBoard[(size_t)horizontalDim * i + k] == "W" || gameBoard[(size_t)horizontalDim * i + k] == "") && k < j + winNum && k <= horizontalDim) {
					k++;
				}
				if (k == j + winNum) {
					return false;
				}

				// check if vertical
				while ((gameBoard[(size_t)horizontalDim * m + j] == "W" || gameBoard[(size_t)horizontalDim * m + j] == "") && m < i + winNum && m <= horizontalDim) {
					m++;
				}
				if (m == i + winNum) {
					return false;
				}

				// check if diagonal
				while ((gameBoard[(size_t)horizontalDim * p + q] == "W" || gameBoard[(size_t)horizontalDim * p + q] == "") && p < i + winNum && p <= horizontalDim && q < j + winNum && q <= horizontalDim) {
					p++;
					q++;
				}
				if (p == i + winNum || q == j + winNum) {
					return false;
				}
			}


			else {   //gameboard[i][j] is empty

			  //check if black can win
				while ((gameBoard[(size_t)horizontalDim * i + k] == "B" || gameBoard[(size_t)horizontalDim * i + k] == "") && k < j + winNum && k <= horizontalDim) {
					k++;
				}
				if (k == j + winNum) {
					return false;
				}

				while ((gameBoard[(size_t)horizontalDim * m + j] == "B" || gameBoard[(size_t)horizontalDim * m + j] == "") && m < i + winNum && m <= horizontalDim) {
					m++;
				}
				if (m == i + winNum) {
					return false;
				}

				while ((gameBoard[(size_t)horizontalDim * p + q] == "B" || gameBoard[(size_t)horizontalDim * p + q] == "") && p < i + winNum && p <= horizontalDim && q < j + winNum && q <= horizontalDim) {
					p++;
					q++;
				}
				if (p == i + winNum || q == j + winNum) {
					return false;
				}

				//check if white can win
				k = j;
				m = i;
				p = i;
				q = j;

				while ((gameBoard[(size_t)horizontalDim * i + k] == "W" || gameBoard[(size_t)horizontalDim * i + k] == "") && k < j + winNum && k <= horizontalDim) {
					k++;
				}
				if (k == j + winNum) {
					return false;
				}
				while ((gameBoard[(size_t)horizontalDim * m + j] == "W" || gameBoard[(size_t)horizontalDim * m + j] == "") && m < i + winNum && m <= horizontalDim) {
					m++;
				}
				if (m == i + winNum) {
					return false;
				}
				while ((gameBoard[(size_t)horizontalDim * p + q] == "W" || gameBoard[(size_t)horizontalDim * p + q] == "") && p < i + winNum && p <= horizontalDim && q < j + winNum && q <= horizontalDim) {
					while ((gameBoard[(size_t)horizontalDim * p + q] == "W" || gameBoard[(size_t)horizontalDim * p + q] == "") && p < i + winNum && p <= horizontalDim && q < j + winNum && q <= horizontalDim) {
						p++;
						q++;
					}
					if (p == i + winNum || q == j + winNum) {
						return false;
					}
				}

			}

		}
		this->print();
		return true;
	}
	return true;
}


int Gomoku::turn() {

	this->print();		// print out the current board
	unsigned int horizontal;
	unsigned int vertical;
	unsigned int& x = horizontal;
	unsigned int& y = vertical;

	if (display == "B") {	// switch turns
		cout << "It's Black Player's turn." << endl;
	}
	else if (display == "W") {
		cout << "It's White Player's turn." << endl;
	}
	int result = prompt(x, y);

	// check if the point is already occupied
	if (result == state::success) {
		while (gameBoard[horizontalDim * (size_t)x + y] != "") {	// if the point is already occupied, reprompt the user to keep 
																	// entering inputs untill it's valid
			cout << "This point is already occupied." << endl;
			int result = prompt(x, y);
			if (result == state::success && gameBoard[horizontalDim * (size_t)x + y] == "") {
				break;
			}
			if (result == state::endGameByUser) {
				return result;
			}
		}
	}
	if (result == state::endGameByUser) {	// if the user enters "quit", return the appropriate enum state
		return result;
	}
	while (result == state::endGameInvalidInput || result == state::endGameExtractionError) { // if the user input is invalid or there is an extraction error,
																							// reprompt the user to keep entering inputs untill it's valid
		int result = prompt(x, y);
		if (result == state::success) {
			break;
		}
		if (result == state::endGameByUser) {
			return result;
		}
	}
	gameBoard[horizontalDim * (size_t)x + y] = display;	// set the corresponding index in gameBoard to be the current move of the player
	if (display == "B") {	// switch turns
		display = "W";
	}
	else if (display == "W") {
		display = "B";
	}
	return state::success;
}

