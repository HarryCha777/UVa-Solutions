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
        int n, d, r; cin >> n >> d >> r; if (!n && !d && !r) break;
        vi morning(n), afternoon(n); rep(i, n) cin >> morning[i]; rep(i, n) cin >> afternoon[i];
        sort(morning.begin(), morning.end());
        sort(afternoon.rbegin(), afternoon.rend());

        int cost = 0;
        rep(i, n)
            if (morning[i] + afternoon[i] > d)
                cost += morning[i] + afternoon[i] - d;
        cout << cost * r << endl;
    }

    return 0;
}

/*
2 20 5
10 15
10 15
2 20 5
10 10
10 10
*/
