#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 300010;
const ll inf = 1e18;
const ll mod = 1000000007;

int t;
int n;
ll k;
vector<ll> a;
int c[maxn];
bool success;

void check(ll v) {
	int base = 0;
	while (v != 0) {
		if (v % k != 0) {
			// cout << v << " " << k << " " << v % k << endl;
			c[base] += v % k;
			if (c[base] > 1)
				success = false;
		}
		v = v / k;
		base += 1;
	}
}

int main() {
  freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  for (int i = 0; i < t; ++i) {
  	cin >> n;
  	cin >> k;
  	a.resize(n);
  	for (int j = 0; j < n; ++j) cin >> a[j];

  	memset(c, 0, sizeof(c));
  	success = true;
  	for (int j = 0; j < n; ++j) {
  		check(a[j]);
  	}
  	if (success) {
  		cout << "YES" << endl;
  	} else {
  		cout << "NO" << endl;
  	}
  }
  return 0;
}
