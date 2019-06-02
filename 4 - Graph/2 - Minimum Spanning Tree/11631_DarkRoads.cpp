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

vi r, p, setSize; // r is used to keep tree short. r meaning: "rank," p meaning: "parent."
int findSet(int i) { if (p[i] == i) return i; return p[i] = findSet(p[i]); }
void connect(int a, int b)
{
	if (r[a] > r[b]) p[b] = a, setSize[a] += setSize[b];
	else if (r[a] < r[b]) p[a] = b, setSize[b] += setSize[a];
	else p[a] = b, r[b]++, setSize[b] += setSize[a];
}

int main()
{
    while (1)
    {
        int V, E; scanf("%d %d", &V, &E);
        if (!V && !E) break;

        ll total = 0;
        vector< pair<int, ii> > edges; // vector of (weight, (vertex 1, vertex 2))
        for (int i = 0; i < E; i++)
        {
            int u, v, w; scanf("%d %d %d", &u, &v, &w);
            edges.push_back(make_pair(w, ii(u, v)));
            total += w;
        }
        sort(edges.begin(), edges.end());

        r.assign(V, 0);
        p.assign(V, 0); for (int i = 1; i < V; i++) p[i] = i;
        setSize.assign(V, 1);

        int numSets = V;
        ll minCost = 0;
        for (int i = 0; i < edges.size() && 1 < numSets; i++)
        {
            pair<int, ii> front = edges[i];
            int a = findSet(front.second.first);
            int b = findSet(front.second.second);
            if (a != b) minCost += front.first, connect(a, b), numSets--;
        }
        cout << total - minCost << endl;
    }

    return 0;
}
