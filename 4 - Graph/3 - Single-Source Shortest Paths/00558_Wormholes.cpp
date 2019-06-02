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
    while (T--)
    {
        int V, E; scanf("%d %d", &V, &E);
    	vector<vii> adjList(V, vii());
    	for (int i = 0; i < E; i++)
    	{
    		int u, v, w; scanf("%d %d %d", &u, &v, &w);
    		adjList[u].push_back(ii(v, w));
    	}

    	int s = 0;
    	vi dist(V, INF);
    	dist[s] = 0;

    	for (int i = 0; i < V - 1; i++)
    		for (int u = 0; u < V; u++)
    			for (int j = 0; j < adjList[u].size(); j++)
    			{
    				int v = adjList[u][j].first;
    				int w = adjList[u][j].second;
    				dist[v] = min(dist[v], dist[u] + w);
    			}

    	bool hasNegCycle = false;
    	for (int u = 0; u < V; u++)
    		for (int j = 0; j < adjList[u].size(); j++)
    		{
    			int v = adjList[u][j].first;
    			int w = adjList[u][j].second;
    			if (dist[v] > dist[u] + w)
    				hasNegCycle = true;
    		}

    	hasNegCycle ? printf("possible\n") : printf("not possible\n");
    }

    return 0;
}

/*
2
3 3
0 1 1000
1 2 15
2 1 -42
4 4
0 1 10
1 2 20
2 3 30
3 0 -60

*/
