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

const vector<char> directions = {'U', 'D', 'L', 'R'};

const int bsize = 4;

ll recsolve(ii prev, vector<ii> &travelled, string &pattern)
{
  if (sz(travelled) == bsize * bsize)
  {
    travelled.pop_back(); // unconsider this one
    return prev == ii(0, bsize - 1) ? 1 : 0;
  }
  else
  {
    ll val = 0;

    // ll j = sz(travelled);
    // cout << j;
    // cout << travelled[j - 1].first << "-" << travelled[j - 1].second << endl;
    // return 1;

    // up
    if (prev.second != 0 && (pattern[sz(travelled) - 1] == 'U' || pattern[sz(travelled) - 1] == '?'))
    {
      ii moved(prev.first, prev.second - 1);
      if (find(travelled.begin(), travelled.end(), moved) == travelled.end()) // don't repeat
      {
        // vii copytravel(travelled);
        travelled.push_back(moved);
        val += recsolve(moved, travelled, pattern);
      }
    }

    // down
    if (prev.second != (bsize - 1) && (pattern[sz(travelled) - 1] == 'D' || pattern[sz(travelled) - 1] == '?'))
    {
      ii moved(prev.first, prev.second + 1);
      if (find(travelled.begin(), travelled.end(), moved) == travelled.end()) // don't repeat
      {
        // vii copytravel(travelled);
        travelled.push_back(moved);
        val += recsolve(moved, travelled, pattern);
      }
    }

    // left
    if (prev.first != 0 && (pattern[sz(travelled) - 1] == 'L' || pattern[sz(travelled) - 1] == '?'))
    {
      ii moved(prev.first - 1, prev.second);
      if (find(travelled.begin(), travelled.end(), moved) == travelled.end()) // don't repeat
      {
        // vii copytravel(travelled);
        travelled.push_back(moved);
        val += recsolve(moved, travelled, pattern);
      }
    }

    // right
    if (prev.first != (bsize - 1) && (pattern[sz(travelled) - 1] == 'R' || pattern[sz(travelled) - 1] == '?'))
    {
      ii moved(prev.first + 1, prev.second);
      if (find(travelled.begin(), travelled.end(), moved) == travelled.end()) // don't repeat
      {
        // vii copytravel(travelled);
        travelled.push_back(moved);
        val += recsolve(moved, travelled, pattern);
      }
    }

    travelled.pop_back(); // remove last

    return val;
  }
}

///// Consider many cases that get locked up (create bool variable "moved" and if there's no possibility it should simply return 0 and lockout)

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  vii travelled = {ii(0, 0)};

  string pattern;
  cin >> pattern;

  ll x = recsolve(ii(0, 0), travelled, pattern);

  cout << x << endl;
}

// Always consider overflowing (Don't return inside main, because that is considered as runtime error (returning diff than 0))