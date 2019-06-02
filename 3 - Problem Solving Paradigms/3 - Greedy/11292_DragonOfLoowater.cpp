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
        int n, m; cin >> n >> m; if (!n && !m) break;
        vi heads(n), knights(m); rep(i, n) cin >> heads[i]; rep(i, m) cin >> knights[i];
        sort(heads.begin(), heads.end()); sort(knights.begin(), knights.end());

        int headsI = 0, knightsI = 0, cost = 0;
        for (; headsI < n; headsI++)
        {
            while (knightsI < m && knights[knightsI] < heads[headsI]) knightsI++;
            if (knightsI == m) break;
            cost += knights[knightsI++];
        }
        if (headsI == n) cout << cost << endl;
        else cout << "Loowater is doomed!" << endl;
    }

    return 0;
}

/*
2 3
5
4
7
8
4
2 1
5
5
10
0 0
*/
