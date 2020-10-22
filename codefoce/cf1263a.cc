#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 300010;
const ll inf = 1e18;
const ll mod = 1000000007;

int t;
int r, g, b;

int main() {
  freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  while (t > 0) {
    cin >> r >> g >> b;
    t--;

    if (r > g) {
      swap(r, g);
    }
    if (g > b) {
      swap(g, b);
    }
    if (r > b) {
      swap(r, b);
    }

    if (b >= r + g) {
      cout << r + g << endl;
    } else {
      cout << b + (r + g - b) / 2 << endl;
    }
  }
  return 0;
}
