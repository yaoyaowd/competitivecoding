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
#define maxn 1100010
#define maxk 101
#define maxm 500010
#define maxq 500010
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n;
ll sum;
int a[maxn];
int c[maxn];

int solve(int value) {
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; ++i)
        c[a[i]]++;
    c[value]++;

    int less = 0;
    ll left = 0, right = 0;
    for (int k = 0, i = 0; k <= n; ++k) {
        int val = (i == k && (i == n || a[i] < value)) ? value : a[i++];
        left += val;
        --c[val];
        right -= min(val, k);
        less += c[k];
        right += n - k - less;
        if (left > right + (ll)(k + 1) * k) {
            return (i == k) ? 1 : -1;
        }
    }
    return 0;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    sort(a, a + n, greater<int>());
    
    int parity = sum & 1;
    int lo = 0, hi = (n - parity) / 2, lores = -1;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (solve(2 * mid + parity) < 0) {
            lo = mid + 1;
        } else {
            lores = mid;
            hi = mid - 1;
        }
    }

    lo = lores;
    hi = (n - parity) / 2;
    int hires = -1;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (solve(2 * mid + parity) > 0) {
            hi = mid - 1;
        } else {
            hires = mid;
            lo = mid + 1;
        }
    }

    if (lores == -1 || hires == -1) cout << -1 << endl;
    else {
        for (int i = lores; i <= hires; ++i) cout << 2 * i + parity << " ";
        cout << endl;
    }
    return 0;
}