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

int n, dist[20][20], memo[20][1 << 20];

int tsp(int currPos, int bitmask)
{
    if (bitmask == (1 << (n + 1)) - 1) return dist[currPos][0];
    if (memo[currPos][bitmask] != -1) return memo[currPos][bitmask];

    int ans = 2000000000;
    for (int nextPos = 0; nextPos <= n; nextPos++)
        if (currPos != nextPos && !(bitmask & (1 << nextPos))) // if nextPos not visited yet
            ans = min(ans, dist[currPos][nextPos] + tsp(nextPos, bitmask | (1 << nextPos)));
    return memo[currPos][bitmask] = ans;
}

int main()
{
    int T; cin >> T;
    while (T--)
    {
        int xSize, ySize; cin >> xSize >> ySize; // these 2 variables are uesless.
        int x[20] = {}, y[20] = {}; scanf("%d %d", &x[0], &y[0]);
        scanf("%d", &n); rep(i, n) scanf("%d %d", &x[i+1], &y[i+1]);

        rep(i, n + 1)
            rep(j, n + 1)
                dist[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);

        memset(memo, -1, sizeof memo);
        printf("The shortest path has length %d\n", tsp(0, 1));
    }

    return 0;
}
