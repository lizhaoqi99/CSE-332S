[Errors and warnings]
One error that we had was that when we used the extraction operator to print the game board, the board was not printed but instead a line of hexadecimals were shown. The hexadecimal display was an indication of memory address being printed. The error was caused by this line of code: 
cout << this;
In the line of code above, this is a pointer that is not dereferenced so what's in the output is the memory address of this.After I changed the code to cout << *this;, where this was dereferenced, the game board was printed correctly.


[The following are test cases for TicTacToe game]
Assume player X executes the first move (so the game has maxLength = 1) if the user input is valid and successfully activates the game:

1. When having more than 1 input (H:\cse332\labs\Lab4\Lab4\Debug>Lab4.exe TicTacToe hello world), the program returns:
Usage: Please have at least one input but not more than three inputs
1 input usage: Lab4.exe <Game Name(TicTacToe or Gomoku)>
2 inputs usage: Lab4.exe <Game Name(TicTacToe or Gomoku)> <Board Dimension(optional, an integer greater than 4)>
3 inputs usage: Lab4.exe <Game Name(TicTacToe or Gomoku)> <Board Dimension(optional, an integer greater than 4)> <Number of Connecting Pieces to Win(optional, an integer greater than 4 and less than or equal to the board dimension)>


2. When having no input, the program returns 
Usage: Please have at least one input but not more than three inputs
1 input usage: Lab4.exe <Game Name(TicTacToe or Gomoku)>
2 inputs usage: Lab4.exe <Game Name(TicTacToe or Gomoku)> <Board Dimension(optional, an integer greater than 4)>
3 inputs usage: Lab4.exe <Game Name(TicTacToe or Gomoku)> <Board Dimension(optional, an integer greater than 4)> <Number of Connecting Pieces to Win(optional, an integer greater than 4 and less than or equal to the board dimension)>


3. When having exactly 1 input other than "TicTacToe", the program returns
Usage: Please have at least one input but not more than three inputs
1 input usage: Lab4.exe <Game Name(TicTacToe or Gomoku)>
2 inputs usage: Lab4.exe <Game Name(TicTacToe or Gomoku)> <Board Dimension(optional, an integer greater than 4)>
3 inputs usage: Lab4.exe <Game Name(TicTacToe or Gomoku)> <Board Dimension(optional, an integer greater than 4)> <Number of Connecting Pieces to Win(optional, an integer greater than 4 and less than or equal to the board dimension)>


4. When having exactly 1 input "TicTacToe", the program activates the game, prints "It is player X's turn.", and prompts the user to type either 'quit' 
or a valid coordinate (a comma-separated pair of unsigned decimal integers).
	a. If the user enters an invalid string such as "abc123", the program returns
	Invalid input: please enter two valid coordinates separated by a comma.
	, and will reprompt the user to type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).

	b. If the user enters a pair of valid integer but the input has spaces such as "1,  1", the program returns
	Invalid input: please enter two valid coordinates separated by a comma.
	, and will reprompt the user to type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).

	c. If the user enters no input or if the input is longer than 3 characters, the program returns
	Invalid input: please enter two valid coordinates separated by a comma.
	, and will reprompt the user to type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).

	d. If the user enters a pair of integers that are not greater than 0 and less than 4 such as "5,5", the program returns
	Invalid input: please enter two valid coordinates separated by a comma.
	, and will reprompt the user to type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
 
	e. If the user enters "quit", the program returns 
	(number of turns played) turns were played. The user quits.
	, and will end the program.

	f. If the user enters a valid pair of integers that are already occupied by the other player, the program returns
	This point is already occupied.
	, and will reprompt the user to type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).

	g. If the user enters a valid pair of integers such as "1,1", the program returns
	4
	3
	2
	1  X
	0
	 0 1 2 3 4
	Player X: 1,1
	
	Then the program prints "It is player O's turn.", and will prompt the user to type either 'quit' or a valid coordinate (a comma-separated pair of 
	unsigned decimal integers) for player O.

	Suppose player O enters another pair of valid integers such as "2,2", the program returns
	4
	3
	2    O
	1  X
	0
	 0 1 2 3 4
	Player O: 2,2

	Then the program prints "It is player X's turn.", and will prompt the user to type either 'quit' or a valid coordinate (a comma-separated pair of 
	unsigned decimal integers) for player X.

	Suppose player X enters another pair of valid integers such as "1,2", the program returns
	4
	3
	2  X O
	1  X
	0
	 0 1 2 3 4
	Player X: 1,1; 1,2

	If either play doesn't enter a valid pair of integers, the program behaves as described above.
	
	h. If one of the players have 3 consecutive moves horizontally, for instance, suppose player X has moves (1,1) (2,1) (3,1), and player O has moves
	(1,2) (2,2), the program returns
	4
	3
	2  O O
	1  X X X
	0
	 0 1 2 3 4
	Player X: 1,1; 2,1; 3,1

	Player X won the game.

	i. If one of the players have 3 consecutive moves vertically, for instance, suppose player X has moves (1,1) (1,2) (1,3), and player O has moves
	(2,1) (2,2), the program returns
	4
	3  X
	2  X O
	1  X O
	0
	 0 1 2 3 4
	Player X: 1,1; 1,2; 1,3

	Player X won the game.

	j. If one of the players have 3 consecutive moves diagonally, for instance, suppose player X has moves (1,1) (2,2) (3,3), and player O has moves
	(1,2) (1,3), the program returns
	4
	3  O   X
	2  O X
	1  X
	0
	 0 1 2 3 4
	Player X: 1,1; 2,2; 3,3

	Player X won the game.

	Suppose player X has moves (1,3) (2,2) (3,1), and player O has moves (1,2) (1,1), the program returns
	4
	3  X
	2  O X
	1  O   X
	0
	 0 1 2 3 4
	Player X: 1,3; 2,2; 3,1

	Player X won the game.

	k. If the gameBoard is full, the program prints “9 turns were played. No winning moves remain.”


