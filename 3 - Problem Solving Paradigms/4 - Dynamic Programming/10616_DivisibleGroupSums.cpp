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

int n, d, m, memo[210][15][210];
vi a;

int knapsack(int index, int counter, int currVal)
{
    if (counter == m) return currVal == 0;
    if (index == n) return 0;
    if (memo[index][counter][currVal] != -1) return memo[index][counter][currVal];

    return memo[index][counter][currVal] = knapsack(index + 1, counter, currVal) + knapsack(index + 1, counter + 1, (currVal + a[index]) % d);
}

int main()
{
    int q, t = 1;
    while (cin >> n >> q, n && q)
    {
        cout << "SET " << t++ << ":" << endl;
        a.assign(n, 0); rep(i, n) cin >> a[i];
        rep(i, q)
        {
            cin >> d >> m;
            memset(memo, -1, sizeof memo);
            cout << "QUERY " << i + 1 << ": " << knapsack(0, 0, 0) << endl;
        }
    }

    return 0;
}

/*
10 2
1 2 3 4 5 6 7 8 9 10
5 1
5 2
5 1
2 3 4 5 6
6 2
0 0
*/
