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
typedef vector<vector<int>> intMat;

void getTops(int n, intMat &towers, int &topA, int &topB, int &topC)
{
  topA = n + 1;

  rep(n)
  {
    if (towers[0][i] != 0)
    {
      topA = towers[0][i];
      break;
    }
  }

  topB = n + 1;
  rep(n)
  {
    if (towers[1][i] != 0)
    {
      topB = towers[1][i];
      break;
    }
  }

  topC = n + 1;
  rep(n)
  {
    if (towers[2][i] != 0)
    {
      topC = towers[2][i];
      break;
    }
  }
}

void movetower(int from, int to, intMat &towers, int n)
{
  int toMove;
  rep(n)
  {
    if (towers[from][i] != 0)
    {
      toMove = towers[from][i];
      towers[from][i] = 0;
      break;
    }
  }

  int firstEleIndex = n;
  rep(n)
  {
    if (towers[to][i] != 0)
    {
      firstEleIndex = i;
      break;
    }
  }

  towers[to][firstEleIndex - 1] = toMove;
}

void printMat(intMat mat)
{
  FOR(i, 0, mat.size())
  {
    FOR(j, 0, mat[0].size())
    {
      std::cout << mat[i][j] << " ";
    }
    std::cout << "\n";
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<vector<int>> towers = vector<vector<int>>(3, vector<int>(n, 0));
  vector<vector<int>> target = vector<vector<int>>(3, vector<int>(n, 0));

  rep(n)
  {
    towers[0][i] = i + 1;
    target[2][i] = i + 1;
  }

  ll count = 0;
  int topA;
  int topB;
  int topC;

  // getTops(n, towers, topA, topB, topC);

  cout << pow(2, n) - 1 << endl;
  if (n % 2 == 0)
  { // even strat

    while (true)
    {
      // printMat(towers);
      // cout << " ------ " << endl;
      // A to B
      getTops(n, towers, topA, topB, topC);
      if (topA < topB)
      {
        movetower(0, 1, towers, n);
        cout << "1 2" << endl;
      }
      else
      {
        movetower(1, 0, towers, n);
        cout << "2 1" << endl;
      }
      if (towers == target)
      {
        break;
      }
      count++;
      // A to C
      // printMat(towers);
      // cout << " ------ " << endl;
      getTops(n, towers, topA, topB, topC);
      if (topA < topC)
      {
        movetower(0, 2, towers, n);
        cout << "1 3" << endl;
      }
      else
      {
        movetower(2, 0, towers, n);
        cout << "3 1" << endl;
      }
      if (towers == target)
      {
        break;
      }
      count++;

      // B to C
      // printMat(towers);
      // cout << " ------ " << endl;
      getTops(n, towers, topA, topB, topC);
      if (topB < topC)
      {
        movetower(1, 2, towers, n);
        cout << "2 3" << endl;
      }
      else
      {
        movetower(2, 1, towers, n);
        cout << "3 2" << endl;
      }
      if (towers == target)
      {
        break;
      }
    }
  }
  else
  {
    // uneven strategy
    while (true)
    {
      // printMat(towers);
      // cout << " ------ " << endl;
      // A to C
      getTops(n, towers, topA, topB, topC);
      if (topA < topC)
      {
        movetower(0, 2, towers, n);
        cout << "1 3" << endl;
      }
      else
      {
        movetower(2, 0, towers, n);
        cout << "3 1" << endl;
      }
      if (towers == target)
      {
        break;
      }
      count++;
      // A to B
      // printMat(towers);
      // cout << " ------ " << endl;
      getTops(n, towers, topA, topB, topC);
      if (topA < topB)
      {
        movetower(0, 1, towers, n);
        cout << "1 2" << endl;
      }
      else
      {
        movetower(1, 0, towers, n);
        cout << "2 1" << endl;
      }
      if (towers == target)
      {
        break;
      }
      count++;

      // B to C
      // printMat(towers);
      // cout << " ------ " << endl;
      getTops(n, towers, topA, topB, topC);
      if (topB < topC)
      {
        movetower(1, 2, towers, n);
        cout << "2 3" << endl;
      }
      else
      {
        movetower(2, 1, towers, n);
        cout << "3 2" << endl;
      }
      if (towers == target)
      {
        break;
      }
    }
  }
}
// Always consider overflowing (Don't return inside main, because that is considered as runtime error (returning diff than 0))