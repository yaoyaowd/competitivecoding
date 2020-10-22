#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 300010;
const int inf = 1e8;
const int mod = 1000000007;

int t;
int n;
int a[550];
int dp[550][550];
int dp2[550];

int calc(int l, int r) {
	if (l + 1 == r) {
		return dp[l][r] = a[l];
	}
	if (dp[l][r] != 0) {
		return dp[l][r];
	}

	dp[l][r] = -1;
	for (int mid = l + 1; mid < r; ++mid) {
		int lf = calc(l, mid);
		int rg = calc(mid, r);
		if (lf > 0 && lf == rg) {
			return dp[l][r] = lf + 1;
		}
	}
	return dp[l][r];
}

void solve() {
	for (int i = 0; i < n + 1; ++i)
		dp2[i] = inf;

	dp2[0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			// cout << i << " " << j << " " << calc(i, j) << endl;
			if (calc(i, j) > 0) {
				dp2[j] = min(dp2[j], dp2[i] + 1);
			}
		}
	}
	cout << dp2[n] << endl;
}

int main() {
  freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i)
  	cin >> a[i];

  solve();

  return 0;
}
