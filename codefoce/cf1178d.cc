#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e6 + 7;
const int mod = 998244353;

int n;
int p;

bool is_prime(int p) {
  for (int i = 2; i * i <= p; ++i)
    if (p % i == 0)
      return false;
  return true;
}

int main() {
  freopen("in.txt", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  p = n;
  while (p < n + n / 2 && !is_prime(p)) {
    p++;
  }

  if (!is_prime(p)) {
    cout << -1 << endl;
  } else {
    cout << p << endl;
    for (int i = 1; i < n; ++i)
      cout << i << " " << i + 1 << endl;
    cout << n << " " << 1 << endl;
    for (int i = n; i < p; ++i) {
      cout << i - n + 1 << " " << i - n + 1 + n / 2 << endl;
    }
  }
  return 0;
}
