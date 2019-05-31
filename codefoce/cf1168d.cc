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
#define maxn 300010
#define mod 1000000007
typedef long long ll;
typedef unsigned long long ull;
const ll inf = (ll)(1e18+7);

using namespace std;

int n, q;
int dep[maxn];
int deg[maxn];
int par[maxn];
char ch[maxn];
int len[maxn];

int sum[maxn];
int up[maxn];
int up_ch[maxn];
map<int, int> cnt[maxn];
vector<int> g[maxn];
int dp[maxn][30];

int main() {
  freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(0);
  cin >> n >> q;

  for (int i = 1; i < n; ++i) {
    int p;
    char c;
    cin >> p >> c;
    p--;
    dep[i] = dep[p] + 1;
    deg[p]++;
    par[i] = p;
    ch[i] = c;
  }

  // Check the length of the word.
  for (int i = n - 1; i; i--) {
    if (len[par[i]] && len[par[i]] != len[i] + 1) {
      for (int j = 0; j < q; ++j) cout << "Fou\n";
      return 0;
    }
    len[par[i]] = len[i] + 1;
  }

  for (int i = 0; i < n; ++i) {
    if (deg[par[i]] > 1 || !par[i]) {
      up[i] = par[i];
      up_ch[i] = i;
    } else {
      up[i] = up[par[i]];
      up_ch[i] = up_ch[par[i]];
    }
    if (i && ch[i] != '?')
      cnt[up_ch[i]][ch[i] - 'a']++;
  }

  int bad = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (deg[i] != 1) {
      for (int j = 0; j < 26; ++j) {
        dp[up[i]][j] = max(dp[up[i]][j], dp[i][j] + cnt[up_ch[i]][j]);
      }
      g[up[i]].push_back(i);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 26; ++j) {
      sum[i] += dp[i][j];
    }
    if (sum[i] > len[i]) {
      bad++;
    }
  }

  up[0] = -1;
  auto upd = [&](int v, char c) {
    if (c == '?') {
      return;
    }
    c -= 'a';
    for (; ~v; v = up[v]) {
      if (sum[v] > len[v]) {
        bad--;
      }
      sum[v] -= dp[v][c];
      dp[v][c] = 0;
      for (int to : g[v]) {
        dp[v][c] = max(dp[v][c], dp[to][c] + cnt[up_ch[to]][c]);
      }
      sum[v] += dp[v][c];
      if (sum[v] > len[v]) {
        bad++;
      }
    }
  };
  for (int i = 0; i < q; ++i) {
    int v;
    char c;
    cin >> v >> c;
    v--;
    if (ch[v] != '?') {
      cnt[up_ch[v]][ch[v] - 'a']--;
      upd(up[v], ch[v]);
    }
    ch[v] = c;
    if (ch[v] != '?') {
      cnt[up_ch[v]][ch[v] - 'a']++;
      upd(up[v], ch[v]);
    }
    if (bad) {
      cout << "Fou\n";
    } else {
      cout << "Shi ";
      int val = 0;
      for (int i = 0; i < 26; i++) {
        val += (dp[0][i] + len[0] - sum[0]) * (i + 1);
      }
      cout << val << '\n';
    }
  }
  return 0;
}