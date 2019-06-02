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
        priority_queue<int, vector<int>, greater<int>> pq;
        rep(i, n)
        {
            int num; cin >> num;
            pq.push(num);
        }

        int minAns = 0;
        while (pq.size() >= 2)
        {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            pq.push(a+b);
            minAns += a + b;
        }
        cout << minAns << endl;
    }

    return 0;
}
