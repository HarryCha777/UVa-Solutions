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
    int n, m;
    while (cin >> n >> m)
    {
        vector<vi> adjList(1000010, vi(0)); // without using adjList, using O(n*m) will be time out.
        rep(i, n)
        {
            int j; cin >> j;
            adjList[j].push_back(i + 1);
        }

        rep(i, m)
        {
            int k, v; cin >> k >> v;
            adjList[v].size() > k - 1 ? cout << adjList[v][k - 1] << endl : cout << 0 << endl;
        }
    }

    return 0;
}
