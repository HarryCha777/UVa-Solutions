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

int a, b, row[10], lineCounter;

bool canBePlaced(int r, int c)
{
    rep(prev, c)
        if (row[prev] == r || abs(row[prev] - r) == abs(prev - c))
            return false;
    return true;
}

void rec(int c)
{
    if (c == 8 && row[b] == a)
    {
        printf("%2d     ", lineCounter++);
        rep(j, 8) cout << " " << row[j] + 1;
        cout << endl;
    }

    rep(r, 8)
    {
        if (c == b && r != a) continue;
        if (canBePlaced(r, c))
            row[c] = r, rec(c + 1);
    }
}

int main()
{
    int T; cin >> T;
    while (T--)
    {
        cin >> a >> b; a--, b--;
        memset(row, 0, sizeof row);
        lineCounter = 1;

        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        rec(0);
        if (T) cout << endl;
    }

    return 0;
}
