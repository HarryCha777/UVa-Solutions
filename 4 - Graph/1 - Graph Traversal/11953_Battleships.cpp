//#include <bits/stdc++.h>
#include <iostream>
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

int n, grid[110][110], dr[] = {1,0,-1,0}, dc[] = {0,1,0,-1};

bool floodfillBroken(int r, int c, char c1, char c2)
{
    if (r == n || c == n || r == -1 || c == -1 || grid[r][c] == c2) return false;
    bool ret = false;
    if (grid[r][c] == 'x') ret = true;
    grid[r][c] = c2;

    rep(i, 4) ret = max(ret, floodfillBroken(r + dr[i], c + dc[i], c1, c2));
    return ret;
}

void floodfillNormal(int r, int c, char c1, char c2)
{
    if (r == n || c == n || r == -1 || c == -1 || grid[r][c] != c1) return;
    grid[r][c] = c2;

    rep(i, 4) floodfillNormal(r + dr[i], c + dc[i], c1, c2);
}

int main()
{
    int T; cin >> T;
    rep(t, T)
    {
        cin >> n;
        rep(i, n)
        {
            string s; cin >> s;
            rep(j, n) grid[i][j] = s[j];
        }
        int counter = 0;
        rep(i, n) rep(j, n) if (grid[i][j] == '@' && floodfillBroken(i, j, '@', '.')) counter++;
        //for (int i = 0; i < n; i++, cout << endl)
        //    rep(j, n)
        //        cout << (char)grid[i][j] << " ";
        //cout << endl;
        //cout << counter << endl;
        rep(i, n) rep(j, n) if (grid[i][j] == 'x') floodfillNormal(i, j, 'x', '.'), counter++;
        printf("Case %d: %d\n", t + 1, counter);
    }

    return 0;
}

/*
2
4
x...
..x.
@.@.
....
2
..
x.
*/
