#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 300010;
const int inf = 1e8;
const int mod = 1000000007;

int main() {
  freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  vector<int> b(m);

  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int j = 0; j < m; ++j) cin >> b[j];

  vector<int> ca;
  vector<int> cb;
  int c = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) {
      c++;
    } else {
      if (c > 0) {
        ca.push_back(c);
        c = 0;
      }
    }
  }
  if (c > 0) {
    ca.push_back(c);
  }
  c = 0;
  for (int i = 0; i < m; ++i) {
    if (b[i] == 1) {
      c++;
    } else {
      if (c > 0) {
        cb.push_back(c);
        c = 0;
      }
    }
  }
  if (c > 0) {
    cb.push_back(c);
  }
  sort(ca.begin(), ca.end());
  sort(cb.begin(), cb.end());

  ll ans = 0;
  ll totalca = 0;
  for (int i = 0; i < ca.size(); ++i)
    totalca += ca[i];
  ll totalcb = 0;
  int ap = 0;
  int aselect = ca.size();
  int bp = cb.size() - 1;
  int bselect = 0;

  for (int i = 1; i <= n; ++i)
    if (k % i == 0) {
      // cout << i << " " << k / i << endl;
      while (ap < ca.size() && ca[ap] < i) {
        totalca -= ca[ap];
        aselect -= 1;
        ap++;
      }
      int bl = k / i;
      while (bp >= 0 && cb[bp] >= bl) {
        totalcb += cb[bp];
        bselect += 1;
        bp--;
      }

      ll ac = totalca - aselect * i + aselect;
      ll bc = totalcb - bselect * bl + bselect;
      // cout << ac << " " << bc << endl;
      ans += ac * bc;
    }

  cout << ans << endl;

  return 0;
}
