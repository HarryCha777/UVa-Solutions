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
    int T; cin >> T; cin.ignore();
    rep(t, T)
    {
        cout << "Case #" << t + 1 << ":" << endl;
        string input, s = ""; getline(cin, input);
        rep(i, input.size())
            if (('a' <= input[i] && input[i] <= 'z') || ('A' <= input[i] && input[i] <= 'Z'))
                s += input[i];

        int dimension = -1;
        rep(i, 101) // note max input size is 10000 chars and sqrt(10000) = 100
            if (i * i == s.size())
                dimension = i;
        if (dimension == -1 || s != string(s.rbegin(), s.rend()))
        {
            cout << "No magic :(" << endl;
            continue;
        }
        cout << dimension << endl;
    }

    return 0;
}

/*
3
sator arepo tenet opera rotas
this sentence is, quite clearly, not a magic square palindrome! but then again, you never know...
muse sun, eve.s e(y)es even use sum.
*/