Assume player XXX executes the first move (so the game has maxLength isn't 1 but 3) if the user input is valid and successfully activates the game:

For the above part 4.(a)(b)(c)(d)(e)(f)(k), the program behaves the same.

1. Vertical:
Player XXX: 1,1; 1,2; 1,3

4
3     XXX
2     XXX   O
1     XXX   O
0
    0   1   2   3   4
Player XXX won the game.


2. Horizontal:
Player XXX: 1,1; 2,1; 3,1

4
3
2       O   O
1     XXX XXX XXX
0
    0   1   2   3   4
Player XXX won the game.

3. Diagonal:
Player XXX: 1,1; 2,2; 3,3

4
3       O     XXX
2       O XXX
1     XXX
0
    0   1   2   3   4
Player XXX won the game.

Player XXX: 1,3; 2,2; 3,1

4
3     XXX
2       O XXX
1       O     XXX
0
    0   1   2   3   4
Player XXX won the game.

4. Quit:
After playing the game for 2 turns, and enter “quit”, the program returns:
2 turns were played. The user quits.

5. Invalid coordinates:
I tested invalid coordinates “-1,-1” and “5,5”, and invalid strings such as “fadsf”, “1 1”, “3,,3”, “1, 1” and the program returns “Invalid input: please enter two valid coordinates separated by a comma.” and prompts the user to reenter the input.




[The following are test cases for Gomoku Game]
In Gomoku, it is defined that the black player(displayed with “B”) moves first; since the display string of either player is one character in length (either a “B” or a “W”), however, the dimension of the gameboard could be more than one digit (e.g. by default, the  board has dimension of 19, which is 2-character long), thus the maxLength should be determined by the number of digits gameBoard has. If the user input is correct and valid, the output should be as following:

If the user inputs 2 arguments, where the first argument is the correct program name(“Lab4.exe”) and the second argument is the correct game name (“Gomoku”):

A. The program should print out the game board, tell the user that it’s black player’s turn and prompt the user to give a valid coordinate.
 19
 18
 17
 16
 15
 14
 13
 12
 11
 10
  9
  8
  7
  6
  5
  4
  3
  2
  1
  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
It's Black Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).

B. If the black player then inputs  a  valid coordinate, (e.g. 19,18), the program should print out the gameboard again, with a “B” at the corresponding position. Then it will switch the player to “W”, tell the player that it’s the white player’s turn and ask for a valid input coordinate or “quit”.
 19
 18                                                        B
 17
 16
 15
 14
 13
 12
 11
 10
  9
  8
  7
  6
  5
  4
  3
  2
  1
  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
It's White Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).

C. If the white player then inputs  a  valid coordinate, (e.g. 1,2), the program should print out the gameboard again, with a “W” at the corresponding position. Then it will switch the player to “B”, tell the player that it’s the black player’s turn and ask for a valid input coordinate or “quit”.
 19
 18                                                        B
 17
 16
 15
 14
 13
 12
 11
 10
  9
  8
  7
  6
  5
  4
  3
  2  W
  1
  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
It's Black Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).

D. The game will repeat this procedure until some player has 5 pieces connected together(i.e. That player wins the game). 
A player has 5 pieces connected with each other horizontally
      E.g. after the following series of inputs, the black player wins.
B: (19,18) (18,18) (17,18) (15,18) (16,18)
W: (1,2) (2,1) (5,6) (7,8)
The program will print out that “the winner is Black”, the current state of the game board and then return true and end the game.
winner is Black
 19
 18                                            B  B  B  B  B
 17
 16
 15
 14
 13
 12
 11
 10
  9
  8                    W
  7
  6              W
  5
  4
  3
  2  W
  1     W
  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

A player has 5 pieces connected with each other vertically.
E.g. after the following series of inputs, the white player wins.
B:(1,2) (5,6) (17,13) (14,15) (9,6)
W:(7,8) (9,10) (8,9) (11,12) (10,11)
The program will print out that “the winner is White”, the current state of the game board and then return true.
winner is White
 19
 18
 17
 16
 15                                         B
 14
 13                                                  B
 12                                W
 11                             W
 10                          W
  9                       W
  8                    W
  7
  6              B           B
  5
  4
  3
  2  B
  1
  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

A player has 5 pieces connected with each other diagonally.
E.g. after the following series of inputs, the black player wins.
B: (18,19) (17,18) (16,17) (15,16) (14,15)
W: (3,4) (5,6) (1,19) (3,13)
The program will print out that “the winner is Black”, the current state of the game board and then return true.
winner is Black
 19  W                                                  B
 18                                                  B
 17                                               B
 16                                            B
 15                                         B
 14
 13        W
 12
 11
 10
  9
  8
  7
  6              W
  5
  4        W
  3
  2
  1
  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

2. If the user input has 3 arguments, where the first argument is the correct program name, the second is the correct game name, the third argument is a valid integer which is >=5 for an custom board dimension;
By default, the number of connected pieces of each player that is needed to win the game is 5.

E.g. If the User input is Lab4.exe Gomoku 10
A. The program should print out the game board(with horizontal and vertical dimension from 1 to 10), tell the user that it’s black player’s turn and prompt the user to give a valid coordinate.
10
  9
  8
  7
  6
  5
  4
  3
  2
  1
  X  1  2  3  4  5  6  7  8  9 10
It's Black Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).

B. If the black player then inputs  a  valid coordinate, (e.g. 9,9), the program should print out the gameboard again, with a “B” at the corresponding position. Then it will switch the player to “W”, tell the player that it’s the white player’s turn and ask for a valid input coordinate or “quit”.
 10
  9                          B
  8
  7
  6
  5
  4
  3
  2
  1
  X  1  2  3  4  5  6  7  8  9 10
It's White Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).

C.  If the white player then inputs  a  valid coordinate, (e.g. 1,2), the program should print out the gameboard again, with a “W” at the corresponding position. Then it will switch the player to “B”, tell the player that it’s the black player’s turn and ask for a valid input coordinate or “quit”.
 10
  9                          B
  8
  7
  6
  5
  4
  3
  2  W
  1
  X  1  2  3  4  5  6  7  8  9 10
It's Black Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).

D. The game will repeat this procedure until some player has 5 pieces connected together(i.e. That player wins the game). 
A player has 5 pieces connected with each other horizontally
           E.g. after the following series of inputs, the black player wins.
B: (9,9) (8,9) (6,9) (5,9) (7,9)
W: (1,2) (2,1) (5,6) (7,8)

The program will print out that “the winner is Black”, the current state of the game board and then return true and end the game.
winner is Black
 10
  9              B  B  B  B  B
  8                    W
  7
  6              W
  5
  4
  3
  2  W
  1     W
  X  1  2  3  4  5  6  7  8  9 10

A player has 5 pieces connected with each other vertically.
            E.g. after the following series of inputs, the white player wins.
B: (1,3) (2,4) (7,5) (8,7) (7,6)
W: (3,3) (3,4) (3,5) (3,6) (3,7)
The program will print out that “the winner is White”, the current state of the game board and then return true.
winner is White
 10
  9
  8
  7        W              B
  6        W           B
  5        W           B
  4     B  W
  3  B     W
  2
  1
  X  1  2  3  4  5  6  7  8  9 10

A player has 5 pieces connected with each other diagonally.
            E.g. after the following series of inputs, the white player wins.
B: (1,3) (2,4) (7,5) (8,7) (7,6)
W: (3,3) (4,4) (5,5) (6,6) (7,7)
The program will print out that “the winner is White”, the current state of the game board and then return true.
winner is White
 10
  9
  8
  7                    W  B
  6                 W  B
  5              W     B
  4     B     W
  3  B     W
  2
  1
  X  1  2  3  4  5  6  7  8  9 10

3. If the user input has 4 arguments, where the first argument is the correct program name, the second is the correct game name, the third argument is a valid integer which is >=5 for an custom board dimension, the fourth argument is a valid integer which is >=5 for an custom number of connected pieces for each player that is needed to win the game.

E.g. If the User input is Lab4.exe Gomoku 10 6
A. The program should print out the game board, tell the user that it’s black player’s turn and prompt the user to give a valid coordinate.
  10
   9
   8
   7
   6
   5
   4
   3
   2
   1
   X   1   2   3   4   5   6   7   8   9  10
It's Black Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).

B. If the black player then inputs  a  valid coordinate, (e.g. 9,9), the program should print out the gameboard again, with a “B” at the corresponding position. Then it will switch the player to “W”, tell the player that it’s the white player’s turn and ask for a valid input coordinate or “quit”.
  10
   9                                   B
   8
   7
   6
   5
   4
   3
   2
   1
   X   1   2   3   4   5   6   7   8   9  10
It's White Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).

C.  If the white player then inputs  a  valid coordinate, (e.g. 1,2), the program should print out the gameboard again, with a “W” at the corresponding position. Then it will switch the player to “B”, tell the player that it’s the black player’s turn and ask for a valid input coordinate or “quit”.
  10
   9                                   B
   8
   7
   6
   5
   4
   3
   2   W
   1
   X   1   2   3   4   5   6   7   8   9  10
It's Black Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).

D. The game will repeat this procedure until some player has 6(which is the user input number, in this case is 6) pieces connected together(i.e. That player wins the game). 
1?A player has 6 pieces connected with each other horizontally
      E.g. after the following series of inputs, the black player wins.
      B: (9,9) (8,9) (6,9) (5,9) (7,9) (4,9)
      W: (1,2) (2,1) (5,6) (7,8) (2,5)

The program will print out that “the winner is Black”, the current state of the game board and then return true.
winner is Black
  10
   9               B   B   B   B   B   B
   8                           W
   7
   6                   W
   5       W
   4
   3
   2   W
   1       W
   X   1   2   3   4   5   6   7   8   9  10

2? A player has 6 pieces connected with each other vertically.
      E.g. after the following series of inputs, the white player wins.
      B: (1,3) (2,4) (7,5) (8,7) (7,6) (9,9)3
      W: (3,3) (3,4) (3,5) (3,6) (3,7) (3,2)

The program will print out that “the winner is White”, the current state of the game board and then return true ending the game.
winner is White
  10
   9                                   B
   8
   7           W                   B
   6           W               B
   5           W               B
   4       B   W
   3   B       W
   2           W
   1
   X   1   2   3   4   5   6   7   8   9  10

3)A player has 6 pieces connected with each other diagonally.
   E.g. after the following series of inputs, the white player wins.
   B: (1,3) (2,4) (7,5) (8,7) (7,6) (8,8)
   W: (3,3) (4,4) (5,5) (6,6) (7,7) (2,2)

