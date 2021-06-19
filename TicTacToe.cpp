#include <stdio.h>
using namespace std;
int move;

char gamegrid(int i) {
    switch(i) {
        case -1:
            return 'X';
        case 0:
            return ' ';
        case 1:
            return 'O';
    }
}
void gameboard(int b[9]) {
    printf("\t\t\t\t\t\t %c | %c | %c\n",gamegrid(b[0]),gamegrid(b[1]),gamegrid(b[2]));
    printf("\t\t\t\t\t\t---+---+---\n");
    printf("\t\t\t\t\t\t %c | %c | %c\n",gamegrid(b[3]),gamegrid(b[4]),gamegrid(b[5]));
    printf("\t\t\t\t\t\t---+---+---\n");
    printf("\t\t\t\t\t\t %c | %c | %c\n",gamegrid(b[6]),gamegrid(b[7]),gamegrid(b[8]));
}

int wins(const int board[9]) {
    unsigned wins[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int i;
    for(i = 0; i < 8; ++i) {
        if(board[wins[i][0]] != 0 &&
           board[wins[i][0]] == board[wins[i][1]] &&
           board[wins[i][0]] == board[wins[i][2]])
            return board[wins[i][2]];
    }
    return 0;
}

int minimax(int board[9], int p1) {
    int winner = wins(board);
    if(winner != 0) return winner*p1;

    move = -1;
    int score = -2;
    int i;
    for(i = 0; i < 9; ++i) {
        if(board[i] == 0) {
            board[i] = p1;
            int thisScore = -minimax(board, p1*-1);
            if(thisScore > score) {
                score = thisScore;
                move = i;
            }
            board[i] = 0;
        }
    }
    if(move == -1) return 0;
    return score;
}

void CompMoves(int board[9]) {
    int move = -1;
    int score = -2;
    int i;
    for(i = 0; i < 9; ++i) {
        if(board[i] == 0) {
            board[i] = 1;
            int temp = -minimax(board, -1);
            board[i] = 0;
            if(temp > score) {
                score = temp;
                move = i;
            }
        }
    }
    board[move] = 1;
}

void p1moves(int board[9]) 
{
	int move = 0;
	do 
	{
		start:
		printf("\nInput move ([1 - 9]): ");
		scanf("%d", &move);
		if(move<1 || move>9)
		{
			printf("\nInvalid Move!");
			goto start;
		}
		move=move-1;
		if(board[move] != 0) 
		{
			printf("\nMove already played! ");
			goto start;
		}
		printf("\n");
	}	 
	while (move >= 9 || move < 0 && board[move] == 0);
	board[move] = -1;
}

int main() 
{
	printf("\t\t\t\t\t\t  1 | 2 | 3 \n");
    printf("\t\t\t\t\t\t ---+---+---\n");
    printf("\t\t\t\t\t\t  4 | 5 | 6 \n");
    printf("\t\t\t\t\t\t ---+---+---\n");
    printf("\t\t\t\t\t\t  7 | 8 | 9\n");
    int board[9] = {0,0,0,0,0,0,0,0,0};
    int p1=0;
    printf("Computer plays O, You play X\nPlay (1)st or (2)nd?: ");
    scanf("%d",&p1);
    printf("\n");
    unsigned chance;
    for(chance = 0; chance < 9 && wins(board) == 0; ++chance) {
        if((chance+p1) % 2 == 0)
            CompMoves(board);
        else {
            gameboard(board);
            p1moves(board);
        }
    }
    switch(wins(board)) {
        case 0:
            printf("Draw!\n");
            break;
        case 1:
            gameboard(board);
            printf("Computer Wins!\n");
            break;
        case -1:
            printf("Player Wins!\n");
            break;
    }
}
