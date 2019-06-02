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
    int n;
    while (cin >> n, n)
    {
        int maxSum = 0, currSum = 0;
        rep(i, n)
        {
            int num; cin >> num;
            currSum += num;
            maxSum = max(maxSum, currSum);
            currSum = max(currSum, 0);
        }
        if (maxSum)
            cout << "The maximum winning streak is " << maxSum << "." << endl;
        else
            cout << "Losing streak." << endl;
    }

    return 0;
}
