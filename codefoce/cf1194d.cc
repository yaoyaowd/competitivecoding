#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 7;
const int mod = 998244353;

int q;
int n, k;

int main() {
  freopen("in.txt", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    cin >> n >> k;
    if (k % 3 == 1 || k % 3 == 2) {
        if (n % 3 == 0) {
            cout << "Bob" << endl;
        } else {
            cout << "Alice" << endl;
        }
    } else {
        int x = n / k;
        int y = n % k;
        // cout << x << " " << y << " " << y - x % (k + 1) << endl;
        y = y - x % (k + 1);
        if (y < 0) y += (k + 1);
        if (y % 3 == 0 && y != k) {
            cout << "Bob" << endl;
        } else {
            cout << "Alice" << endl;
        }
    }
  }
  return 0;
}
