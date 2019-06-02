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
    while (1)
    {
        int n, m; cin >> n >> m; if (!n && !m) break;
        vector<vi> map(n, vi(m)); rep(i, n) rep(j, m) cin >> map[i][j];
        int q; cin >> q;
        rep(i, q)
        {
            int a, b; cin >> a >> b;
            int maxSide = 0;
            rep(j, n)
            {
                int minIndex = lower_bound(map[j].begin(), map[j].end(), a) - map[j].begin();
                for (int k = maxSide; k < n; k++)
                    if (j + k >= n || minIndex + k >= m || map[j + k][minIndex + k] > b) break;
                    else if (k + 1 > maxSide) maxSide = k + 1;
            }
            cout << maxSide << endl;
        }

        cout << "-\n";
    }

    return 0;
}

// Input:
/*
4 5
13 21 25 33 34
16 21 33 35 35
16 33 33 45 50
23 51 66 83 93
3
22 90
33 35
20 100
4 4
1 7 9 11
5 8 10 12
7 10 15 17
11 19 30 41
4
6 20
7 9
10 10
13 14
0 0
*/
// Ans:
/*
3
2
4
-
3
1
1
0
-
*/
