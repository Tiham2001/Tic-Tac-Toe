# Tic-Tac-Toe
AIM: Making a foolproof tic-tac-toe bot using Data Structure and Algorithm in C language.

INTRODUCTION: The tic tac toe bot uses minimax algorithm and evaluation function to write a proper Tic-TacToe AI (Artificial Intelligence) that plays a perfect game. This AI will consider all possible scenarios and makes the
most optimal move. With the minimax algorithm the bot takes into consideration all the possibilities and makes the most
error free move. Thus this bot will never allow the user to win a game as it always plays the most optimal move.

The basic working of the bot is as follows:
function findBestMove(board):
 bestMove = NULL
 for each move in board :
 if current move is better than bestMove
 bestMove = current move
 return bestMove
 
RELATED APPROACHES:
• MINIMAX ALGORITHM: Minimax is a kind of back tracking algorithm that is used in decision making and game
theory to find the optimal move for a player, assuming that your opponent also plays optimally. It is widely
used in two player turn-based games such as Tic-Tac-Toe, Backgammon, Mancala, Chess, etc.
In Minimax the two players are called maximizer and minimizer. The maximizer tries to get the highest score
possible while the minimizer tries to do the opposite and get the lowest score possible.
Every board state has a value associated with it. In a given state if the maximizer has upper hand then, the
score of the board will tend to be some positive value. If the minimizer has the upper hand in that board state
then it will tend to be some negative value. The values of the board are calculated by some heuristics which
are unique for every type of game.

• EVALUATION FUNCTION:
As seen in the above article, each leaf node had a value associated with it. We had stored this value in an array. But
in the real world when we are creating a program to play Tic-Tac-Toe, Chess, Backgamon, etc. we need to
implement a function that calculates the value of the board depending on the placement of pieces on the board. This
function is often known as Evaluation Function. It is sometimes also called Heuristic Function.
The evaluation function is unique for every type of game. In this post, evaluation function for the game Tic-Tac-Toe is
discussed. The basic idea behind the evaluation function is to give a high value for a board if maximizer‘s turn or a
low value for the board if minimizer‘s turn

CONCLUSION: The tic tac toe bot aptly responds to the user’s inputs and maintains a perfect game resulting in
either a draw or a win for the bot in every game scenario using the minimax algorithm and Evaluation function.

REFERENCE:
• https://www.geeksforgeeks.org/
• https://cs.stackexchange.com/
