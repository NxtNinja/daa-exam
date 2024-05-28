#include <stdio.h>
#include <stdbool.h>

#define N 4 // Change this value to solve for a different size of the board

void printBoard(char board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(char board[N][N], int row, int col)
{
    // Check this column on upper side
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    // Check upper diagonal on right side
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    return true;
}

void nqueen(char board[N][N], int row)
{
    if (row == N)
    {
        printBoard(board);
        return;
    }

    for (int col = 0; col < N; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 'Q';
            nqueen(board, row + 1);
            board[row][col] = '-'; // Backtrack
        }
    }
}

int main()
{
    char board[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = '-';
        }
    }
    nqueen(board, 0);
    return 0;
}
