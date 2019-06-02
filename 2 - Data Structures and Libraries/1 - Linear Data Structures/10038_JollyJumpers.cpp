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
        int prev; cin >> prev;
        vector<bool> used(n, 0);
        rep(i, n - 1)
        {
            int num; cin >> num;
            used[abs(num - prev)] = 1;
            prev = num;
        }
        bool jolly = true; for (int i = 1; i <= n - 1; i++) if (!used[i]) jolly = false;
        jolly ? cout << "Jolly\n" : cout << "Not jolly\n";
    }

    return 0;
}
