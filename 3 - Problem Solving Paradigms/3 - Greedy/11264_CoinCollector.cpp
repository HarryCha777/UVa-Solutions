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
        int n; cin >> n;
        vi vec(n); rep(i, n) cin >> vec[i];

        int sumSoFar = 0, counter = 1;
        rep(i, n - 1)
            if (sumSoFar + vec[i] < vec[i + 1])
            {
                sumSoFar += vec[i];
                counter++;
            }
        cout << counter << endl;
    }

    return 0;
}

/*
2
6
1 2 4 8 16 32
6
1 3 6 8 15 20
*/
