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

int weights[1000010];

int main()
{
    int T; cin >> T;
    while (T--)
    {
        int R, C, V; cin >> R >> C; V = R * C;

        memset(weights, 0, sizeof weights);
        rep(i, R)
            rep(j, C)
            {
                int w; cin >> w;
                weights[i * C + j] = w;
            }

	    vector<vii> adjList(V, vii());
        rep(i, R)
            rep(j, C)
            {
                int u = i * C + j;
                if (j + 1 < C) adjList[u].pb(ii(u + 1, weights[u + 1]));
                if (j - 1 > -1) adjList[u].pb(ii(u - 1, weights[u - 1]));
                if (i + 1 < R) adjList[u].pb(ii(u + C, weights[u + C]));
                if (i - 1 > -1) adjList[u].pb(ii(u - C, weights[u - C]));
            }
    	vi dist(V, INF); dist[0] = weights[0];
	    priority_queue<ii, vii, greater<ii>> pq; pq.push(ii(weights[0], 0));

    	while (!pq.empty())
    	{
            ii front = pq.top(); pq.pop();
    		int d = front.first, u = front.second;
    		if (d > dist[u]) continue;
    		for (int j = 0; j < adjList[u].size(); j++)
    		{
    			int v = adjList[u][j].first;
    			int w = adjList[u][j].second;
    			if (dist[v] > dist[u] + w)
    				dist[v] = dist[u] + w,
    				pq.push(ii(dist[v], v));
    		}
    	}
        cout << dist[V - 1] << endl;
    }

    return 0;
}

/*
2
4
5
0 3 1 2 9
7 3 4 9 9
1 7 5 5 3
2 3 4 2 5
1
6
0 1 2 3 4 5
*/
