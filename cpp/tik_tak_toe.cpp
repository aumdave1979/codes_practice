#include <bits/stdc++.h>
using namespace std;

void display(int board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << "|";
        }
        cout << endl
             << "------" << endl;
    }
}

void play(int board[3][3])
{
    char ch1, ch2;
    do
    {
        cout << "Player 1 choose the symbol: X/O ? :";
        cin >> ch1;
    } while (ch1 != 'X' && ch1 != 'O');
    if (ch1 == 'X')
    {
        ch2 = 'O';
    }
    else
    {
        ch2 = 'X';
    }

    bool flag = true;
    while (flag)
    {
        int pos;
        cout << "Enter Position player 1: ";
        cin >> pos;
        int i = (pos - 1) / 3;
        int j = (pos - 1) % 3;
        if (board[i][j] == 0)
        {
            board[i][j] = ch1;
            display(board);
        }
    }
}

bool check(int board[3][3], int pos)
{
}

int main()
{
    int board[3][3] = {1};
    display(board);
    int val;
    cout << "Enter 1 to play: ";
    cin >> val;
    if (val == 1)
    {
        play(board);
    }
}