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

/*
4
25
4
10 12 5 7
925
10
45 15 120 500 235 58 6 12 175 70
120
5
25 25 25 25 25
0
2
13 567
*/
int main()
{
    int T; cin >> T;
    while (T--)
    {
        int n, p, arr[30], sum = 0; cin >> n >> p;
        rep(i, p) cin >> arr[i];
        rep(i, (1 << p))
        {
            sum = 0;
            rep(j, p)
                if (i & (1 << j))
                    sum += arr[j];
            //D(sum);
            if (sum == n) break;
        }
        sum == n ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}
