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
    int T; cin >> T;
    bool firstTime = true;
    while (T--)
    {
        if (!firstTime) cout << endl; firstTime = false;

        int n, t, m; cin >> n >> t >> m;
        vector<int> ansOrder(m, 0);
        queue<int> left, right, leftAnsOrder, rightAnsOrder;
        rep(i, m)
        {
            int arrival; string dir; cin >> arrival >> dir;
            if (dir == "left") left.push(arrival), leftAnsOrder.push(i);
            else right.push(arrival), rightAnsOrder.push(i);
        }

        int currTime = 0;
        bool posLeft = true; // true when currently at left
        while (!left.empty() || !right.empty())
        {
            bool moved = false;
            if (posLeft)
            {
                int carPopulation = 0;
                while (!left.empty() && left.front() <= currTime && carPopulation < n)
                {
                    ansOrder[leftAnsOrder.front()] = currTime + t;
                    leftAnsOrder.pop(); left.pop();
                    carPopulation++;
                    moved = true;
                }
                if (moved) currTime += t, posLeft = 0;
            }
            else
            {
                int carPopulation = 0;
                while (!right.empty() && right.front() <= currTime && carPopulation < n)
                {
                    ansOrder[rightAnsOrder.front()] = currTime + t;
                    rightAnsOrder.pop(); right.pop();
                    carPopulation++;
                    moved = true;
                }
                if (moved) currTime += t, posLeft = 1;
            }

            if (!moved)
            {
                if (!left.empty() && !right.empty())
                {
                    if (left.front() < right.front() && left.front() <= currTime && !posLeft) currTime += t, posLeft = 1;
                    else if (left.front() >= right.front() && right.front() <= currTime && posLeft) currTime += t, posLeft = 0;
                    else currTime = min(left.front(), right.front());
                }
                else if (!left.empty())
                {
                    if (left.front() <= currTime && !posLeft) currTime += t, posLeft = 1;
                    else currTime = left.front();
                }
                else
                {
                    if (right.front() <= currTime && posLeft) currTime += t, posLeft = 0;
                    else currTime = right.front();
                }
            }
        }
        rep(i, m) cout << ansOrder[i] << endl;
    }

    /*
    2
    2 10 10
    0 left
    10 left
    20 left
    30 left
    40 left
    50 left
    60 left
    70 left
    80 left
    90 left

    2 10 3
    10 right
    25 left
    40 left
    */

    return 0;
}
