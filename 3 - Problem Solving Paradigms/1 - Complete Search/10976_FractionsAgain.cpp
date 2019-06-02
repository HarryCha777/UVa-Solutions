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

string numToStr(int num) { stringstream ss; ss << num; return ss.str(); }

int main()
{
    int k;
    while (cin >> k)
    {
        vector<string> ans(0);
        for (int y = k + 1; y <= 2 * k; y++)
        {
            int x = (k * y) / (y - k);
            if ((k * y) % (y - k) == 0)
                ans.pb("1/" + numToStr(k) + " = 1/" + numToStr(x) + " + 1/" + numToStr(y));
        }
        cout << ans.size() << endl;
        rep(i, ans.size()) cout << ans[i] << endl;
    }

    return 0;
}
