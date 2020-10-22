#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 300010;
const ll inf = 1e18;
const ll mod = 1000000007;

int t;
int n;
vector<int> a;

int main() {
  freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> n;
    int x;
    a.clear();
    for (int j = 0; j < n; ++j) {
      cin >> x;
      a.push_back(x);
    }

    bool fnd = false;
    for (int j = 0; j + 1 < n; ++j) {
      if (abs(a[j] - a[j + 1]) > 1) {
        cout << "YES" << endl << j + 1 << " " << j + 2 << endl;
        fnd = true;
        break;
      }
    }
    if (!fnd) {
      cout << "NO" << endl;
    }
  }
  return 0;
}