The program will print out that “the winner is White”, the current state of the game board and then return true ending the game.
winner is White
  10
   9
   8                               B
   7                           W   B
   6                       W   B
   5                   W       B
   4       B       W
   3   B       W
   2       W
   1
   X   1   2   3   4   5   6   7   8   9  10

4. If until now, no player has won and there is possibility for either player to win(though there may still be some empty space on the gameboard), the program should print out the current state of the gameboard and end the game, returning a specific value(return state::endGameNoWinningMovesRemain;) indicating “No winning moves remain."
E.g. my input is Lab4.exe Gomoku 5 5
After the following moves, neither Black player or White player can win the game, but  there is still empty space on the game board, the output of the program should be:
Moves:
B:(1,1) (3,3) (5,5) (5,2) (4,1) (1,4)
W:(2,2) (4,4) (5,3) (3,1) (1,5)

Output:
  5  W           B
  4  B        W
  3        B     W
  2     W        B
  1  B     W  B
  X  1  2  3  4  5
11 turns were played. No winning moves remain.

5. Some invalid input cases:
If the user input has a third argument that is not an integer, the program will call usage message, and tell the user what is the correct format of the input argument:
E.g. 
Input: Lab4.exe Gomoku a
Output:
Usage: Please have at least one input but not more than three inputs
1 input usage: Lab4.exe <Game Name(TicTacToe or Gomoku)>
2 inputs usage: Lab4.exe <Game Name(TicTacToe or Gomoku)> <Board Dimension(optional, an integer greater than 4)>
3 inputs usage: Lab4.exe <Game Name(TicTacToe or Gomoku)> <Board Dimension(optional, an integer greater than 4)> <Number of Connecting Pieces to Win(optional, an integer greater than 4 and less than or equal to the board dimension)>
If the user input has a third argument that is an integer <5, the program will call usage message, and tell the user what is the correct format of the input argument:
E.g.
Input: Lab4.exe Gomoku 4
Output:
Usage: Please have at least one input but not more than three inputs
1 input usage: Lab4.exe <Game Name(TicTacToe or Gomoku)>
2 inputs usage: Lab4.exe <Game Name(TicTacToe or Gomoku)> <Board Dimension(optional, an integer greater than 4)>
3 inputs usage: Lab4.exe <Game Name(TicTacToe or Gomoku)> <Board Dimension(optional, an integer greater than 4)> <Number of Connecting Pieces to Win(optional, an integer greater than 4 and less than or equal to the board dimension)>
If the user input has a fourth argument that is not an integer, the program will call usage message, and tell the user what is the correct format of the input argument:
 Input: Lab4.exe Gomoku 5 a
