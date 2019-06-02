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

vi vec;
bool possible(int k)
{
    rep(i, vec.size() - 1)
    {
        if (vec[i + 1] - vec[i] > k) return false;
        else if (vec[i + 1] - vec[i] == k) k--;
    }
    return true;
}

int main()
{
    int T; cin >> T;
    rep(t, T)
    {
        int n; cin >> n;
        vec.assign(n+1, 0); rep(i, n) cin >> vec[i+1];

        int high = 10000010, low = 0, mid;
        while (high - low > 1)
        {
            mid = (high + low) / 2;
            if (possible(mid)) high = mid;
            else low = mid;
        }
        if (!possible(mid)) mid++;
        printf("Case %d: %d\n", t + 1, mid);
    }

    return 0;
}

/*
2
5
1 6 7 11 13
4
3 9 10 14
*/
