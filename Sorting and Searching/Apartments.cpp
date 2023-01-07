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

int a[2 * ten5];
int b[2 * ten5];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;

  cin >> n >> m >> k;

  rep(n)
  {
    cin >> a[i];
  }

  rep(m)
  {
    cin >> b[i];
  }

  int i = 0;
  int j = 0;

  // sort both arrays

  std::sort(a, a + n);
  std::sort(b, b + m);

  int assigned = 0;

  while (i < n && j < m)
  {
    if (abs(a[i] - b[j]) <= k)
    {
      // compatible
      i++;
      j++;
      assigned++;
    }
    else
    {
      if (a[i] < b[j]) { // the guy wants a smaller apartment. However there's no smaller aparments!
        i++; // skip the guy;
      } else {
        // b[j] < a[i] the apartment is too small for the guy.
        // However, there aren't any other people that want smaller apartments. so ditch the apartment
        j++;
      }
    }
  };

  std::cout << assigned;
}

// 2^10 = 10^3 => 2^20 = 10^9 => 2^30 = 10

// Always consider overflowing (Don't return inside main, because that is considered as runtime error (returning diff than 0))