#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2000010;
const int inf = 1e8;
const int mod = 1000000007;

int t;
string s;
int pref[maxn];

string solve2(const string& s) {
  string a = s;
  reverse(a.begin(), a.end());
  a = s + "#" + a;
  int c = 0;
  for (int i = 1; i < a.size(); ++i) {
    while (c != 0 && a[c] != a[i]) {
      c = pref[c - 1];
    }
    if (a[c] == a[i]) {
      c++;
    }
    pref[i] = c;
  }
  return s.substr(0, c);
}

void solve() {
  int l = 0;
  while (l < s.size() - l - 1) {
    if (s[l] != s[s.size() - l - 1])
      break;
    l++;
  }
  if (l > 0) {
    cout << s.substr(0, l);
  }

  if (s.size() > l + l) {
    string x = s.substr(l, s.size() - l - l);
    string a = solve2(x);
    reverse(x.begin(), x.end());
    string b = solve2(x);
    if (a.size() < b.size()) {
      cout << b;
    } else {
      cout << a;
    }
  }
  if (l > 0) {
    cout << s.substr(s.size() - l, l);
  }
  cout << endl;
}

int main() {
  freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> s;
    solve();
  }

  return 0;
}
