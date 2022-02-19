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

// 10^19 is greater than LL capacity.
ll quick_pow10(int n)
{
  static ll pow10[19] = {
      1,   // 10^0
      10,  // 10^1
      100, // 10^2
      1000,
      10000,
      100000, // 10^5
      1000000,
      10000000,
      100000000,
      1000000000,
      10000000000, // 10^10
      100000000000,
      1000000000000,
      10000000000000,
      100000000000000,
      1000000000000000, // 10^15
      10000000000000000,
      100000000000000000,  // 10^17
      1000000000000000000, // 10^18
  };

  return pow10[n];
}

char query(ll k)
{
  // locate number of digit
  if (k < 10)
  {
    return to_string(k)[0];
  }

  int digit = 1;
  ll prevendpoint = 1;
  ll endpoint = 9;

  ll help_k = k;
  while (true)
  {
    if (help_k <= endpoint)
    {
      break;
    }
    prevendpoint = endpoint;
    // prevendpoint = quick_pow10(digit - 1) * 9 * digit;
    digit++;
    help_k -= prevendpoint;
    endpoint = quick_pow10(digit - 1) * 9 * digit;
    // cout << endpoint << endl;
  }

  ll index = help_k - 1;
  ll str_index = index % digit;
  ll interval_index = index / digit;

  // cout << "Digit " << digit << endl;
  // cout << "Index " << index << endl;
  // cout << "String " << str_index << endl;
  // cout << "Interval " << interval_index << endl;
  // cout << "Endpoints " << prevendpoint << "------" << endpoint << endl;

  // cout << "Detected number: " << quick_pow10(digit - 1) + interval_index << endl;
  return to_string(quick_pow10(digit - 1) + interval_index)[str_index];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  ll k;
  rep(t)
  {
    cin >> k;
    cout << query(k) << endl;
  }
}

// Always consider overflowing (Don't return inside main, because that is considered as runtime error (returning diff than 0))
// Check when receiving parameters (Those can overflow too! ll > int)