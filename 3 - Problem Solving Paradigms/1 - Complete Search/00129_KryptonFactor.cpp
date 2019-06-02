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

int n, l, counter, ans[110];

bool solve(int curr)
{
    if (counter++ == n)
    {
        rep(i, curr)
        {
            if (i && i % (4 * 16) == 0) cout << endl;
            else if (i && i % 4 == 0) cout << " ";
            cout << (char)(ans[i] + 'A');
        }
        cout << endl << curr << endl;
        return true;
    }

    rep(i, l)
    {
        ans[curr] = i;
        bool noRepetition = true;
        for (int j = 1; 2 * j < curr + 2; j++)
        {
            bool allSame = true;
            rep(k, j)
                if (ans[curr - k] != ans[curr - k - j])
                    allSame = false;
            if (allSame)
            {
                noRepetition = false;
                break;
            }
        }
        if (noRepetition && solve(curr + 1)) return true;
    }

    return false;
}

int main()
{
    while (1)
    {
        cin >> n >> l;
        if (!n && !l) break;

        memset(ans, 0, sizeof ans);
        counter = 0;
        solve(0);
    }

    // failed version of iteration
    /*while (1)
    {
        int n, l; cin >> n >> l;
        if (!n && !l) break;

        string str = "";
        rep(i, n)
        {
            rep(j, l)
            {
                str += 'A' + j;
                bool repetition = false;
                for (int k = 1; i+1 - k - k >= 0; k++)
                    if (str.substr(i+1 - k) == str.substr(i+1 - k - k, k))
                        repetition = true;
                if (!repetition) break;
                str.resize(str.size() - 1);
            }
            D(str);
        }
        rep(i, n)
        {
            if (i % (4 * 16) == 0) cout << endl;
            else if (i % 4 == 0) cout << " ";
            cout << str[i];
        }
        cout << str.size() << endl;
    }*/

    return 0;
}