Output:
Usage: Please have at least one input but not more than three inputs
1 input usage: Lab4.exe <Game Name(TicTacToe or Gomoku)>
2 inputs usage: Lab4.exe <Game Name(TicTacToe or Gomoku)> <Board Dimension(optional, an integer greater than 4)>
3 inputs usage: Lab4.exe <Game Name(TicTacToe or Gomoku)> <Board Dimension(optional, an integer greater than 4)> <Number of Connecting Pieces to Win(optional, an integer greater than 4 and less than or equal to the board dimension)>
If the user input has a third argument that is an integer <5, the program will call usage message, and tell the user what is the correct format of the input argument:
Input: Lab4.exe Gomoku 5 4
Output:
Usage: Please have at least one input but not more than three inputs
1 input usage: Lab4.exe <Game Name(TicTacToe or Gomoku)>
2 inputs usage: Lab4.exe <Game Name(TicTacToe or Gomoku)> <Board Dimension(optional, an integer greater than 4)>
3 inputs usage: Lab4.exe <Game Name(TicTacToe or Gomoku)> <Board Dimension(optional, an integer greater than 4)> <Number of Connecting Pieces to Win(optional, an integer greater than 4 and less than or equal to the board dimension)> 
During the game, anytime the player enters anything other than a coordinate of the form x,y(where x and y are integers that are >=1 and <= the dimension of the board), the program will call usagemessage, tell the user what is the correct input format and rannge, and then the program will repeatedly reprompt the user to give another coordinate until the given coordinate is in the form of “x,y” and both x and y are in the valid board range(still, there can be another error which happens when the point has already been occupied by another game piece, see F) .
E.g. On the default gomoku gameboard(which is 19*19 and needs 5 pieces connected to win the game)
Input: a
Ouput:
Invalid input: please enter two valid coordinates separated by a comma.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).

