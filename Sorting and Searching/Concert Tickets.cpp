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


void removeTicket(std::map<int,int>&tickets, std::map<int,int>::iterator it){
  if (it->second == 1){
    // delete
    tickets.erase(it);
  } else{
    it->second--; // reduce ticket count
  }
}

int solve(std::map<int,int>&tickets, int customerMaxPrice){


  // std::cout << "Amount of tickets: " << tickets.size() << std::endl;
  if (tickets.size() == 0)
    return -1; // we ran out of tickets fellas

  auto it = tickets.lower_bound(customerMaxPrice); // the bound is not as normal ranges or smth


  if (it == tickets.end()){
    // std::cout << "Lower bound reported as tickets.end" << std::endl;
    // guy's willing to pay higher than our most expensive ticket
    // so simply give him most expensive ticket
    it--; // now points to most expensive ticket
    int toGive = (it)->first;
    removeTicket(tickets, it);
    return toGive;
  }

  if (it->first == customerMaxPrice){
    // same price ticket as he's requesting, perfect, just give him that one
    removeTicket(tickets, it);
    return customerMaxPrice;
  }

  if (it == tickets.begin()){ // our cheapest ticket, is MORE than he can afford, so big luck pal
    return -1;
  }

  it--; // it is now pointing to first element that is LESS than he requested.

  int toGive = it->first; // sell him that one
  removeTicket(tickets, it);
  return toGive;
}


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  std::map<int,int> tickets;

  int n,m;
  cin >> n >> m;

  int temp;
  rep(n){
    cin >> temp;
    if (tickets.find(temp) == tickets.end()){
      tickets[temp] = 1;
    } else {
      tickets[temp]++;
    }
  }


  int willingPrice;
  rep(m){
    cin >> willingPrice;
    cout << solve(tickets, willingPrice) << std::endl;
  }

}

// Always consider overflowing (Don't return inside main, because that is considered as runtime error (returning diff than 0))