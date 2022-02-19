#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define clr(a) memset(a, 0, sizeof(a))
#define sz(x) x.size()
#define rep(n) for (ll i = 0; i < n; i++)
#define repc(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, x, y) for (int i = x; i < y; i++)
#define RANGE(start, step, stop) for (ll i = start; i < stop; i += step)
#define DEC(i, x, y) for (int i = x; i >= y; i--)
#define all(v) v.begin(), v.end()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define alla(a, n) a, a + n

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

const int inf = 1e9 + 7;
const int ten5 = 100000;
const int ten6 = 1000000;

int c[ten6 + 1];
int dp[ten6 + 1];

int solve(int n, int x)
{
  if (x < 0)
  {
    return 0;
  }
  dp[0] = 0;
  FOR(i, 1, x + 1)
  {
    int mn = ten6 + 1;
    FOR(j, 0, n)
    {
      if (i - c[j] >= 0)
      {
        mn = min(dp[i - c[j]] + 1, mn);
      }
    }
    dp[i] = mn;
  }
  if (dp[x] == ten6 + 1)
  {
    return -1; // cannot reach that coin
  }
  return dp[x];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, x;
  cin >> n >> x;
  rep(n)
  {
    cin >> c[i];
  }
  cout << solve(n, x) << endl;
}

// Always consider overflowing (Don't return inside main, because that is considered as runtime error (returning diff than 0))