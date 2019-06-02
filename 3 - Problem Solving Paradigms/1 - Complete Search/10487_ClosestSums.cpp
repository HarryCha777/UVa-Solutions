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
    for (int t = 1; ; t++)
    {
        int n, arr[1010]; cin >> n; if (!n) break;
        rep(i, n) cin >> arr[i];

        printf("Case %d:\n", t);
        int m; cin >> m;
        rep(i, m)
        {
            int closest = 2000000000, v; cin >> v;
            rep(j, n)
                for (int k = j + 1; k < n; k++)
                {
                    int sum = arr[j] + arr[k];
                    if (arr[j] != arr[k] && abs(v - sum) < abs(v - closest))
                        closest = sum;
                }
            printf("Closest sum to %d is %d.\n", v, closest);
        }
    }
    /*
    5
    3
    12
    17
    33
    34
    3
    1
    51
    30
    3
    1
    2
    3
    3
    1
    2
    3
    3
    1
    2
    3
    3
    4
    5
    6
    0
    */

    return 0;
}
