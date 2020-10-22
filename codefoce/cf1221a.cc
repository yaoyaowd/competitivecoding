#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1000010;
const ll mod = 1000000007;

int n;
vector<int> a;

int main() {
  freopen("in.txt", "r", stdin);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int q;
    cin >> q;
    a.resize(q);
    for (int j = 0; j < q; ++j)
      cin >> a[j];

    bool succ = false;
    while (true) {
      bool move = false;
      sort(a.begin(), a.end());
      for (int j = 0; j < a.size(); ++j) {
        if (a[j] == 2048) {
          succ = true;
          break;
        }
      }
      if (succ)
        break;

      for (int j = 0; j < a.size() - 1; ++j) {
        if (a[j] == a[j + 1]) {
          move = true;
          a[j] += a[j + 1];
          a[j + 1] = a[a.size() - 1];
          a.resize(a.size() - 1);
          break;
        }
      }

      if (!move)
        break;
    }

    if (succ)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