Input: 3 4
Output: Invalid input: please enter two valid coordinates separated by a comma.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).

Input: 20,20
Output: Invalid input: please enter two valid coordinates separated by a comma.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
 During the game, if the player enters a coordinate that is in the range of the gameboard but has already been occupied by another game piece, the program will call usagemessage, telling the player that this position has already been occupied and then repeatedly reprompt the user to give another coordinate until the user gives a valid coordinate that has not been occupied by another gamepiece.
E.g. On the default gomoku gameboard(which is 19*19 and needs 5 connected pieces to win the game)
Input:
B:(1,1)
W:(1,1)
Output:
This point is already occupied.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
During the game, if the player enters “quit”, the program will print out a message telling the players that “The user quits”,and then returns a specific value indicating that the user ends the game(state::endGameByUser) ending the game.
E.g. On the default gomoku gameboard
Input:
B: (1,2), quit
W:(2,1)
Output:
2 turns were played. The user quits.

------------------------------------------------------------------------------------------------------------------------------
[Extra Credit]

Design and implementation:
To add the extra credit feature, a member variable that represents the number of connecting pieces needed to win is added to each of the three classes.
The number of connecting pieces to win depends on the game type as well as the number of input arguments.
If the game type is TicTacToe, then this member variable is initialized to 3 by default.
If the game type if Gomoku, then this member variable is initialized to a value that is determined by the input arguments.

