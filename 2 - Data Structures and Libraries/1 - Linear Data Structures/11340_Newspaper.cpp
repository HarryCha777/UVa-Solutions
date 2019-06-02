//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
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
#define rep(i, n) for (ll i = 0; i < n; i++)
#define D(x) cout << #x " is " << x << endl
#define pb push_back
#define F first
#define S second

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

int main()
{
    ll T; cin >> T;
    while (T--)
    {
        ll n; cin >> n;
        ll cost[260] = {};
        rep(i, n)
        {
            char ch; ll c; cin >> ch >> c;
            cost[ch+128] = c;
        }

        ll m, ans = 0; cin >> m; cin.ignore();
        rep(i, m)
        {
            string s; getline(cin, s);
            rep(j, s.size())
                ans += cost[s[j]+128];
        }
        //cout << fixed << setprecision(2) << ans/100.0 << "$" << endl;
        printf("%lld.%02lld$\n", ans/100, ans%100);
    }

    return 0;
}

/*
1
7
a 3
W 10
A 100
, 10
k 7
. 3
I 13
7
ACM International Collegiate Programming Contest (abbreviated
as ACM-ICPC or just ICPC) is an annual multi-tiered competition
among the universities of the world. The ICPC challenges students
to set ever higher standards of excellence for themselves
through competition that rewards team work, problem analysis,
and rapid software development.
From Wikipedia.
*/
