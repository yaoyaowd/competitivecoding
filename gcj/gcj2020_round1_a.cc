#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 200010;
const int inf = 1e8;
const int mod = 1000000007;

int64_t a, b;
string ans;

bool solve() {
  ans = "";
  bool ra = a < 0;
  bool rb = b < 0;
  a = abs(a);
  b = abs(b);
  // cout << a << " " << b << endl;
  while (a != 0 || b != 0) {
    if (a % 2 == b % 2)
      return false;
    if (a % 2 == 1) {
      int64_t na = a - 1;
      if (na % 4 == b % 4 && (na != 0 || b != 0))
        na = a + 1;
      if (na == a + 1)
        ans = ans + "W";
      else
        ans = ans + "E";
      a = na;
    } else {
      int64_t nb = b - 1;
      if (nb % 4 == a % 4 && (a != 0 || nb != 0))
        nb = b + 1;
      if (nb == b + 1)
        ans = ans + "S";
      else
        ans = ans + "N";
      b = nb;
    }
    a /= 2;
    b /= 2;
    // cout << a << " " << b << endl;
  }

  for (int i = 0; i < ans.length(); ++i) {
    if (ra && ans[i] == 'E')
      ans[i] = 'W';
    else if (ra && ans[i] == 'W')
      ans[i] = 'E';
    else if (rb && ans[i] == 'N')
      ans[i] = 'S';
    else if (rb && ans[i] == 'S')
      ans[i] = 'N';
  }
  return true;
}

void init() {
  cin >> a >> b;
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
    bool s = solve();
    if (!s)
      cout << "Case #" << i + 1 << ": IMPOSSIBLE" << endl;
    else
      cout << "Case #" << i + 1 << ": " << ans << endl;
  }

  return 0;
}