In the check function in GameBase.cpp, we check the number of command arguments.

If the number of command argument is three, we check whether the third input is valid and whether the input game name is Gomoku.
If either of the conditions is not satisfied, usageMessage is called to remind the user of the correct input format.
For the third input to be valid, it has to be an integer greater than or equal to 5. 
Then a new Gomoku game is dynamically allocated with several initialized values.
The number of connecting pieces to win is 5, longest display length is determined by the number of digits in the board dimension integer,
and the horizontal and vertical dimension of the game board is the input integer value. 

If the number of command argument is four, we check whether the third and fourth inputs are valid and whether the input game name is Gomuku.
If any one of the three conditions is not satisfied, usageMessage is called to remind the user of the correct input format. 
The third input argument is checked in the same way as stated before.
The fourth input argument has to be an integer greater than or equal to 5 and smaller than or equal to the board dimension.
Then a new Gomoku game is dynamically allocated with several initialized values.
The number of connecting pieces to win is the fourth input argument, longest display length is determined by the number of digits 
in the board dimension integer and the horizontal and vertical dimension of the game board is the input integer value.
In Gomoku.cpp, the done and draw methods are also modifed so that the for loops take into consideration of the new board 
dimension and number of connecting pieces to win when checking whether there is a winner or whether the game is a draw.

If the number of comman argument exceeds four, the usageMessage is called to remind the user of the correct input method.


The following are several test cases after the extra credit component is added:


1. no additional arguments after the game name, play TicTacToe
	As can be seen in the process shown below, the TicTacToe game is still able to play normally and correctly.
	The game flow is correct, display is correct, number of connecting pieces to win is correct and the board dimension is also correct.
	
	H:\CS332S_CZ\lab4-li_ma_zhang\Lab4\x64\Debug>Lab4.exe TicTacToe
4
3
2
1
0
  0 1 2 3 4
It is player X's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
1,1

Player X: 1,1

4
3
2
1   X
0
  0 1 2 3 4
It is player O's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
3,3

Player O: 3,3

4
3       O
2
1   X
0
  0 1 2 3 4
It is player X's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
1,2

Player X: 1,1; 1,2

4
3       O
2   X
1   X
0
  0 1 2 3 4
It is player O's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
3,1

Player O: 3,3; 3,1

4
3       O
2   X
1   X   O
0
  0 1 2 3 4
It is player X's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
1,3

Player X: 1,1; 1,2; 1,3

4
3   X   O
2   X
1   X   O
0
  0 1 2 3 4
Player X won the game.


2. no additional arguments after the game name, play Gomoku
	As shown by the process below, the Gomoku is still able to play successfully and correctly.
	The display, board dimension, number of connecting pieces to play and flow of the game are all correct as usual.

H:\CS332S_CZ\lab4-li_ma_zhang\Lab4\x64\Debug>Lab4.exe Gomoku
 19
 18
 17
 16
 15
 14
 13
 12
 11
 10
  9
  8
  7
  6
  5
  4
  3
  2
  1
  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
It's Black Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
1,1

 19
 18
 17
 16
 15
 14
 13
 12
 11
 10
  9
  8
  7
  6
  5
  4
  3
  2
  1  B
  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
It's White Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
5,5

 19
 18
 17
 16
 15
 14
 13
 12
 11
 10
  9
  8
  7
  6
  5              W
  4
  3
  2
  1  B
  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
It's Black Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
19,19

 19                                                        B
 18
 17
 16
 15
 14
 13
 12
 11
 10
  9
  8
  7
  6
  5              W
  4
  3
  2
  1  B
  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
It's White Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
5,6

 19                                                        B
 18
 17
 16
 15
 14
 13
 12
 11
 10
  9
  8
  7
  6              W
  5              W
  4
  3
  2
  1  B
  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
It's Black Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
18,17

 19                                                        B
 18
 17                                                     B
 16
 15
 14
 13
 12
 11
 10
  9
  8
  7
  6              W
  5              W
  4
  3
  2
  1  B
  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
It's White Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
1,1

This point is already occupied.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
5,4

 19                                                        B
 18
 17                                                     B
 16
 15
 14
 13
 12
 11
 10
  9
  8
  7
  6              W
  5              W
  4              W
  3
  2
  1  B
  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
It's Black Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
8,10

 19                                                        B
 18
 17                                                     B
 16
 15
 14
 13
 12
 11
 10                       B
  9
  8
  7
  6              W
  5              W
  4              W
  3
  2
  1  B
  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
