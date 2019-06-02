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
        int R, C, V; cin >> R >> C; V = R * C;
        if (!R && !C) break;

        int n; cin >> n;
        bool bombs[1000010] = {};
        rep(i, n)
        {
            int r, m; cin >> r >> m;
            rep(j, m)
            {
                int c; cin >> c;
                int u = r * C + c;
                bombs[u] = 1;
            }
        }

	    vector<vi> adjList(V, vi());
        rep(i, R)
            rep(j, C)
            {
                int u = i * C + j;
                if (j + 1 < C  && !bombs[u + 1]) adjList[u].pb(u + 1);
                if (j - 1 > -1 && !bombs[u - 1]) adjList[u].pb(u - 1);
                if (i + 1 < R  && !bombs[u + C]) adjList[u].pb(u + C);
                if (i - 1 > -1 && !bombs[u - C]) adjList[u].pb(u - C);
            }

        int sr, sc, s; cin >> sr >> sc; s = sr * C + sc;
        int dr, dc, d; cin >> dr >> dc; d = dr * C + dc;
    	vi dist(V, INF); dist[s] = 0;
    	queue<int> q; q.push(s);

    	while (!q.empty())
    	{
    		int u = q.front(); q.pop();
    		for (int j = 0; j < adjList[u].size(); j++)
    		{
    			int v = adjList[u][j];
    			if (dist[v] == INF)
    				dist[v] = dist[u] + 1,
    				q.push(v);
    		}
    	}
        cout << dist[d] << endl;
    }

    return 0;
}

/*
10 10
9
0 1 2
1 1 2
2 2 2 9
3 2 1 7
5 3 3 6 9
6 4 0 1 2 7
7 3 0 3 8
8 2 7 9
9 3 2 3 4
0 0
9 9
0 0
*/
