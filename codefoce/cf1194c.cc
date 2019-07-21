#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 7;
const int mod = 998244353;

string s, t, p;
int q;
int c[26];

string solve() {
    memset(c, 0, sizeof(c));
    for (int i = 0; i < p.length(); ++i) {
        c[p[i]-'a']++;
    }
    int pos = 0;
    for (int i = 0; i < t.length(); ++i) {
        if (pos < s.length() && t[i] == s[pos]) {
            pos++;
        } else {
            if (c[t[i]-'a']>0) {
                c[t[i]-'a']--;
            } else {
                return "NO";
            }
        }
    }
    if (pos == s.length()) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
  freopen("in.txt", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    cin >> s >> t >> p;
    cout << solve() << endl;
  }
  return 0;
}
