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
#define maxn 1000010
#define maxm 500010
#define maxq 500010
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ull n, m;
vector<ull> a;

int main(){
    cin >> n >> m;
    for (int i = 0; i < m; ++i) a.pb(0);
    for (int i = 0; i < m; ++i) if (n >= i) {
        int mo = (i * i) % m;
        a[mo] += (n - i) / m;
        if (i > 0) a[mo] += 1;
    }
    ull ans = 0;
    for (int i = 0; i < m; ++i) {
        ans += a[i] * a[(m - i) % m];
        // cout << i << " " << m << " " << a[i] << " " << a[m-i] << endl;
    }
    cout << ans << endl;
    return 0;
}