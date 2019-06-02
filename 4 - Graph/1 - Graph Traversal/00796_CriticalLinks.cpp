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

int V;
vector<vi> adjList;

vi dfsLow, dfsParent, dfsNum;
vii bridges;
int dfsNumberCounter = 1;
void articulationBridge(int u)
{
	dfsLow[u] = dfsNum[u] = dfsNumberCounter++;
	for (int j = 0; j < adjList[u].size(); j++)
	{
		int v = adjList[u][j];
		if (dfsNum[v] == -1)
		{
			dfsParent[v] = u;
			articulationBridge(v);

			if (dfsLow[v] > dfsNum[u])
                bridges.pb(ii(min(u, v), max(u, v)));
			dfsLow[u] = fmin(dfsLow[u], dfsLow[v]);
		}
		else if (v != dfsParent[u])
			dfsLow[u] = fmin(dfsLow[u], dfsNum[v]);
	}
}


int main()
{
    while(cin >> V)
    {
        adjList.assign(V, vi());
        rep(i, V)
        {
            int u; cin >> u;
            int n; char c; cin >> c >> n >> c;
            rep(j, n)
            {
                int v; cin >> v;
                adjList[u].pb(v);
                adjList[v].pb(u);
            }
        }

        bridges.assign(0, ii(0, 0));
        dfsLow.assign(V, -1);
        dfsNum.assign(V, -1);
        dfsParent.assign(V, -1);
        rep(i, V)
            if (dfsNum[i] == -1)
                articulationBridge(i);

        printf("%d critical links\n", bridges.size());
        sort(bridges.begin(), bridges.end());
        rep(i, bridges.size())
            printf("%d - %d\n", bridges[i].F, bridges[i].S);
        cout << endl;
    }

    return 0;
}

/*
8
0 (1) 1
1 (3) 2 0 3
2 (2) 1 3
3 (3) 1 2 4
4 (1) 3
7 (1) 6
6 (1) 7
5 (0)

0
*/
