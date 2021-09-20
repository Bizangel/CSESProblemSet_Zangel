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


ll recsolve(ll k){
  if(k == 1){
    cout << 0 << endl;
    return 0;
  } else if (k == 2){
    cout << 0 << endl << 6 << endl;
    return 6;
  } 

  ll count = 0;
  // bottom side
  ll poss = (k-1)*(k-1);
  rep(k-1){
    int cancel = 0;
    if (i - 1 >= 0){
      cancel++;
    }
    if(i - 2 >= 0){
      cancel++;
    }
    if (i + 1 < k - 1){
      cancel++;
    }
    if(i + 2 < k - 1){
      cancel++;
    }
    // cout << cancel << endl;
    count += (poss - cancel)*2;
  }
  
  count += ((k-1)*(k-1)) - 2; // from corner
  count += (2*k - 1)*(k-1) - 2;
  
  ll result = recsolve(k-1) + count;
  cout << result << endl;
  return result;
}


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  recsolve(n);
}

// Always consider overflowing