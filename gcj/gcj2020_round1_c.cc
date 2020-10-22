#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 200010;
const int inf = 1e8;
const int mod = 1000000007;

int r, s;

void solve(int r, int s) {
  if (r == 1)
    return;
  for (int i = s - 1; i > 0; --i)
    cout << i * r + (r - 1) * (s - i - 1) << " " << r - 1 << endl;
  solve(r - 1, s);
}

void init() {
  cin >> r >> s;
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
    cout << "Case #" << i + 1 << ": " << (r - 1) * (s - 1) << endl;
    solve(r, s);
  }

  return 0;
}
