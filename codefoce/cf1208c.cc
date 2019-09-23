#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e6 + 7;
const int mod = 998244353;

int n;
vector<int> a = {8, 9, 1, 13, 3, 12, 7, 5, 0, 2, 4, 11, 6, 10, 15, 14};
vector<int> ans;

void fill() {
  ans.resize(n * n);
  for (int i = 0; i < n / 4; ++i)
    for (int j = 0; j < n / 4; ++j)
      for (int x = 0; x < 4; ++x)
        for (int y = 0; y < 4; ++y)
          ans[(i * 4 + x) * n + j * 4 + y] = a[x * 4 + y] + (i * n / 4 + j) * 16;
}

int main() {
  cin >> n;
  fill();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (j == 0)
        cout << ans[i * n + j];
      else
        cout << " " << ans[i * n + j];
    }
    cout << endl;
  }
  return 0;
}
