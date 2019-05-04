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
char c[maxn];
int a[maxn];

int m;
int ua[maxn];
multiset<int> s;

ll b[maxn];

void add(int id, int x) {
    id++;
    for (; id <= m; id += id & (-id))
        b[id] += x;
}

ll query(int id) {
    id++;
    ll ret = 0;
    for (; id; id ^= id & (-id))
        ret += b[id];
    return ret;
}

int solve() {
    if (s.size() <= 1) return 0;
    auto x = s.begin();
    int cnt = 0;
    while (x != s.end()) {
        int id = lower_bound(ua, ua + m, *x) - ua;
        if (x != s.begin()) {
            ll sum = query(id - 1);
            if (sum * 2 < *x) cnt++;
        }
        ll sum = query(id);
        x = s.upper_bound(sum * 2);
        if (x == s.end()) break;
    }
    return s.size() - cnt - 1;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c[i] >> a[i];
    }
    memcpy(ua, a, sizeof(a));
    sort(ua, ua + n);
    m = unique(ua, ua + n) - ua;

    for (int i = 0; i < n; ++i) {
        int id = lower_bound(ua, ua + m, a[i]) - ua;
        if (c[i] == '+') {
            s.insert(a[i]);
            add(id, a[i]);
            printf("%d\n", solve());
        } else {
            multiset<int>::iterator it = s.find(a[i]);
            s.erase(it);
            add(id, -a[i]);
            printf("%d\n", solve());
        }
    }
}