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

int n, m, k;
vector<int> a[maxn];
int depth[maxn];
bool visited[maxn];
bool is_leaf[maxn];
int parent[maxn];
int max_depth_id;

void dfs(int u, int p) {
	visited[u] = true;
	parent[u] = p;
	is_leaf[u] = true;
	for (int v : a[u]) {
		if (visited[v]) continue;
		depth[v] = depth[u] + 1;
		dfs(v, u);
		is_leaf[u] = false;
	}
	if (depth[u] > depth[max_depth_id])
		max_depth_id = u;
}

int main() {
	cin >> n >> m >> k;
	if (n == 1) {
		cout << "PATH\n1\n1\n";
		return 0;
	}
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}

	depth[1] = 1;
	dfs(1, -1);

	int b = (n + k - 1) / k;
	if (depth[max_depth_id] >= b) {
		vector<int> ans;
		ans.pb(max_depth_id);
		while (max_depth_id != 1) {
			max_depth_id = parent[max_depth_id];
			ans.pb(max_depth_id);
		}
		cout << "PATH\n";
		cout << ans.size() << endl;
		for (int u : ans) cout << u << " ";
		cout << endl;
		return 0;
	}

	vector<vector<int> > ans;
	for (int u = 1; u <= n; ++u) {
		if (!is_leaf[u])
			continue;
		vector<int> e;
		for (int v : a[u]) {
			if (v == parent[u])
				continue;
			e.pb(v);
		}

		bool found = false;
		for (int v : e) {
			int l = depth[u] - depth[v] + 1;
			if (l % 3 == 0)
				continue;
			found= true;

			vector<int> c;
			c.pb(u);
			while (c.back() != v) {
				c.pb(parent[c.back()]);
			}
			ans.pb(c);
			break;
		}

		if (!found) {
			int st = e[0];
			int ed = e[1];
			if (depth[st] < depth[ed]) {
				swap(st, ed);
			}
			vector<int> c;
			c.pb(u);
			c.pb(st);
			while (c.back() != ed) {
				c.pb(parent[c.back()]);
			}
			ans.pb(c);
		}
	}

	cout << "CYCLES\n";
	for (int i = 0; i < k && i < ans.size(); ++i) {
		cout << ans[i].size() << endl;
		for (int u : ans[i]) cout << u << " ";
		cout << endl;
	}
	return 0;
}