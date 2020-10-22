#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 300010;
const ll inf = 1e18;
const ll mod = 1000000007;

int t;
int n;
int k1, k2;
int m1, m2;

int main() {
  freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> n >> k1 >> k2;
    int x;
    m1 = 0;
    m2 = 0;
    for (int j = 0; j < k1; ++j) {
      cin >> x;
      m1 = max(m1, x);
    }
    for (int j = 0; j < k2; ++j) {
      cin >> x;
      m2 = max(m2, x);
    }
    if (m1 > m2) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
