#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 300010;
const ll inf = 1e18;
const ll mod = 1000000007;

int n;
std::string s;

int main() {
  freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  cin >> s;
  int o = s.length();

  bool remove = false;
  for (int c = 25; c >= 0; c--) {
    remove = false;
    std::string ns;
    char p = s[0];
    for (int i = 0; i < s.length(); ++i) {
      if ((s[i] - 'a') == c && ((i > 0 && (p - 'a') == c-1) || (i < s.length() - 1 && (s[i + 1] - 'a') == c - 1))) {
        // pass
        remove = true;
      } else {
        ns = ns + s[i];
        p = s[i];
      }
    }
    if (remove) c++;
    s = ns;
  }

  cout << o - s.length() << endl;
  return 0;
}
