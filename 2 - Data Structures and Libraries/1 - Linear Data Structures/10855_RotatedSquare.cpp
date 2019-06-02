//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <sstream>
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
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define D(x) cout << #x " is " << x << endl
#define INF 1000000000
#define pb push_back
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main()
{
    bool firstTime = true;
    while (1)
    {
        if (!firstTime) cout << endl; firstTime = false;
        int N, n; cin >> N >> n; if (!N) break;
        vector<string> big(N, ""), small(n, "");
        rep(i, N) cin >> big[i];
        rep(i, n) cin >> small[i];

        rep(a, 4)
        {
            //rep(i, n)
            //    rep(j, n)
            //        cout << small[i][j] << "\n"[j == n - 2];
            //cout << endl;

            int counter = 0;
            rep(i, N - n + 1)
                rep(j, N - n + 1)
                {
                    bool same = true;
                    rep(k, n)
                        rep(l, n)
                            if (big[i+k][j+l] != small[k][l])
                                same = false;
                    counter += same;
                }
            if (a != 0) cout << " ";
            cout << counter;

            vector<string> newSmall = small; // this is for newSmall to have same string length of n as small
            rep(i, n)
                rep(j, n)
                    newSmall[i][j] = small[n-1-j][i];
            small = newSmall;
        }
    }

    return 0;
}
