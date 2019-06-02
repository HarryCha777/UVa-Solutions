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
        int V, E, s, d; scanf("%d %d %d %d", &V, &E, &s, &d);
    	vector<vii> adjList(V, vii());
    	for (int i = 0; i < E; i++)
    	{
    		int u, v, w; scanf("%d %d %d", &u, &v, &w);
    		adjList[u].push_back(ii(v, w));
    		adjList[v].push_back(ii(u, w));
    	}

    	vi dist(V, INF);
    	dist[s] = 0;
    	priority_queue<ii, vii, greater<ii>> pq;
    	pq.push(ii(0, s));

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
        dist[d] == INF ?
        printf("Case #%d: unreachable\n", t + 1) :
        printf("Case #%d: %d\n", t + 1, dist[d]);
    }

	return 0;
}