It's White Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
5,7

 19                                                        B
 18
 17                                                     B
 16
 15
 14
 13
 12
 11
 10                       B
  9
  8
  7              W
  6              W
  5              W
  4              W
  3
  2
  1  B
  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
It's Black Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
19,10

 19                                                        B
 18
 17                                                     B
 16
 15
 14
 13
 12
 11
 10                       B                                B
  9
  8
  7              W
  6              W
  5              W
  4              W
  3
  2
  1  B
  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
It's White Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
5,3

winner is White
 19                                                        B
 18
 17                                                     B
 16
 15
 14
 13
 12
 11
 10                       B                                B
  9
  8
  7              W
  6              W
  5              W
  4              W
  3              W
  2
  1  B
  X  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

H:\CS332S_CZ\lab4-li_ma_zhang\Lab4\x64\Debug>


3. with a single extra argument of 3

H:\CS332S_CZ\lab4-li_ma_zhang\Lab4\x64\Debug>Lab4.exe Gomoku 3
Usage: Please have at least one input but not more than three inputs
1 input usage: Lab4.exe <Game Name(TicTacToe or Gomoku)>
2 inputs usage: Lab4.exe <Game Name(TicTacToe or Gomoku)> <Board Dimension(optional, an integer greater than 4)>
3 inputs usage: Lab4.exe <Game Name(TicTacToe or Gomoku)> <Board Dimension(optional, an integer greater than 4)> <Number of Connecting Pieces to Win(optional, an integer greater than 4 and less than or equal to the board dimension)>

As shown by the response above, the program correctly detected and reported the mistake.
The third argument has to be a number greater than or equal to 5 beccause this is a Gomoku game and the game board dimension cannot be smaller than five.
(The rule stated above is defined by the manual and suggested by a piazza post)


4. with two extra arguments of 3 and 3

H:\CS332S_CZ\lab4-li_ma_zhang\Lab4\x64\Debug>Lab4.exe Gomoku 3 3
Usage: Please have at least one input but not more than three inputs
1 input usage: Lab4.exe <Game Name(TicTacToe or Gomoku)>
2 inputs usage: Lab4.exe <Game Name(TicTacToe or Gomoku)> <Board Dimension(optional, an integer greater than 4)>
3 inputs usage: Lab4.exe <Game Name(TicTacToe or Gomoku)> <Board Dimension(optional, an integer greater than 4)> <Number of Connecting Pieces to Win(optional, an integer greater than 4 and less than or equal to the board dimension)>

Again, as shown by the response above, the program correctly detected and reported the mistake.
The third argument and the fourth argument cannot be smaller than five because this is a Gomoku game and the game board dimension and number of connecting pieces to win cannot be samller than five.
(The above rule is defined by the manual and suggested by a piazza post)

5. input a board dimension with a non-positive number

H:\CS332S_CZ\lab4-li_ma_zhang\Lab4\x64\Debug>Lab4.exe Gomoku -1 3
Usage: Please have at least one input but not more than three inputs
1 input usage: Lab4.exe <Game Name(TicTacToe or Gomoku)>
2 inputs usage: Lab4.exe <Game Name(TicTacToe or Gomoku)> <Board Dimension(optional, an integer greater than 4)>
3 inputs usage: Lab4.exe <Game Name(TicTacToe or Gomoku)> <Board Dimension(optional, an integer greater than 4)> <Number of Connecting Pieces to Win(optional, an integer greater than 4 and less than or equal to the board dimension)>

As shown by the process above, the program successfully detected a non-positive board dimension input.
It correctly called the usageMessage to remind the user of the correct way to input command line arguments.

6. with one extra argument of 9

As shown by the process below, a Gomoku game with game board dimension 9 is correctly played.
The game board display is correct. The number of connecting pieces to win is correctly set to the default value 5. 
The program correctly displayed each piece at its correct position.
The game play flow is correct.
The program also correctly reprompted the user when given an invalid input.

H:\CS332S_CZ\lab4-li_ma_zhang\Lab4\x64\Debug>Lab4.exe Gomoku 9
 9
 8
 7
 6
 5
 4
 3
 2
 1
 X 1 2 3 4 5 6 7 8 9
It's Black Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
1,1

 9
 8
 7
 6
 5
 4
 3
 2
 1 B
 X 1 2 3 4 5 6 7 8 9
