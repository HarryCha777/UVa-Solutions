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
    int r, c;
    while (scanf("%d %d", &r, &c), (r || c))
    {
        // Notice that knights placed in black square can only attack white squares and vice versa.
        int ans;
        if (!r || !c) ans = 0;
        else if (r == 1 || c == 1) ans = max(r, c);
        else if (r == 2 || c == 2)
        {
            int k = max(r, c);
            int C = (k % 4 == 0) ? k / 4 : (k / 4) + 1;
            int D = ((k - 1) % 4 == 0) ? (k - 1) / 4 : ((k - 1) / 4) + 1;
            ans = 2 * (C + D);
        }
        else ans = ((r * c) %2 == 0) ? (r * c) / 2 : ((r * c + 1) / 2);

        printf("%d knights may be placed on a %d row %d column board.\n", ans, r, c);
    }

    return 0;
}
