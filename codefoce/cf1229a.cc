#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> a;
vector<ll> b;
vector<int> c;
int n;
ll ans;

int main() {
  freopen("in.txt", "r", stdin);
  cin >> n;
  a.resize(n);
  b.resize(n);
  c.resize(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];

  for (int i = 0; i < n; ++i) {
    if (c[i] == 0) {
      for (int j = i + 1; j < n; ++j)
        if (a[i] == a[j]) {
          c[i] = 1;
          c[j] = 1;
        }

      if (c[i] == 1) {
        for (int j = 0; j < n; ++j)
          if ((a[i] & a[j]) == a[j])
            c[j] = 1;
      }
    }
  }

  ans = 0;
  for (int i = 0; i < n; ++i)
    if (c[i])
      ans += b[i];

  cout << ans << endl;
  return 0;
}
