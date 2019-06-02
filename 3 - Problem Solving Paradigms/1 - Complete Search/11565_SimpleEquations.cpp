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
    int T; cin >> T;
    while (T--)
    {
        int A, B, C; cin >> A >> B >> C;
        bool found = false;
        for (int x = -100; x <= 100 && !found; x++)
            for (int y = -100; y <= 100 && !found; y++) if (x != y)
                for (int z = -100; z <= 100 && !found; z++)
                    if (y != x && z != x && z != y
                        && x + y + z == A && x * y * z == B && x * x + y * y + z * z == C)
                    {
                        printf("%d %d %d\n", x, y, z);
                        found = true;
                    }
        if (!found) printf("No solution.\n");
    }
    /*
    2
    1 2 3
    6 6 14
    */

    return 0;
}
