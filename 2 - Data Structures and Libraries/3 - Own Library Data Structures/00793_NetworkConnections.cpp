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

vi r, p;
int findSet(int i) { if (p[i] == i) return i; return p[i] = findSet(p[i]); }
void connect(int a, int b)
{
	if (r[a] > r[b]) p[b] = a;
	else if (r[a] < r[b]) p[a] = b;
	else p[a] = b, r[b]++;
}
int strToInt(string str) { int num; stringstream ss(str); ss >> num; return num; }

/*
2

10
c 1 5
c 2 7
q 7 1
c 3 9
q 9 6
c 2 5
q 7 5

1
q 1 1
c 1 1
q 1 1
*/

int main()
{
    int T; scanf("%d\n", &T);
    while (T--)
    {
        int V; scanf("%d\n\n", &V);
	    r.assign(V + 10, 0); // + 10 is necessary
	    p.assign(V + 10, 0); for (int i = 1; i < V; i++) p[i] = i; // + 10 is necessary
        int yes = 0, no = 0;

        while (1)
        {
            string line; getline(cin, line);
            if (line.empty()) break;

            int index = 2; while (line[index] != ' ') index++;
            string strA = line.substr(2, index - 2), strB = line.substr(index + 1);
            int a = strToInt(strA), b = strToInt(strB);
            if (line[0] == 'c')
            {
        		int x = findSet(a), y = findSet(b);
        		if (x != y) connect(x, y);
            }
            else
            {
                findSet(a) == findSet(b) ? yes++ : no++;
            }
        }

        printf("%d,%d\n", yes, no);
		if (T) cout << endl;
    }

    return 0;
}
