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
        if (!n)
        {
            cout << 0 << endl;
            continue;
        }
        int a[2010]={}, lis[2010]={}, lds[2010]={}; rep(i, n) cin >> a[i];

        for (int i = n - 1; i >= 0; i--)
        {
            lis[i] = 1;
            for (int j = i + 1; j < n; j++)
                if (a[j] > a[i] && lis[i] < lis[j] + 1)
                    lis[i] = lis[j] + 1;
        }
        //rep(i, n) cout << lis[i] << " "; cout << endl;

        for (int i = n - 1; i >= 0; i--)
        {
            lds[i] = 1;
            for (int j = i + 1; j < n; j++)
                if (a[j] < a[i] && lds[i] < lds[j] + 1)
                    lds[i] = lds[j] + 1;
        }
        //rep(i, n) cout << lds[i] << " "; cout << endl;

        int ans = 1; rep(i, n) ans = max(ans, lis[i] + lds[i] - 1);
        cout << ans << endl;
    }

    return 0;
}

// 1 15    10 3 13 1 4 9 8 12 6 14 5 7 2 0 11
