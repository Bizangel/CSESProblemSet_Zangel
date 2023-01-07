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

struct movie_sort_by_end
{
    inline bool operator() (const pair<int,int>& struct1, const pair<int,int>& struct2)
    {
        return (struct1.second < struct2.second);
    }
};

pair<int,int> movies[2*ten5];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;

  int watchedMovies = 0;

  cin >> n;
  int a,b;
  rep(n) {
    cin >> a >> b;
    movies[i] = pair(a,b);
  }

  std::sort(movies,movies+n, movie_sort_by_end());


  // after sorting.
  int currentTime = 0;

  rep(n){
    if (currentTime <= movies[i].first){  // can watch, so watch it!
      watchedMovies++;
      currentTime = movies[i].second;
    }
  }

  std::cout << watchedMovies;
}

// Always consider overflowing (Don't return inside main, because that is considered as runtime error (returning diff than 0))