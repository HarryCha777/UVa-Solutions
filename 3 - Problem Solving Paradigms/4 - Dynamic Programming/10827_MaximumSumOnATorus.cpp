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

int main()
{
    int T; cin >> T;
    while (T--)
    {
        int n; cin >> n;
        vector<vi> map(n*n, vi(n*2, 0));
        rep(i, n)
        {
            rep(j, n)
                cin >> map[i][j];
            rep(j, n)
                map[i][j + n] = map[i][j];
        }
        rep(i, n)
            rep(j, n)
                map[i + n][j] = map[i][j],
                map[i + n][j + n] = map[i][j];

        //rep(i, n*2)
        //    rep(j, n*2)
        //        cout << map[i][j] << "\t\n"[j == n * 2 - 1];

        rep(i, n*2)
            rep(j, n*2)
            {
                if (i) map[i][j] += map[i - 1][j];
                if (j) map[i][j] += map[i][j - 1];
                if (i && j) map[i][j] -= map[i - 1][j - 1];
            }

        int maxSum = -INF;
        rep(i, n*2)
            rep(j, n*2)
                for (int k = i; k < n * 2; k++)
                    for (int l = j; l < n * 2; l++)
                        if (k - i < n && l - j < n)
                        {
                            int currSum = map[k][l];
                            if (i) currSum -= map[i - 1][l];
                            if (j) currSum -= map[k][j - 1];
                            if (i && j) currSum += map[i - 1][j - 1];
                            maxSum = max(maxSum, currSum);
                        }
        cout << maxSum << endl;
    }

    return 0;
}

/*
2
5
1 -1 0 0 -4
2 3 -2 -3 2
4 1 -1 5 0
3 -2 1 -3 2
-3 2 4 1 -4
3
1 2 3
4 5 6
7 8 9
*/
