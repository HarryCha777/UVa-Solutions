//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <sstream>
using namespace std;

#define INF 1000000000
#define rep(i, n) for (int i = 0; i < n; i++)
#define D(x) cout << #x " is " << x << endl
#define pb push_back
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int r, c;
char board[110][110];
string s;

int dfs(int x, int y, char dir)
{
    int counter = 0;
    rep(i, s.size())
    {
        if (s[i] == 'D')
        {
            if (dir == 'N') dir = 'L';
            else if (dir == 'S') dir = 'O';
            else if (dir == 'L') dir = 'S';
            else if (dir == 'O') dir = 'N';
        }
        else if (s[i] == 'E')
        {
            if (dir == 'N') dir = 'O';
            else if (dir == 'S') dir = 'L';
            else if (dir == 'L') dir = 'N';
            else if (dir == 'O') dir = 'S';
        }
        else if (s[i] == 'F')
        {
            if (dir == 'N' && board[x-1][y] != '#' && x-1 > -1) x--, counter += board[x][y] == '*', board[x][y] = '.';
            else if (dir == 'S' && board[x+1][y] != '#' && x+1 < r) x++, counter += board[x][y] == '*', board[x][y] = '.';
            else if (dir == 'L' && board[x][y+1] != '#' && y+1 < c) y++, counter += board[x][y] == '*', board[x][y] = '.';
            else if (dir == 'O' && board[x][y-1] != '#' && y-1 > -1) y--, counter += board[x][y] == '*', board[x][y] = '.';
        }
        //printf("%d, %d\n", x, y);
    }
    return counter;
}

int main()
{
    while (1)
    {
        int len; cin >> r >> c >> len; if (!r && !c && !len) break;
        memset(board, 0, sizeof board);
        rep(i, r) rep(j, c) cin >> board[i][j];
        cin >> s;
        rep(i, r) rep(j, c) if (board[i][j] == 'N' || board[i][j] == 'S' || board[i][j] == 'L' || board[i][j] == 'O')
        {
            char d = board[i][j];
            board[i][j] = '.',
            cout << dfs(i, j, d) << endl;
        }
    }

    return 0;
}

/*
3 3 2
***
*N*
***
DE
4 4 5
...#
*#O.
*.*.
*.#.
FFEFF
10 10 20
....*.....
.......*..
.....*....
..*.#.....
...#N.*..*
...*......
..........
..........
..........
..........
FDFFFFFFEEFFFFFFEFDF
0 0 0
*/
