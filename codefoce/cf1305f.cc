#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 300010;
const int inf = 1e8;
const int mod = 1000000007;

mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<int> a;

bool c[1000000];
vector<int> pr;
void init() {
  for (int i = 2; i < 1000000; ++i) {
    if (!c[i]) {
      pr.push_back(i);
      for (int j = i; j < 1000000; j += i) {
        c[j] = true;
      }
    }
  }
}

set<ll> can;
void add_prime(ll v) {
  for (int i = 0; i < pr.size(); ++i) {
    if (v % pr[i] == 0) {
      can.insert(v);
      while (v % pr[i] == 0) {
        v /= pr[i];
      }
    }
  }
  if (v > 1) {
    can.insert(v);
  }
}

int solve(ll v) {
  ll ret = 0;
  for (int i = 0; i < n; ++i) {
    long long add = (a[i] < v ? v - a[i] : min(a[i] % v, v - a[i] % v));
    ret = min((long long) n, ret + add);
  }
  return ret;
}

int main() {
  freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  init();
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  shuffle(a.begin(), a.end(), mt);

  for (int i = 0; i < 100 && i < a.size(); ++i) {
    add_prime(a[i]);
    add_prime(a[i] + 1);
    if (a[i] > 1) {
      add_prime(a[i] - 1);
    }
  }

  int ans = maxn;
  for (ll v : can) {
    ans = min(ans, solve(v));
  }
  cout << ans << endl;

  return 0;
}
