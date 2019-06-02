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

/*
3
2
10 10
-5 -5
2
10 -5
10 -5
2
10 -5
-5 10
*/

int main()
{
    int T; cin >> T;
    while (T--)
    {
        int n; cin >> n;
        vector<vi> board(n, vi(n, 0));
        rep(i, n) rep(j, n) cin >> board[i][j];

        int minVal = INF;
        vi colOrder(n); rep(i, n) colOrder[i] = i;
        do
        {
            int currVal = 0;
            rep(i, n) currVal += board[i][colOrder[i]];
            minVal = min(currVal, minVal);
        }
        while (next_permutation(colOrder.begin(), colOrder.end()));
        cout << minVal << endl;
    }

    return 0;
}
