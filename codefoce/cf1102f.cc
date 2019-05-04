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
#define maxn 500010
#define maxk 101
#define maxm 500010
#define maxq 500010
#define inf 1000000000
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n, m;
vector<int> a[20];
int ab[20][20]; // b follow a.
int ba[20][20];
int f[16][16][1 << 16];
bool c[16 * 16 * (1 << 16)];
vector<int> q;

int h(int s, int d, int b) {
	return s * n * (1<<n) + d * (1<<n) + b;
}

void solve() {
	memset(f, 0, sizeof(f));
	memset(c, 0, sizeof(c));
	for (int i = 0; i < n; ++i) {
		f[i][i][1 << i] = inf;
		c[h(i, i, 1<<i)] = true;
		q.pb(h(i, i, 1<<i));
	}
	int st = 0;
	while (st < q.size()) {
		int s = q[st] / n / (1 << n);
		int e = (q[st] / (1 << n)) % n;
		int d = q[st] % (1 << n);
		for (int j = 0; j < n; ++j)
			if (((d >> j) & 1) == 0) {
				int v = f[s][e][d];
				v = min(v, ab[e][j]);
				if (v >= f[s][j][d | (1 << j)]) {
					f[s][j][d | (1 << j)] = v;
					if (!c[h(s, j, d | (1 << j))]) {
						q.pb(h(s, j, d | (1 << j)));
					}
				}
			}
		st++;
	}
	int ans = 0;
	if (n == 1) ans = ba[0][0];
	else {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (i != j)
					ans = max(ans, min(ba[j][i], f[i][j][(1 << n) - 1]));
	}
	cout << ans << endl;
}

void init() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		a[i].resize(m);
		for (int j = 0; j < m; ++j) scanf("%d", &a[i][j]);
	}
}

void prepare() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ab[i][j] = abs(a[i][0] - a[j][0]);
			for (int t = 1; t < m; ++t)
				ab[i][j] = min(ab[i][j], abs(a[i][t] - a[j][t]));
			ba[i][j] = inf;
			for (int t = 1; t < m; ++t)
				ba[i][j] = min(ba[i][j], abs(a[i][t-1] - a[j][t]));
		}
	}
}

int main() {
	init();
	prepare();
	solve();
	return 0;
}