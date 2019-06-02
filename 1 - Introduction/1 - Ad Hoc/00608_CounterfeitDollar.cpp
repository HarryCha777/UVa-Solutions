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

string A[3], B[3], C[3];

int weightSide(string s)
{
    if (s == "up") return 1;
    if (s == "down") return -1;
    return 0;
}

bool thisIsAns(char c, bool light)
{
    rep(i, 3)
    {
        int a = 0, b = 0;
        if (A[i].find(c) != string::npos) a = 1;
        if (B[i].find(c) != string::npos) b = 1;
        if (light) a *= -1, b *= -1; // light simply reverses signs of heavy values
        if (a - b != weightSide(C[i])) return false;
    }
    return true;
}

int main()
{
    int T; cin >> T;
    while (T--)
    {
        rep(i, 3) cin >> A[i] >> B[i] >> C[i];
        rep(i, 'Z' - 'A' + 1)
        {
            if (thisIsAns(i + 'A', 0))
            {
                printf("%c is the counterfeit coin and it is heavy.\n", i + 'A');
                break;
            }
            if (thisIsAns(i + 'A', 1))
            {
                printf("%c is the counterfeit coin and it is light.\n", i + 'A');
                break;
            }
        }
    }

    return 0;
}
