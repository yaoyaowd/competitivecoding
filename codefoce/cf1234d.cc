#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1000010;
const ll mod = 1000000007;

std::string a;
int n;
int b[maxn];

void add(int c, int l, int r, int p, int v) {
  b[c] |= (1<<v);
  if (l >= r - 1) {
    return;
  }
  int m = (l + r) / 2;
  if (p < m) {
    add(c * 2 + 1, l, m, p, v);
  } else {
    add(c * 2 + 2, m, r, p, v);
  }
}

void remove(int c, int l, int r, int p, int v) {
  if (l >= r - 1) {
    b[c] = 0;
    return;
  }
  int m = (l + r) / 2;
  if (p < m) {
    remove(c * 2 + 1, l, m, p, v);
  } else {
    remove(c * 2 + 2, m, r, p, v);
  }
  b[c] = b[c * 2 + 1] | b[c * 2 + 2];
  // cout << c << " " << l << " " << r << " "<< b[c] << endl;
}

int query(int c, int l, int r, int ll, int rr) {
  if (ll <= l && r <= rr)
    return b[c];
  int m = (l + r) / 2;
  if (rr <= m) {
    return query(c * 2 + 1, l, m, ll, rr);
  } else if (ll >= m) {
    return query(c * 2 + 2, m, r, ll, rr);
  } else {
    return query(c * 2 + 1, l, m, ll, m) | query(c * 2 + 2, m, r, m, rr);
  }
}

int main() {
  freopen("in.txt", "r", stdin);
  cin >> a;
  for (int i = 0; i < a.length(); ++i) {
    add(0, 0, a.length(), i, a[i] - 'a');
  }
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    if (t == 2) {
      int l, r;
      cin >> l >> r;
      l -= 1;
      int ans = query(0, 0, a.length(), l, r);
      int cnt = 0;
      for (int j = 0; j < 26; ++j) {
        if (ans & (1 << j))
          cnt += 1;
      }
      cout << cnt << endl;
    } else {
      int p;
      string c;
      cin >> p >> c;
      p -= 1;
      remove(0, 0, a.length(), p, a[p] - 'a');
      add(0, 0, a.length(), p, c[0] - 'a');
      a[p] = c[0];
    }
  }
  return 0;
}
