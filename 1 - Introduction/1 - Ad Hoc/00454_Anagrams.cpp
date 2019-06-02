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
    int T; cin >> T; cin.ignore(); cin.ignore();
    while (T--)
    {
        vector<string> input(0), s(0), ans(0);
        rep(i, 110)
        {
            input.pb(""); getline(cin, input[i]);
            if (input[i] == "")
            {
                input.erase(input.end());
                break;
            }
        }
        sort(input.begin(), input.end());

        rep(i, input.size())
        {
            string sortedNoSpace = "";
            rep(j, input[i].size())
                if (input[i][j] != ' ')
                    sortedNoSpace += input[i][j];
            sort(sortedNoSpace.begin(), sortedNoSpace.end());
            s.pb(sortedNoSpace);
        }

        rep(i, s.size())
            for (int j = i + 1; j < s.size(); j++)
                if (s[i] == s[j])
                    ans.pb(input[i] + " = " + input[j]);

        sort(ans.begin(), ans.end());
        rep(i, ans.size())
            cout << ans[i] << endl;
        if (T) cout << endl;
    }

    return 0;
}
