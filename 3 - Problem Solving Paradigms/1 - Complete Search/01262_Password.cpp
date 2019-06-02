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

vector<string> one, two, ans;

/*
1
1
1
AYGSU
DOMRA
CPFAS
XBODG
WDYPK
PRXWO
CBOPT
DOSBG
GTRAR
APMMS
WSXNU
EFGHI
*/

void makeAns(string currAns, int c)
{
    if (c == 5)
    {
        ans.pb(currAns);
        return;
    }

    rep(i, 6)
    {
        bool exists = false;
        rep(j, 6)
            if (one[i][c] == two[j][c])
                exists = true;
        if (exists)
            makeAns(currAns + one[i][c], c + 1);
    }
}

int main()
{
    int T; cin >> T;
    while (T--)
    {
        int k; cin >> k;
        one.assign(6, ""); rep(i, 6) cin >> one[i];
        two.assign(6, ""); rep(i, 6) cin >> two[i];

        ans.assign(0, "");
        makeAns("", 0);

        sort(ans.begin(), ans.end());
        ans.erase( unique( ans.begin(), ans.end() ), ans.end() );
        if (k > ans.size())
        {
            cout << "NO" << endl;
            continue;
        }
        cout << ans[k - 1] << endl;
    }

    return 0;
}
