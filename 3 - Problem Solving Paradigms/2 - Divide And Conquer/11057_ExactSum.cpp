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
    int n;
    while (cin >> n)
    {
        vi vec(n); rep(i, n) cin >> vec[i]; sort(vec.begin(), vec.end());
        int p; cin >> p;

        vector<pair<int, ii>> ans(0);
        rep(i, n)
            if (binary_search(vec.begin() + i, vec.end(), p - vec[i]))
            {
                int j = lower_bound(vec.begin() + i, vec.end(), p - vec[i]) - vec.begin();
                ans.pb(make_pair(abs(vec[i] - vec[j]), ii(vec[i], vec[j])));
            }
        sort(ans.begin(), ans.end());
        printf("Peter should buy books whose prices are %d and %d.\n\n", ans[0].S.F, ans[0].S.S);
    }

    return 0;
}
