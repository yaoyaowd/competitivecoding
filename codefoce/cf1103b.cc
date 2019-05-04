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
#define maxn 100060
#define maxk 101
#define maxm 500010
#define maxq 500010
#define inf 1000000000
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

string s;

bool xGreat(int l, int r) {
	printf("? %d %d\n", l, r);
	fflush(stdout);
	cin >> s;
	return s == "x";
}

void solve() {
	int l = 1, r = 2;
	while (!xGreat(l, r)) {
		l = r;
		r <<= 1;
	}
	if (l == 1) {
		if (xGreat(2, 3)) {
			printf("! 1\n");
			fflush(stdout);
		} else {
			printf("! 2\n");
			fflush(stdout);
		}
		return;
	}
	
	int x = l;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (xGreat(x, mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	printf("! %d\n", r);
	fflush(stdout);
}

int main() {
	while (true) {
		cin >> s;
		if (s == "start") {
			solve();
		} else {
			break;
		}
	}
	return 0;
}