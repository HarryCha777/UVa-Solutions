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

int n;
vector<vi> adjList;
vi visited, topoSort;

void dfsTopo(int u)
{
    visited[u] = 1;
    rep(i, adjList[u].size())
        if (!visited[adjList[u][i]])
            dfsTopo(adjList[u][i]);
    topoSort.pb(u);
}

int main()
{
    int m;
    while (cin >> n >> m, n || m)
    {
        if (!m)
        {
            cout << 1;
            rep(i, n - 1) cout << " " << i + 2; cout << endl;
            continue;
        }

        adjList.assign(n, vi());
        rep(i, m)
        {
            int a, b; cin >> a >> b; a--, b--;
            adjList[a].pb(b);
        }
        topoSort.clear();
        visited.assign(n, 0);
        rep(i, n)
            if (!visited[i])
                dfsTopo(i);
	    reverse(topoSort.begin(), topoSort.end());
        cout << topoSort[0] + 1;
        rep(i, n - 1) cout << " " << topoSort[i + 1] + 1; cout << endl;
    }

    return 0;
}

/*
5 4
1 2
2 3
1 3
1 5
0 0

1 4 2 5 3
*/
