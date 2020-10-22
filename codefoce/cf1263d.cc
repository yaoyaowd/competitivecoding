#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 300010;
const ll inf = 1e18;
const ll mod = 1000000007;

int n;
int a[30];
int c[30];
int b[30];

int f(int x) {
  if (x != a[x]) {
    a[x] = f(a[x]);
  }
  return a[x];
}

void merge(int x, int y) {
  x = f(x);
  y = f(y);
  if (y != x)
    a[y] = x;
}

int main() {
  freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int i = 0; i < 30; ++i) a[i] = i;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;

    memset(b, 0, sizeof(b));
    for (int j = 0; j < s.length(); ++j) {
      c[s[j] - 'a'] = 1;
      b[s[j] - 'a'] = 1;
    }

    for (int j = 0; j < 26; ++j)
      for (int t = j + 1; t < 26; ++t)
        if (b[j] == 1 && b[t] == 1) {
          merge(j, t);
        }
  }

  for (int i = 0; i < 30; ++i) a[i] = f(i);

  int ans = 0;
  for (int i = 0; i < 30; ++i)
    if (c[i] && a[i] == i) {
      ++ans;
    }

  cout << ans << endl;

  return 0;
}
