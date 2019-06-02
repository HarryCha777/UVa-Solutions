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
        int n, arr[1010]; cin >> n;
        rep(i, n) cin >> arr[i];

        int sum = 0;
        for (int i = 1; i < n; i++)
        {
            int counter = 0;
            rep(j, i)
                counter += arr[j] <= arr[i];
            sum += counter;
        }
        cout << sum << endl;
    }

    return 0;
}
