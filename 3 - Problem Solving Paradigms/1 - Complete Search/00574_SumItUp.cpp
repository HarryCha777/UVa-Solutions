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

int n, total, A[13];
vector<vi> ans;

void makeAns(int remain, int prevI, vi currAns)
{
    if (remain < 0) return;
    if (!remain)
    {
        ans.pb(currAns);
        return;
    }

    for (int i = prevI + 1; i < n; i++)
    {
        currAns.pb(A[i]);
        makeAns(remain - A[i], i, currAns);
        currAns.pop_back();
    }
}

int main()
{
    while (1)
    {
        cin >> total >> n; if (!total && !n) break;
        rep(i, n) cin >> A[i];

        ans.assign(0, vi(0));
        makeAns(total, -1, vi(0));
        sort(ans.rbegin(), ans.rend());
        ans.erase( unique( ans.begin(), ans.end() ), ans.end() );

        printf("Sums of %d:\n", total);
        if (!ans.size())
            printf("NONE\n");
        else
            rep(i, ans.size())
                rep(j, ans[i].size())
                    cout << ans[i][j] << "+\n"[j == ans[i].size()-1];
    }

    return 0;
}

/*
4 6 4 3 2 2 1 1
5 3 2 1 1
400 12 50 50 50 50 50 50 25 25 25 25 25 25
0 0
*/
