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
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n;
vector<int> a;
unordered_map<int, int> l;

ll pow(ll b, ll p) {
	ll ret = 1;
	ll base = b;
	while (p != 0) {
		if (p & 1) {
			ret = (ret * base) % mod;
		}
		p >>= 1;
		base = (base * base) % mod;
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	a.resize(n + 1);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) l[a[i]] = i;
	int b = 0;
	int last = 1;
	for (int i = 1; i <= n; ++i) {
		if (i > last) {
			b += 1;
		}
		last = max(l[a[i]], last);
	}
	cout << pow((ll)2, (ll)b) << endl;
	return 0;
}