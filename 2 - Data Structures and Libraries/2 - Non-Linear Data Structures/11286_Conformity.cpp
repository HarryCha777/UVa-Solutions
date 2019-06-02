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
    int n;
    while (cin >> n, n)
    {
        map<string, int> m;
        rep(i, n)
        {
            vector<string> s(5); rep(j, 5) cin >> s[j]; sort(s.begin(), s.end());
            string str = ""; rep(j, 5) str += s[j];
            m.find(str) == m.end() ? m[str] = 1 : m[str]++;
        }
        //for (auto it : m) printf("%s %d\n", (it.first).c_str(), it.second); cout << endl;

        int maxPopularity = 0, frosh = 0;
        for (auto it : m)
        {
            if (maxPopularity < it.second)
            {
                maxPopularity = it.second;
                frosh = 0;
            }
            if (maxPopularity == it.second)
            {
                frosh += maxPopularity;
            }
        }
        cout << frosh << endl;
    }

    return 0;
}

/*
3
100 101 102 103 488
100 200 300 101 102
103 102 101 488 100
3
200 202 204 206 208
123 234 345 456 321
100 200 300 400 444
0
*/
