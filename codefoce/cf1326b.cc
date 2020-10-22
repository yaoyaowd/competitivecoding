#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 400010;
const int inf = 1e8;
const int mod = 1000000007;

int n;
int b[maxn];
int a[maxn];

int main() {
  freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  int m = 0;
  for (int i = 0; i < n; ++i) {
    a[i] = b[i] + m;
    m = max(a[i], m);
  }

  for (int i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }
  return 0;
}
