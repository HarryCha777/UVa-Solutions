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
    int n;
    while (cin >> n)
    {
        vector<vi> map(n, vi(n));
        rep(i, n)
        {
            string s; cin >> s;
            rep(j, n)
                map[i][j] = s[j] - '0';
        }

        int ans = 0;
        rep(a, n)
            rep(b, n)
                if (map[a][b] == 1)
                {
                    int minDist = INF;
                    rep(c, n)
                        rep(d, n)
                            if (map[c][d] == 3)
                            {
                                int dist = abs(a - c) + abs(b - d);
                                minDist = min(minDist, dist);
                            }
                    ans = max(ans, minDist);
                }
        cout << ans << endl;
    }

    return 0;
}

/*
4
1223
2123
2213
3212
2
12
33
*/
