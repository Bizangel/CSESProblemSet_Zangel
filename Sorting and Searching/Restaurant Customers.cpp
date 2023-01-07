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

struct less_comparison
{
    inline bool operator() (const pair<int,bool>& struct1, const pair<int,bool>& struct2)
    {
        return (struct1.first < struct2.first);
    }
};

pair<int,bool> times[4*ten5]; // double

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  int a,b;

  cin >> n;
  rep(n) {
    cin >> a >> b;
    times[2*i] = pair<int,bool>(a,true);
    times[2*i + 1] = pair<int,bool>(b,false);
  }

  std::sort(times,times+(2*n), less_comparison());

  int maxCustomers = 0;
  int currentCustomers = 0;

  // after sorting.
  rep(2*n){
    if (times[i].second)
      currentCustomers++;
    else
      currentCustomers--;

    maxCustomers = max(maxCustomers, currentCustomers);
  }

  std::cout << maxCustomers;
}

// Always consider overflowing (Don't return inside main, because that is considered as runtime error (returning diff than 0))