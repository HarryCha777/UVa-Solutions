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
        vector<pair<string, ii>> vec(n);
        rep(i, n) cin >> vec[i].F >> vec[i].S.F >> vec[i].S.S;
        int m; cin >> m;
        rep(i, m)
        {
            int num; cin >> num;
            int makerNum  = 0, k;
            rep(j, n)
                if (vec[j].S.F <= num && num <= vec[j].S.S)
                    makerNum++, k = j;
            makerNum == 1 ? cout << vec[k].F << endl : cout << "UNDETERMINED" << endl;
        }
        if (T) cout << endl;
    }
    /*
    1
    4
    H 10000 45000
    P 12000 44000
    B 30000 75900
    C 7000 37000
    4
    60000
    B
    7500
    C
    5000
    UNDETERMINED
    10000
    UNDETERMINED
    */

    return 0;
}
