#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 200010;
const int inf = 1e8;
const int mod = 1000000007;

int t, a, b;

void solve() {
  string ans = "";
  int x = 0;
  int y = 0;
  int d = 1000000000 - a;
  int l = 1000000000 - d * 3;

  cout << x << " " << y << std::flush;
  cin >> ans;
  if (ans == "CENTER")
    return;

  cout << l << " " << y << std::flush;
  cin >> ans;
  while (ans == "HIT") {
    l++;
    cout << l << " " << y << std::flush;
    cin >> ans;
  }

  while (true) {
    cout << l << " " << y + 1 << std::flush;
    cin >> ans;
    if (ans == "HIT") {
      y += 1;
      while (ans == "HIT") {
        l++;
        cout << l << " " << y << std::flush;
        cin >> ans;
      }
    } else {
      cout << l << " " << y - 1 << std::flush;
      cin >> ans;
      if (ans == "HIT") {
        y -= 1;
        while (ans == "HIT") {
          l++;
          cout << l << " " << y << std::flush;
          cin >> ans;
        }
      } else {
        cout << l - a << " " << y << std::flush;
        cin >> ans;
        if (ans == "CENTER") {
          return;
        } else {
          cout << ans << std::flush;
          break;
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t >> a >> b;
  for (int i = 0; i < t; ++i) {
    solve();
  }

  return 0;
}
