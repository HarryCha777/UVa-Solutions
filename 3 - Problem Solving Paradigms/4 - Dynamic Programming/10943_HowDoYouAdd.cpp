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

int n, k, memo[110][110];

int solve(int counter, int remaining)
{
    if (counter == k - 1) return 1;
    if (memo[counter][remaining] != -1) return memo[counter][remaining];

    int sum = 0;
    rep(i, remaining + 1)
        sum += solve(counter + 1, remaining - i), sum %= 1000000;
    return memo[counter][remaining] = sum;
}

int main()
{
    while (cin >> n >> k, n && k)
        memset(memo, -1, sizeof memo), cout << solve(0, n) << endl;

    return 0;
}
