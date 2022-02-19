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

int dp[1001][1001];

int solve(vector<string> map)
{
  dp[0][0] = 1;
  int m = map.size();
  int n = map[0].length();
  // cout << dp[0][0];
  for (int j = 0; j < n; j++)
  {
    for (int i = 0; i < m; i++)
    {
      // cout << "(" << i << "," << j << ")" << dp[i][j] << endl;

      if (map[j][i] == '*')
      {
        dp[j][i] = 0;
        continue;
      }

      if (i == 0 && j == 0)
      {
        continue;
      }

      if (j == 0 && i > 0)
      {
        // cout << "(" << i << "," << j << ")" << dp[0][0] << endl;
        // cout << dp[j][i - 1];
        dp[j][i] = dp[j][i - 1];
      }
      else if (i == 0 && j > 0)
      {
        dp[j][i] = dp[j - 1][i];
      }
      else
      {
        dp[j][i] = dp[j - 1][i] + dp[j][i - 1];
        dp[j][i] %= inf;
      }
      // cout << "(" << i << "," << j << ")" << dp[i][j] << endl;
      // cout << "--------" << endl;
    }
  }

  return dp[n - 1][m - 1];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<string> x(n, "");
  rep(n)
  {
    cin >> x[i];
  }
  cout << solve(x) << endl;
}

// Always consider overflowing (Don't return inside main, because that is considered as runtime error (returning diff than 0))