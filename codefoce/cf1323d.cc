#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 400010;
const int inf = 1e8;
const int mod = 1000000007;

int n;
vector<int> a;

int b[maxn];

int check(int bit) {
  for (int i =0 ; i < n; ++i) {
    b[i] = a[i] & ((bit << 1) - 1);
  }
  sort(b, b + n);

  int tot = 0;

  int l = n, r = n;
  for (int i = 0; i < n; ++i) {
    while (l > 0 && b[l - 1] + b[i] >= bit) l--;
    while (r < n && b[r] + b[i] >= bit + bit) r--;
    if (l < r) {
      tot += r - l + 1;
      if (i >= l && i < r) tot -= 1;
    }
  }
  cout << bit << " " << l << " " << r << endl;

  l = n, r = n;
  for (int i = 0; i < n; ++i) {
    while (l > 0 && b[l - 1] + b[i] >= bit + bit + bit) l--;
    while (r < n && b[r] + b[i] >= bit + bit + bit + bit - 2) r--;
    if (l < r) {
      tot += r - l + 1;
      if (i >= l && i < r) tot -= 1;
    }
  }
  
  cout << bit << " " << l << " " << r << endl;
  return tot;
}

int main() {
  freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  sort(a.begin(), a.end());

  int ans = 0;
  for (int i = 1; i <= a[n - 1] * 2; i += i) {
    ans += (check(i) % 2) * i;
  }

  cout << ans << endl;

  return 0;
}
