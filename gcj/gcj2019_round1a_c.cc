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
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 301000;
const ll inf = (ll)(1e18+7);

using namespace std;

int n;
vector<string> a;
set<string> ans;
int b[1010];
int c[1010];
int ed = 0;

int compare(int i, int j) {
	for (int t = 0; t < a[i].length() && t < a[j].length(); ++t)
		if (a[i][t] != a[j][t]) {
			return t;
		}
	return min(a[i].length(), a[j].length());
}
int solve() {
	cin >> n;
	a.clear();
	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		a.emplace_back(s.rbegin(), s.rend());
	}
	sort(a.begin(), a.end());

	ans.clear();
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	for (int i = 0; i < n; ++i) {
		b[i] = i;
		if (i > 0) c[i] = compare(i - 1, i);
	}
	int count = n;
	while (count >= 0) {
		int jmax = 0;
		for (int j = 1; j < count; ++j)
			if (c[j] > c[jmax])
				jmax = j;
		if (c[jmax] == 0)
			break;
		ans.insert(a[b[jmax]].substr(0, c[jmax]));
		for (int j = jmax + 1; j < count; ++j) {
			b[j - 2] = b[j];
			c[j - 2] = c[j];
		}
		count -= 2;
		if (jmax > 1) {
			c[jmax - 1] = compare(b[jmax - 2], b[jmax - 1]);
		} else {
			c[0] = 0;
		}
	}
	return ans.size() * 2;
}

int main() {
	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	for (int i = 1; i <=t; ++i) {
		cout << "Case #" << i << ": " << solve() << endl;
	}
}