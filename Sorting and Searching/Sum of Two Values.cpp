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


int arr[2*ten5];


void report_indexes(int i1, int i2){
  std::cout << i1 + 1 << " " << i2 + 1 << std::endl;
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;

  int x;

  int a;

  cin >> n >> x;

  std::multimap<int,int> hashmap;

  rep(n) {
    cin >> arr[i];
    hashmap.insert(pair(arr[i],i));
  }


  rep(n) {
    auto found = hashmap.find(x - arr[i]);

    if (found != hashmap.end()){
      if (found->second == i) { // found same, so not valid
        // small trick, if already found, delete this one, and check if another one exists. and use another one
        // else, welp, just put it back in the dict
        hashmap.erase(found);
        auto found2 = hashmap.find(x - arr[i]);
        if (found2 != hashmap.end()){ // another one exists!
          report_indexes(found->second, found2->second);
          return 0;
        }

        // nop, this was just same one... add again
        hashmap.insert(pair(found->first,i));
      } else {
        report_indexes(i, found->second);
        return 0;
      }
    }
  }



  std::cout << "IMPOSSIBLE";
  return 0;
}

// Always consider overflowing (Don't return inside main, because that is considered as runtime error (returning diff than 0))