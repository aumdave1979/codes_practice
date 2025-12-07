#include <iostream>
using namespace std;
bool isValid(int board[9][9], int row, int col, int num)
{
    // check in row
    for (int j = 0; j < 9; j++)
    {
        if (board[row][j] == num)
            return false;
    }
    // to check in column
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == num)
            return false;
    }
    int sr = row - row % 3;
    int sc = col - col % 3;
    for (int i = sr; i < sr + 3; i++)
    {
        for (int j = sc; j < sc + 3; j++)
        {
            if (board[i][j] == num)
                return false;
        }
    }
    return true;
}
bool solveboard(int board[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
            {
                for (int num = 1; num < 10; num++)
                {
                    if (isValid(board, i, j, num))
                    {
                        board[i][j] = num;
                        if (solveboard(board))
                        {
                            return true;
                        }
                        board[i][j] = 0; // backtrace
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void printBoard(int board[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
            if ((j + 1) % 3 == 0)
                cout << "| ";
        }
        if ((i + 1) % 3 == 0)
        {
            cout << endl
                 << "--------------------------" << endl;
        }
        else
        {
            cout << endl;
        }
    }
}
int main()
{
    int board[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    printBoard(board);
    if (solveboard(board))
    {
        cout << endl
             << "Solved" << endl;
        printBoard(board);
    }
    else
    {
        cout << endl
             << "No solution available";
    }
    return 0;
}
