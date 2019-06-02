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
    for (int t = 1; ; t++)
    {
        int n, m; cin >> n >> m; if (!n && !m) break;
        vi b(n), s(m); rep(i, n) cin >> b[i]; rep(i, m) cin >> s[i];
        int minB = INF; rep(i, n) minB = min(minB, b[i]);

        if (n > m) printf("Case %d: %d %d\n", t, n - m, minB);
        else printf("Case %d: 0\n", t);

        // below code is all unnecessary!
        /*sort(b.begin(), b.end()); sort(s.begin(), s.end());
        bool used[10010] = {};

        int i;
        for (i = n - 1; i >= 0; i--)
        {
            int nearestVal = INF, nearestIndex = -1;
            rep(j, m)
                if (!used[j] && nearestVal > abs(b[i] - s[j]))
                {
                    nearestVal = abs(b[i] - s[j]);
                    nearestIndex = j;
                }

            if (nearestVal == INF)
            {
                printf("Case %d: %d %d\n", t, i + 1, b[0]);
                break;
            }
            else
            {
                used[nearestIndex] = 1;
            }
        }

        if (i == -1)
            printf("Case %d: 0\n", t);*/
    }

    return 0;
}

/*
4 4
26
25
2
21
35
25
23
24
1 2
20
30
40
4 2
5
5
10
15
20
18
0 0
*/
