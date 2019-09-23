#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e6 + 7;
const int mod = 998244353;

int n;
vector<int> a;
unordered_map<int, int> b;

bool solve(int m) {
  b.clear();
  int c = 0;
  for (int i = m; i < n; ++i) {
    b[a[i]] = b[a[i]] + 1;
    if (b[a[i]] == 2)
      c++;
  }
  if (c == 0)
    return true;
  for (int i = 0; i < n - m; ++i) {
    b[a[i]] = b[a[i]] + 1;
    if (b[a[i]] == 2)
      c++;
    b[a[i + m]] = b[a[i + m]] - 1;
    if (b[a[i + m]] == 1)
      c--;
    if (c == 0)
      return true;
  }
  return false;
}

int main() {
  freopen("in.txt", "r", stdin);
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int l = 0, r = n - 1;
  int m = (l + r) / 2;
  while (l < r) {
    m = (l + r) / 2;
    if (solve(m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  cout << r << endl;
  return 0;
}
