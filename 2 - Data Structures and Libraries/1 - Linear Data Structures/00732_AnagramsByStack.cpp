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

/*
madam adamm
bahama bahama
long short
eric rice
*/

string a, b;
vector<string> ansList;
void makeAnsList(string currS, string currAns, stack<char> s, int index)
{
    //cout << currS << " " << currAns << endl;
    if (index > a.size() || b.substr(0, currS.size()) != currS) return;
    if (index == a.size() && s.empty() && currS == b)
    {
        ansList.pb(currAns.substr(0, currAns.size() - 1)); // remove last space at end
        return;
    }

    s.push(a[index]);
    makeAnsList(currS, currAns + "i ", s, index + 1);
    s.pop();

    if (!s.empty())
    {
        currS += s.top(); s.pop(); currAns += "o ";
        makeAnsList(currS, currAns, s, index);
    }
}

int main()
{
    while(cin >> a >> b)
    {
        ansList.assign(0, ""); stack<char> s; makeAnsList("", "", s, 0);
        sort(ansList.begin(), ansList.end());
        cout << "[\n"; rep(i, ansList.size()) cout << ansList[i] << endl; cout << "]\n";
    }

    return 0;
}
