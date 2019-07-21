#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e6 + 7;
const int mod = 998244353;

int w, h;

int pow(int b, int t) {
  int ret = 1;
  for (int i = 0; i < t; ++i)
    ret = (ret * b) % mod;
  return ret;
}

int main() {
  freopen("in.txt", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> w >> h;
  cout << pow(2, w + h) << endl;
  return 0;
}
