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
        int n; cin >> n;
        string s; cin >> s;

        int counter = 0;
        rep(i, n)
            if (s[i] == '.')
                i+=2, counter++;

        printf("Case %d: %d\n", t + 1, counter);
    }

    return 0;
}

/*
3
3
.#.
11
...##....##
2
##
*/
