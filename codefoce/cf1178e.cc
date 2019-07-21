#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e6 + 7;
const int mod = 998244353;

int main() {
  freopen("in.txt", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  int n = s.length();
  int i = 0, j = n - 1;

  string a;
  while (j - i >= 3) {
    if (s[i] == s[j]) {
      a.push_back(s[i]);
      ++i; --j;
    } else if (s[i] == s[j - 1]) {
      a.push_back(s[i]);
      ++i; j-= 2;
    } else {
      a.push_back(s[i + 1]);
      if (s[i + 1] == s[j]) {
        --j;
      } else {
        j -= 2;
      }
      i += 2;
    }
  }
  string b = a;
  if (j >= i) a.push_back(s[i]);
  reverse(b.begin(), b.end());
  cout << a << b << endl;
  return 0;
}
