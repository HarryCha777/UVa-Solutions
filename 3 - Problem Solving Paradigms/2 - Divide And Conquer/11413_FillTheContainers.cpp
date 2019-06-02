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

int n, m;
vi vec;

bool possible(int mid)
{
    int containers = 0, capacity = mid;
    rep(i, n)
    {
        if (vec[i] > mid) return false;
        if (vec[i] > capacity)
        {
            containers++;
            if (containers == m) return false;
            capacity = mid;
        }
        capacity -= vec[i];
    }
    return true;
}

int main()
{
    while (cin >> n >> m)
    {
        vec.assign(n, 0); rep(i, n) cin >> vec[i];
        int high = 1000000000, low = 0, mid;
        while (high - low > 1)
        {
            mid = (high + low) / 2;
            if (possible(mid)) high = mid;
            else low = mid;
        }
        if (!possible(mid)) mid++;
        cout << mid << endl;
    }

    return 0;
}