It's White Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
8,7

 9
 8
 7               W
 6
 5
 4
 3
 2
 1 B
 X 1 2 3 4 5 6 7 8 9
It's Black Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
2,2

 9
 8
 7               W
 6
 5
 4
 3
 2   B
 1 B
 X 1 2 3 4 5 6 7 8 9
It's White Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
9,9

 9                 W
 8
 7               W
 6
 5
 4
 3
 2   B
 1 B
 X 1 2 3 4 5 6 7 8 9
It's Black Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
adasdsad

Invalid input: please enter two valid coordinates separated by a comma.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
3,3

 9                 W
 8
 7               W
 6
 5
 4
 3     B
 2   B
 1 B
 X 1 2 3 4 5 6 7 8 9
It's White Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
8,4

 9                 W
 8
 7               W
 6
 5
 4               W
 3     B
 2   B
 1 B
 X 1 2 3 4 5 6 7 8 9
It's Black Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
4,4

 9                 W
 8
 7               W
 6
 5
 4       B       W
 3     B
 2   B
 1 B
 X 1 2 3 4 5 6 7 8 9
It's White Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
2,5

 9                 W
 8
 7               W
 6
 5   W
 4       B       W
 3     B
 2   B
 1 B
 X 1 2 3 4 5 6 7 8 9
It's Black Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
5,5

winner is Black
 9                 W
 8
 7               W
 6
 5   W     B
 4       B       W
 3     B
 2   B
 1 B
 X 1 2 3 4 5 6 7 8 9

H:\CS332S_CZ\lab4-li_ma_zhang\Lab4\x64\Debug>


7. two extra command line arguments with the third one being 10 and fourth one being 6
As can be seen in the process shown below, when the two extra command line arguments are both valid, the Gomoku game is able to successfully play.
The game board adjusts the dimension correctly to 10.
The game rule is correctly updated so that the number of connecting pieces to win is now 6.
The game display, print, and flow are all correct as usual.
The game is also able to deal with invalid inputs correctly.

H:\CS332S_CZ\lab4-li_ma_zhang\Lab4\x64\Debug>Lab4.exe Gomoku 10 6
  10
   9
   8
   7
   6
   5
   4
   3
   2
   1
   X   1   2   3   4   5   6   7   8   9  10
It's Black Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
1,1

  10
   9
   8
   7
   6
   5
   4
   3
   2
   1   B
   X   1   2   3   4   5   6   7   8   9  10
It's White Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
1010

Invalid input: please enter two valid coordinates separated by a comma.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
10,10

  10                                       W
   9
   8
   7
   6
   5
   4
   3
   2
   1   B
   X   1   2   3   4   5   6   7   8   9  10
It's Black Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
2,2

  10                                       W
   9
   8
   7
   6
   5
   4
   3
   2       B
   1   B
   X   1   2   3   4   5   6   7   8   9  10
It's White Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
8,5

  10                                       W
   9
   8
   7
   6
   5                               W
   4
   3
   2       B
   1   B
   X   1   2   3   4   5   6   7   8   9  10
It's Black Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
3,3

  10                                       W
   9
   8
   7
   6
   5                               W
   4
   3           B
   2       B
   1   B
   X   1   2   3   4   5   6   7   8   9  10
It's White Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
2,9

  10                                       W
   9       W
   8
   7
   6
   5                               W
   4
   3           B
   2       B
   1   B
   X   1   2   3   4   5   6   7   8   9  10
It's Black Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
4,4

  10                                       W
   9       W
   8
   7
   6
   5                               W
   4               B
   3           B
   2       B
   1   B
   X   1   2   3   4   5   6   7   8   9  10
It's White Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
2,5

  10                                       W
   9       W
   8
   7
   6
   5       W                       W
   4               B
   3           B
   2       B
   1   B
   X   1   2   3   4   5   6   7   8   9  10
It's Black Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
5,5

  10                                       W
   9       W
   8
   7
   6
   5       W           B           W
   4               B
   3           B
   2       B
   1   B
   X   1   2   3   4   5   6   7   8   9  10
It's White Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
1,2

  10                                       W
   9       W
   8
   7
   6
   5       W           B           W
   4               B
   3           B
   2   W   B
   1   B
   X   1   2   3   4   5   6   7   8   9  10
It's Black Player's turn.
Please type either 'quit' or a valid coordinate (a comma-separated pair of unsigned decimal integers).
6,6

winner is Black
  10                                       W
   9       W
   8
   7
   6                       B
   5       W           B           W
   4               B
   3           B
   2   W   B
   1   B
   X   1   2   3   4   5   6   7   8   9  10
