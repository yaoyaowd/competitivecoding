#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define pb push_back
#define mp make_pair
#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)
#define EPS 1e-6
#define INF 1000000010
#define pi acos(-1.0)
#define mod 1000000007
// #define mod 998244353
#define maxn 100100
#define maxk 101
#define maxm 500010
#define maxq 500010
#define inf 1000000000
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n, m;
vector<pair<int, int>> a;
vector<int> b;
vector<int> c;
int cc;

ll solve(int k) {
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ll newans = (i - k);
		if (newans < 0) newans += n;
		newans += (ll)(c[i]-1) * (ll)n;
		newans += b[i];
		ans = max(newans, ans);
	}
	return ans;
}

void prepare() {
	b.resize(n);
	for (int i = 0; i < n; ++i) b[i] = 0;
	c.resize(n);
	for (int i = 0; i < a.size(); ++i) {
		c[a[i].first]++;
		int d = a[i].second - a[i].first;
		if (d < 0) d += n;
		if (b[a[i].first] == 0) b[a[i].first] = n;
		b[a[i].first] = min(b[a[i].first], d);
	}
	for (int i = 0; i < n; ++i) cc = max(c[i], cc);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		a.pb(mp(x, y));
	}
	sort(a.begin(), a.end());

	prepare();
	
	vector<ll> ans;
	ans.reserve(n);
	for (int i = 0; i < n; ++i) {
		ans.push_back(solve(i));
	}

	for (int i = 0; i < n; ++i) {
		if (i > 0) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
