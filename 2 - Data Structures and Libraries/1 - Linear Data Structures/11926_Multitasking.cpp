//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <sstream>
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
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define D(x) cout << #x " is " << x << endl
#define INF 1000000000
#define pb push_back
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main()
{
    int n, m;
    while (cin >> n >> m, n || m)
    {
        bitset<1000200> bs;
        int a[110], b[110]; rep(i, n) cin >> a[i] >> b[i];
        int x[110], y[110], z[110]; rep(i, m) cin >> x[i] >> y[i] >> z[i];
        bool conflict = false;

        rep(i, n)
            for (int j = a[i]; j < b[i]; j++)
                if (bs[j])
                {
                    conflict = 1;
                    break;
                }
                else
                    bs[j] = 1;
        if (conflict)
        {
            cout << "CONFLICT\n";
            continue;
        }

        rep(i, m)
        {
            for (int r = 0; ; r++)
            {
                if (conflict || y[i] + r*z[i] > 1000000) break;
                for (int j = x[i]; j < y[i]; j++)
                    if (bs[j + r*z[i]])
                    {
                        conflict = 1;
                        break;
                    }
                    else
                        bs[j + r*z[i]] = 1;
            }
            if (conflict)
            {
                cout << "CONFLICT\n";
                break;
            }
        }
        if (conflict) continue;
        cout << "NO CONFLICT\n";
    }

    return 0;
}
