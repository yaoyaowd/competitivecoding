#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 200010;
const int inf = 1e8;
const int mod = 1000000007;

int nr, ng, nb;
vector<int> r;
vector<int> g;
vector<int> b;

long long value(long long a, long long b, long long c) {
  return (a - b) * (a - b) + (a - c) * (a - c) + (b - c) * (b - c);
}

long long select_best1(int i, int& j, int& t) {
  while (t + 1 < nb && value(r[i], g[j], b[t + 1]) <= value(r[i], g[j], b[t]))
    t++;
  return value(r[i], g[j], b[t]);
}

long long select_best2(int i, int& j, int& t) {
  while (j + 1 < ng && value(r[i], g[j + 1], b[t]) <= value(r[i], g[j], b[t]))
    j++;
  return value(r[i], g[j], b[t]);
}

void solve() {
  long long ans = value(r[0], g[0], b[0]);
  vector<int> gp(3, 0);
  vector<int> bp(3, 0);
  vector<int> gc(3, 0);
  vector<int> bc(3, 0);
  for (int i = 0; i < nr; ++i) {
    if (i > 0 && r[i] == r[i - 1]) continue;
    while (gp[0] < ng - 1 && g[gp[0] + 1] < r[i]) gp[0]++;
    gp[1] = gp[0] + 1;
    gp[2] = gp[0] + 1;
    while (gp[2] < ng && g[gp[2]] <= r[i]) gp[2]++;
    while (bp[0] < nb - 1 && b[bp[0] + 1] < r[i]) bp[0]++;
    bp[1] = bp[0] + 1;
    bp[2] = bp[0] + 1;
    while (bp[2] < nb && b[bp[2]] <= r[i]) bp[2]++;

    ans = min(ans, select_best1(i, gp[0], bc[0]));
    if (gp[1] < ng)
      ans = min(ans, select_best1(i, gp[1], bc[1]));
    if (gp[2] < ng)
      ans = min(ans, select_best1(i, gp[2], bc[2]));
    ans = min(ans, select_best2(i, gc[0], bp[0]));
    if (bp[1] < nb)
      ans = min(ans, select_best2(i, gc[1], bp[1]));
    if (bp[2] < nb)
      ans = min(ans, select_best2(i, gc[2], bp[2]));
  }
  cout << ans << endl;
}

void init() {
  cin >> nr >> ng >> nb;
  r.clear();
  g.clear();
  b.clear();
  for (int i = 0; i < nr; ++i) {
    int x;
    cin >> x;
    r.push_back(x);
  }
  for (int i = 0; i < ng; ++i) {
    int x;
    cin >> x;
    g.push_back(x);
  }
  for (int i = 0; i < nb; ++i) {
    int x;
    cin >> x;
    b.push_back(x);
  }
  sort(r.begin(), r.end());
  sort(b.begin(), b.end());
  sort(g.begin(), g.end());
}

int main() {
  freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    init();
    solve();
  }

  return 0;
}
