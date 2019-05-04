#include <bits/stdc++.h>
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
#define maxn 300000
#define maxk 101
#define maxm 500010
#define maxq 500010
#define inf 1000000000
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

bool isp[maxn];
vector<int> p;

int n;
vector<int> val;
vector<int> e[maxn];

void prepare() {
	isp[2] = false;
	for (int i = 2; i < maxn; ++i)
		if (!isp[i]) {
			p.pb(i);
			int x = i;
			while (x + i < maxn) {
				x += i;
				isp[x] = true;
			}
		}
}

void init() {
	scanf("%d", &n);
	val.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		val[i] = x;
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].pb(v);
		e[v].pb(u);
	}
}

int dfs(int u, int fa, int prime, int& longest) {
	while (val[u] % prime == 0) val[u] /= prime;
	int l0 = 0, l1 = 0, cur = 0;
	int ans = 0;
	for (int v : e[u]) {
		if (val[v] % prime == 0 && v != fa) {
			ans = max(ans, dfs(v, u, prime, cur));
			if (cur > l0) {
				l1 = l0;
				l0 = cur;
			} else if (cur > l1) {
				l1 = cur;
			}
		}
	}
	if (l1 + l0 + 1 > ans) {
		ans = l1 + l0 + 1;
	}
	longest = l0 + 1;
	return ans;
}

int main() {
	prepare();
	init();
	int ans = 0, tmp = 0;
	for (int i = 1; i <= n; ++i) {
		int x = val[i];
		for (int j = 0; j < p.size(); ++j)
			if (x % p[j] == 0) {
				while (x % p[j] == 0) {
					x /= p[j];
				}
				ans = max(ans, dfs(i, 0, p[j], tmp));
			} else if (x / p[j] < p[j])
				break;
		if (x != 1) ans = max(ans, dfs(i, 0, x, tmp));
	}
	cout << ans << endl;
	return 0;
}