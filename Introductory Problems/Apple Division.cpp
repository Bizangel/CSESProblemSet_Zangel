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

template <typename T>
struct Node
{
  Node *left;
  Node *right;
  T val;
  Node(T v, Node *l, Node *r)
  {
    left = l;
    right = r;
    val = v;
  }
};

template <typename T>
void DeleteNode(Node<T> *root)
{
  if (root != nullptr)
  {
    if (root->left != nullptr)
    {
      DeleteNode(root->left);
    }
    if (root->right != nullptr)
    {
      DeleteNode(root->right);
    }
    delete root;
  }
}

template <typename T>
void printInorder(struct Node<T> *node)
{
  if (node == nullptr)
    return;
  printInorder(node->left);
  cout << node->val << " ";
  printInorder(node->right);
}

template <typename T>
void prettyPrintTree(const std::string &prefix, const Node<T> *node, bool isLeft)
{
  if (node != nullptr)
  {
    std::cout << prefix;

    // std::cout << (isLeft ? "├──" : "└──");
    std::cout << (isLeft ? "|--" : "|--");

    // print the value of the node
    std::cout << node->val << std::endl;

    // enter the next tree level - left and right branch
    prettyPrintTree(prefix + (isLeft ? "|   " : "    "), node->left, true);
    prettyPrintTree(prefix + (isLeft ? "|   " : "    "), node->right, false);
  }
}

template <typename T>
void prettyPrintTree(const Node<T> *node)
{
  prettyPrintTree("", node, false);
}

ll p[20];

// ll a[20];
// ll b[20];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n;
  cin >> n;
  ll totalsum = 0;
  rep(n)
  {
    cin >> p[i];
    totalsum += p[i];
  }

  // explore all possibilities simultaneously
  // cut them off once they're atop the middle.
  ll target = totalsum / 2; // this is target either equal or less.
  sort(p, p + n);
  reverse(p, p + n);

  queue<Node<ll> *> frontier; // empty que of nodes
  auto *root = new Node<ll>(0, nullptr, nullptr);
  frontier.push(root); // insert first node
  rep(n)
  {
    // process frontier
    ll f_size = sz(frontier);
    FOR(j, 0, f_size)
    {
      auto left = new Node<ll>(frontier.front()->val, nullptr, nullptr); // exclude
      frontier.push(left);
      frontier.front()->left = left;
      if ((frontier.front()->val + p[i]) <= target)
      {
        auto right = new Node<ll>(frontier.front()->val + p[i], nullptr, nullptr);
        frontier.front()->right = right; // includes
        frontier.push(right);
      }
      frontier.pop();
    }
  }

  ll min_diff = 1e9;
  ll x;
  ll total = sz(frontier);
  rep(total)
  {
    x = frontier.front()->val;
    frontier.pop();
    min_diff = min(min_diff, totalsum - 2 * x);
  }

  cout << min_diff << endl;
  DeleteNode(root); // clear memory
}

// Always consider overflowing (Don't return inside main, because that is considered as runtime error (returning diff than 0))