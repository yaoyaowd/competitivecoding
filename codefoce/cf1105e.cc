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
#define mod 998244353
#define maxn 100060
#define maxk 101
#define maxm 500010
#define maxq 500010
#define inf 1000000000
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n, m, na, nb;
map<string, int> a;
vector<int> e[maxn];
int b[50][50];
int f[1 << 20];
int g[1 << 20];

void init() {
	string name;
	na = 0;
	nb = 0;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (x == 1) {
			na++;
			e[na].resize(41);
		} else if (x == 2) {
			cin >> name;
			if (a.find(name) == a.end()) {
				a[name] = nb;
				nb++;
			}
			int id = a[name];
			if (na != 0) {
				e[na][id] = 1;
			}
		}
	}
	memset(b, 0, sizeof(b));
	for (int i = 1; i <= na; ++i) {
		for (int u = 0; u < nb; ++u)
			for (int v = 0; v < nb; ++v)
				if (u != v && e[i][u] && e[i][v]) {
					b[u][v] = b[v][u] = 1;
				}
	}
}

int mask[50];

void bitmask(int st, int ed, int* f) {
	memset(mask, 0, sizeof(mask));
	for (int i = st; i < ed; ++i)
		for (int j = st; j < ed; ++j)
			if (b[i][j])
				mask[i] |= (1 << (j - st));

	int maxbit = 1 << (ed - st);
	for (int i = 1; i < maxbit; ++i) {
		int id = 0;
		for (int j = st; j < ed; ++j)
			if (i & (1 << (j - st))) {
				id = j;
				break;
			}

		int left = i - (1 << (id - st));
		f[i] = f[left];
		int ma = left & ((maxbit - 1) - mask[id]);
		if (1 + f[ma] > f[i]) {
			f[i] = 1 + f[ma];
		}
	}
}

void solve() {
	bitmask(0, min(nb, 20), f);
	if (nb > 20) {
		bitmask(20, nb, g);
	}

	if (nb <= 20) {
		int ans = 0;
		for (int i = 0; i < (1 << nb); ++i) {
			ans = max(ans, f[i]);
		}
		cout << ans << endl;
	} else {
		memset(mask, 0, sizeof(mask));
		for (int i = 0; i < 20; ++i)
			for (int j = 20; j < nb; ++j)
				if (b[i][j])
					mask[i] |= (1 << (j - 20));

		int ans = 0;
		for (int i = 0; i < (1 << 20); ++i) {
			int j = (1 << (nb - 20)) - 1;
			int ma = j;
			for (int t = 0; t < 20; ++t)
				if (i & (1 << t)) {
					j = j & (ma - mask[t]);
				}
			ans = max(ans, f[i] + g[j]);
		}
		cout << ans << endl;
	}
}

int main() {
	init();
	solve();
	return 0;
}