![cp3](https://user-images.githubusercontent.com/36347727/58930361-ce7bf480-870f-11e9-820b-80187182413c.jpg)
![white square](https://user-images.githubusercontent.com/36347727/58930541-b22c8780-8710-11e9-9201-b3452bc7d7c0.jpg)
![uva3](https://user-images.githubusercontent.com/36347727/58930451-49450f80-8710-11e9-9fbb-73ba4163ef32.png)

# UVa-Solutions
These are my C++ solutions to UVa Online Judge problems listed in the book Competitive Programming 3 by Steven Halim.

All solutions in this repository are accepted.

Example: Chapter 4: Graph - Minimum Spanning Tree - 11631_DarkRoads.cpp
```javascript
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
```
---

Link to UVa Online Judge: https://uva.onlinejudge.org

Link to my UVa uHunt: https://uhunt.onlinejudge.org/id/826591

Link to companion website of Competitive Programming 3: https://cpbook.net

# Contact
Please reach out to me through this email address:    harrycha777@gmail.com

# License
This project is under no license.
