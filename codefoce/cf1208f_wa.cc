#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e16 + 113;
const int maxn = 1e6 + 113;

int n, a[maxn], ans, bits;
pair<int, int> dp[1 << 21];

void add(int mask, int w) {
	if (dp[mask].first == -1) {
		dp[mask].first = w;
	} else if (dp[mask].second == -1) {
		if (dp[mask].first == w) return;
		dp[mask].first = w;
		if (dp[mask].first > dp[mask].second) {
			swap(dp[mask].first, dp[mask].second);
		}
	} else {
		if (dp[mask].second < w) {
			dp[mask].first = dp[mask].second;
			dp[mask].second = w;
		} else if (dp[mask].first < w && dp[mask].second != w) {
			dp[mask].first = w;
		}
	}
}

void merge(int m1, int m2) {
    if (dp[m2].first != -1) add(m1, dp[m2].first);
    if (dp[m2].second != -1) add(m1, dp[m2].second);
}

int main() {
  freopen("in.txt", "r", stdin);
  memset(dp, -1, sizeof(dp));
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    add(a[i], i);
    bits = max((int)log2(a[i]), bits);
  }
  bits++;

  for (int i = 0; i < bits; ++i) {
  	for (int mask = 0; mask < (1 << bits); ++mask) {
  	    if (mask & (1 << i)) {
  	        merge(mask ^ (1 << i), mask);
  	    }
  	}
  }

  for (int i = 0; i < n; ++i) {
      int cur = (1 << bits) - 1 - a[i];
      int opt = 0;
      for (int j = bits - 1; j >= 0; --j) {
          if ((cur >> j) & 1) {
              if(dp[opt^(1<<j)].second != -1 and dp[opt^(1<<j)].first > i){
                  opt^=(1<<j);
              }
          }
      }
      if (dp[opt].second != -1 && dp[opt].second) {
          ans = max(ans, a[i] ^ opt);
      }
  }

  cout << ans << endl;
  return 0;
}
