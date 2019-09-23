#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e16 + 113;
const int maxn = 1e6 + 113;

int n;
ll a[maxn];

namespace SegmentTree {
  int n;
  ll t[4 * maxn];
  ll mod[4 * maxn];

  void pull(int v) {
    t[v] = min(t[2 * v + 1], t[2 * v + 2]);
  }

  void apply(int v, ll val) {
    t[v] += val;
    mod[v] += val;
  }

  void push(int v) {
    if (mod[v] != 0) {
      apply(2 * v + 1, mod[v]);
      apply(2 * v + 2, mod[v]);
      mod[v] = 0;
    }
  }

  void add(int v, int l, int r, int ql, int qr, ll val) {
    if (r <= ql || qr <= l) {
      return;
    } else if (ql <= l && r <= qr) {
      apply(v, val);
    } else {
      push(v);
      int m = (l + r) >> 1;
      add(2 * v + 1, l, m, ql, qr, val);
      add(2 * v + 2, m, r, ql, qr, val);
      pull(v);
    }
  }

  void build(int v, int l, int r) {
    if (l + 1 == r) {
      t[v] = a[l];
    } else {
      int m = (l + r) >> 1;
      build(2 * v + 1, l, m);
      build(2 * v + 2, m, r);
      pull(v);
    }
  }

  void init(int n_) {
    n = n_;
    build(0, 0, n);
  }

  int go_down(int v, int l, int r) {
    if (l + 1 == r) {
      return l;
    } else {
      push(v);
      int m = (l + r) >> 1;
      int res = -1;
      if (t[2 * v + 2] == 0) {
        res = go_down(2 * v + 2, m, r);
      } else {
        res = go_down(2 * v + 1, l, m);
      }
      pull(v);
      return res;
    }
  }

  void add(int l, int r, ll val) {
    add(0, 0, n, l, r, val);
  }

  void add(int pos, ll val) {
    add(0, 0, n, pos, pos + 1, val);
  }
}

int main() {
  freopen("in.txt", "r", stdin);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  SegmentTree::init(n);
  vector<int> ans(n, -1);
  for (int i = 1; i <= n; ++i) {
    int pos = SegmentTree::go_down(0, 0, n);
    ans[pos] = i;
    SegmentTree::add(pos, INF);
    SegmentTree::add(pos + 1, n, -i);
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
