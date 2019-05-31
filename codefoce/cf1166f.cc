#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <assert.h>

#define pb push_back
#define mp make_pair
#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)
#define EPS 1e-6
#define INF 1000000010
#define pi acos(-1.0)
#define maxn 100010
#define mod 1000000007
typedef long long ll;
typedef unsigned long long ull;
const ll inf = (ll)(1e18+7);

using namespace std;

int n, m, c, q;
set<int> adj[maxn];
int p[maxn];
set<pair<int, int>> bc[maxn];

int get(int x) {
  if (x == p[x]) return x;
  p[x] = get(p[x]);
  return p[x];
}

void union2(int x, int y) {
  x = get(x);
  y = get(y);
  if (x == y) return;
  if (adj[x].size() < adj[y].size()) swap(x, y);
  for (int v : adj[y]) adj[x].insert(v);
  adj[y].clear();
  p[y] = x;
}

void add_edge(int x, int y, int z) {
  adj[get(x)].insert(y);
  auto it = bc[y].lower_bound(mp(z, -1));
  if (it == bc[y].end() || (it->first != z)) {
    bc[y].insert(mp(z, x));
  } else {
    union2(x, (it->second));
  }
}

int main() {
  freopen("in.txt", "r", stdin);
  cin >> n >> m >> c >> q;
  for (int i = 0; i < n; ++i)
    p[i + 1] = i + 1;

  for (int i = 0; i < m; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    add_edge(x, y, z);
    add_edge(y, x, z);
  }

  string ch;
  for (int i = 0; i < q; ++i) {
    int x, y, z;
    cin >> ch >> x >> y;
    if (ch == "+") {
      cin >> z;
      add_edge(x, y, z);
      add_edge(y, x, z);
    } else {
      if (get(x) == get(y)) {
        cout << "Yes" << endl;
      } else if (adj[get(x)].find(y) != adj[get(x)].end()) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
  return 0;
}