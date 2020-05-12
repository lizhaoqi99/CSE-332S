// Lab4.cpp
// Lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Steve Li (zhaoqi.li@wustl.edu), Xiaowen Ma (maxiaowen@wustl.edu), Claire Zhang (zhangbin@wustl.edu)

#include <iostream>
#include "GameBase.h"
#include "TicTacToeGame.h"

int main(int argc, char *argv[])
{
	
	GameBase* currentGame = GameBase::check(argc, argv);	// construct a new game from the output of check function
	if (currentGame == nullptr) {	// if currentGame is a nullptr, delete the object, free the memory and return appropriate enum value
		delete currentGame;
		currentGame = 0;
		return state::usageCalled;
	}
	else {
		int result = currentGame->play();	// if currentGame is valid, call function play, and delete the object afterwards and return appropriate enum value
		delete currentGame;
		currentGame = 0;
		return result; // use the return value from play, which covers all failure or success cases
	}

}
