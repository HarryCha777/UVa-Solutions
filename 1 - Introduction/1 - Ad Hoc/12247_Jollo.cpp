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
    while (true)
    {
        vi princess(3); cin >> princess[0] >> princess[1] >> princess[2]; sort(princess.begin(), princess.end());
        int x, y; cin >> x >> y;
        bool used[60] = {}; used[princess[0]] = used[princess[1]] = used[princess[2]] = used[x] = used[y] = 1;

        if (!princess[0]) break;
        if (princess[2] > max(x, y) && princess[1] > min(x, y)) // prince stands no chance
        {
            cout << -1 << endl;
            continue;
        }
        if (princess[2] < min(x, y) && princess[1] < min(x, y) && princess[2] < max(x, y) && princess[1] < max(x, y)) // princess stands no chance
        {
            for (int j = 1; ; j++)
                if (!used[j])
                {
                    cout << j << endl;
                    break;
                }
            continue;
        }

        // win with prince's high card
        rep(i, 3)
            if (princess[i] < max(x, y))
            {
                princess[i] = 100;
                break;
            }
        //rep(i, 3) cout << princess[i] << " "; cout << endl;

        // lose with prince's low card
        rep(i, 3)
            if (princess[i] != 100 && princess[i] > min(x, y))
            {
                princess[i] = 100;
                break;
            }
        //rep(i, 3) cout << princess[i] << " "; cout << endl << endl;

        rep(i, 3)
            if (princess[i] != 100)
                for (int j = princess[i] + 1; ; j++)
                    if (j == 53)
                    {
                        cout << -1 << endl;
                        break;
                    }
                    else if (!used[j])
                    {
                        cout << j << endl;
                        break;
                    }
    }

    return 0;
}
