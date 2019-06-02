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

int n, ans;
vi ansList;
vector<vi> adjList;
bitset<110> bs;

/*
1
6 8
1 2
1 3
2 4
2 5
3 4
3 6
4 6
5 6
*/

void solve(int curr)
{
    rep(i, n)
        if (bs[i])
            rep(j, adjList[i].size())
                if (bs[adjList[i][j]])
                    return;

    if (curr == n)
    {
        int currAns = 0; vi currAnsList(0);
        rep(i, n)
            if (bs[i])
                currAns++, currAnsList.pb(i + 1);

        if (currAns > ans)
        {
            ans = currAns;
            ansList = currAnsList;
        }
        return;
    }

    solve(curr + 1);
    bs[curr] = 1;
    solve(curr + 1);
    bs[curr] = 0;
}

int main()
{
    int m; cin >> m;
    while (m--)
    {
        int k; cin >> n >> k;
        adjList.assign(n, vi());
        rep(i, k)
        {
            int u, v; cin >> u >> v; u--, v--;
            adjList[u].pb(v);
            adjList[v].pb(u);
        }

        ans = 0;
        bs.reset();
        ansList.assign(0, 0);
        solve(0);
        
        cout << ans << endl;
        rep(i, ans)
        {
            cout << ansList[i];
            if (i < ans - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
