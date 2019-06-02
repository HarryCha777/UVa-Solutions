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
    int a, b;
    while (cin >> a >> b, a || b)
    {
        set<int> s;
        rep(i, a)
        {
            int num; cin >> num;
            s.insert(num);
        }
        int counter = 0;
        rep(i, b)
        {
            int num; cin >> num;
            if (s.find(num) != s.end()) counter++;
        }
        cout << counter << endl;
    }

    return 0;
}
