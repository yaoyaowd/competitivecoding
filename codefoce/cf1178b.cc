#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e6 + 7;
const int mod = 998244353;

string s;
ll ans;
ll a[maxn];

int main() {
  freopen("in.txt", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s;
  ll l = 0;
  for (int i = s.length() - 1; i >= 0; i--) {
    if (s[i] == 'v' && s[i + 1] == 'v')
      a[i] = a[i + 1] + 1;
    else
      a[i] = a[i + 1];
  }
  for (int i = 0; i < s.length() - 1; ++i) {
    if (s[i] == 'o')
      ans += l * a[i];
    else if (s[i] == 'v' && i > 0 && s[i-1] == 'v') {
      l++;
    }
  }
  cout << ans << endl;
  return 0;
}
