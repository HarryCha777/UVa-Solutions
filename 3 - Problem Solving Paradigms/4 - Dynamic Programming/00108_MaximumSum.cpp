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
    int n; cin >> n;
    vector<vi> map(n, vi(n*2, 0));
    rep(i, n)
        rep(j, n)
            cin >> map[i][j];

    rep(i, n)
        rep(j, n)
        {
            if (i) map[i][j] += map[i - 1][j];
            if (j) map[i][j] += map[i][j - 1];
            if (i && j) map[i][j] -= map[i - 1][j - 1];
        }

    int maxSum = 0;
    rep(i, n)
        rep(j, n)
            for (int k = i; k < n; k++)
                for (int l = j; l < n; l++)
                    if (l - j < n)
                    {
                        int currSum = map[k][l];
                        if (i) currSum -= map[i - 1][l];
                        if (j) currSum -= map[k][j - 1];
                        if (i && j) currSum += map[i - 1][j - 1];
                        maxSum = max(maxSum, currSum);
                    }
    cout << maxSum << endl;

    return 0;
}

/*
4
0 -2 -7  0 9  2 -6  2
-4  1 -4  1 -1
8  0 -2
*/
