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

ll sieveSize;
bitset<110> bs; // this is same as bool array with size 110
vi primeList; // list of primes

// initialize bs and primeList
void sieve(ll upperbound) // create a list of primes in [0..upperbound]
{
	sieveSize = upperbound + 1; // add 1 to include upperbound
	bs.set(); bs[0] = bs[1] = 0; // set all bits to 1 except index 0 and 1
	for (ll i = 2; i <= sieveSize; i++) if (bs[i])
	{
		// cross out multiples of i starting from i * i!
		for (ll j = i * i; j <= sieveSize; j += i) bs[j] = 0;
		primeList.push_back((int)i); // also add this vector containing list of primes
	}
}

bool isPrime(ll N) // checking if a number is prime quickly
{
	if (N <= sieveSize) return bs[N]; // O(1) for small primes
	for (int i = 0; i < primeList.size(); i++)
		if (N % primeList[i] == 0) return false;
	return true; // it takes longer time if N is a large prime
} // note: only work for N <= (last prime in vi "primeList")^2

int n;
vector<vi> ans;

void makeAns(vi currAns, int bitmaskUsed)
{
    if (currAns.size() == n)
    {
        if (isPrime(1 + currAns[currAns.size() - 1]))
            ans.pb(currAns);
        return;
    }

    for (int i = 2; i <= n; i++)
        if (!(bitmaskUsed & (1 << i)) && isPrime(currAns[currAns.size() - 1] + i))
        {
            bitmaskUsed |= (1 << i);
            currAns.pb(i);
            makeAns(currAns, bitmaskUsed);
            bitmaskUsed &= ~(1 << i);
            currAns.pop_back();
        }
}

int main()
{
    sieve(100);

    int caseCounter = 1;
    while (cin >> n)
    {
        if (caseCounter > 1) cout << endl;
        ans.assign(0, vi(0));

        int bitmaskStart = 0; bitmaskStart |= (1 << 1);
        makeAns(vi(1, 1), bitmaskStart);

        printf("Case %d:\n", caseCounter++);
        for (int i = 0; i < ans.size(); i++, cout << endl)
        {
            cout << ans[i][0];
            for (int j = 1; j < ans[i].size(); j++)
                printf(" %d", ans[i][j]);
        }
    }

    return 0;
}
