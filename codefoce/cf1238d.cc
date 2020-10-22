#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 500010;
const ll inf = 1e18;
const ll mod = 1000000007;

int n;
string a;

int main() {
  freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  cin >> a;

  ll ret = (ll)n * ((ll)n - 1) / 2;
  for (int x = 0; x < 2; ++x) {
    ll cur = 1;
    for (int i = 1; i < n; ++i) {
      if (a[i] == a[i - 1])
        cur += 1;
      else {
        ret -= (cur - x);
        cur = 1;
      }
    }
    reverse(a.begin(), a.end());
  }

  cout << ret << endl;

  return 0;
}
