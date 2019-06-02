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
    bool firstTime = 1;
    while (1)
    {
        int n; cin >> n; if (!n) break;
        if (!firstTime) cout << endl; firstTime = 0;
        int A[50] = {};
        rep(i, n) cin >> A[i];

        rep(a, n)
        for (int b = a + 1; b < n; b++)
        for (int c = b + 1; c < n; c++)
        for (int d = c + 1; d < n; d++)
        for (int e = d + 1; e < n; e++)
        for (int f = e + 1; f < n; f++)
            printf("%d %d %d %d %d %d\n", A[a], A[b], A[c], A[d], A[e], A[f]);
    }

    return 0;
}
