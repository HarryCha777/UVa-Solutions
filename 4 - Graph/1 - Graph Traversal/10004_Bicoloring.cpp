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
    int n;
    while (cin >> n, n)
    {
        int m; cin >> m;
        vector<vi> adjList(n, vi());
        rep(i, m)
        {
            int a, b; cin >> a >> b;
            adjList[a].pb(b);
            adjList[b].pb(a);
        }

        int s = 0;
        queue<int> q; q.push(s);
        vi dist(n, INF); dist[s] = 0;
        bool isBipartite = true;

        while (!q.empty())
        {
            int u = q.front(); q.pop();
            rep(j, adjList[u].size())
            {
                int v = adjList[u][j];
                if (dist[v] == INF)
                {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
                else if ((dist[u] % 2) == (dist[v] % 2))
                    isBipartite = false;
            }
        }
        isBipartite ? cout << "BICOLORABLE.\n" : cout << "NOT BICOLORABLE.\n";
    }

    return 0;
}

/*
3
3
0 1
1 2
2 0
3
2
0 1
1 2
9
8
0 1
0 2
0 3
0 4
0 5
0 6
0 7
0 8
0
*/
