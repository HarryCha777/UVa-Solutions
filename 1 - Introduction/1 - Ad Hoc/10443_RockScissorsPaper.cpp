//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <sstream>
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
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define D(x) cout << #x " is " << x << endl
#define INF 1000000000
#define pb push_back
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int r, c;
bool inBounds(int a, int b) { return 0 <= a && a < r && 0 <= b && b < c; }
bool canWin(char a, int b) { return a == 'R' && b == 'S' || a == 'S' && b == 'P' || a == 'P' && b == 'R'; }

int main()
{
    int T; cin >> T;
    while (T--)
    {
        int n; cin >> r >> c >> n;
        vector<vi> map(110, vi(110)), nextMap(110, vi(110));
        rep(i, r)
        {
            string s; cin >> s;
            rep(j, s.size())
                map[i][j] = s[j];
        }
        nextMap = map;

        rep(a, n)
        {
            rep(i, r)
                rep(j, c)
                {
                    char ch = map[i][j];
                    if (inBounds(i+1, j) && canWin(ch, map[i+1][j])) nextMap[i+1][j] = ch;
                    if (inBounds(i-1, j) && canWin(ch, map[i-1][j])) nextMap[i-1][j] = ch;
                    if (inBounds(i, j+1) && canWin(ch, map[i][j+1])) nextMap[i][j+1] = ch;
                    if (inBounds(i, j-1) && canWin(ch, map[i][j-1])) nextMap[i][j-1] = ch;
                }
            map = nextMap;
        }
        rep(i, r)
        {
            rep(j, c)
                cout << (char)map[i][j];
            cout << endl;
        }
        if (T) cout << endl;
    }

    return 0;
}

/*
RSPR
SPRS
PRSP
 |
 V
RRSP
RSPR
SPRS
 |
 V
RRRS
RRSP
RSPR
*/
