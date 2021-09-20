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

int a[ten6];
int b[ten6];

void solve(ll n){
  if (n*(n+1)/2 % 2 == 1){
    cout << "NO" << endl;
  }
  else {
    cout << "YES" << endl;
    ll target_sum = n*(n+1)/4;

    // get sum of numbers up to there
    ll curr_sum = 0;
    ll finisher;
    ll end_value;

    ll alen = 0;
    DEC(i, n, 0){
      // cout << i << endl;
      curr_sum += i;
      
      if (curr_sum > target_sum){
        curr_sum -= i; // backtrack
        finisher = target_sum - curr_sum; // curr_sum + finisher = target_sum
        end_value = i;
        alen++;
        a[n - i] = finisher;
        break;
      }
      
      alen++;
      a[n - i] = i;
      if(curr_sum == target_sum){ // consider equal case
        end_value = i;
        finisher = i;
        break;
      }
    }

    // print found
    cout << alen <<endl;
    rep(n - end_value + 1){
      cout << a[i] << " ";
    }


    cout << endl << n - alen << endl;
    FOR(i,1,end_value + 1){
      if (i != finisher){
        cout << i << " ";
      }
    }
  }

}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n;
  cin >> n; 
  solve(n);


}

// Always consider overflowing