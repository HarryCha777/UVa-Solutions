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
    rep(t, T)
    {
        int n, lis = 1, lds = 1; cin >> n;
        vi h(n), w(n), l(n); rep(i, n) cin >> h[i]; rep(i, n) cin >> w[i];
        rep(i, n)
        {
            l[i] = w[i];
            for (int j = 0; j < i; j++)
                if (h[i] > h[j] && l[i] < l[j] + w[i])
                    l[i] = l[j] + w[i];
            lis = max(lis, l[i]);
        }
        //cout << "L: "; rep(i, n) cout << l[i] << " "; cout << endl;

        l.assign(n, 0);
        rep(i, n)
        {
            l[i] = w[i];
            for (int j = 0; j < i; j++)
                if (h[i] < h[j] && l[i] < l[j] + w[i])
                    l[i] = l[j] + w[i];
            lds = max(lds, l[i]);
        }
        //cout << "L: "; rep(i, n) cout << l[i] << " "; cout << endl;

        printf("Case %d. ", t + 1); lis < lds ? printf("Decreasing (%d). Increasing (%d).\n", lds, lis) : printf("Increasing (%d). Decreasing (%d).\n", lis, lds);
    }

    return 0;
}

/*
3
6
10 100 50 30 80 10
50 10 10 15 20 10
4
30 20 20 10
20 30 40 50
3
80 80 80
15 25 20
*/
