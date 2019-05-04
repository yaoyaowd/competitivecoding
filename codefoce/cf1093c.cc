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

int n;
vector<ll> b;
vector<ll> a;

int main(){
    cin >> n;
    b.resize(n / 2);
    for (int i = 0; i < n / 2; ++i) cin >> b[i];
    a.resize(n);
    a[0] = 0;
    a[n-1] = b[0];
    for (int i = 1; i < n / 2; ++i) {
        ll m0 = a[i-1];
        ll m1 = a[n-i];
        if (b[i]-m0>m1) {
            a[n-i-1] = m1;
            a[i] = b[i] - m1;
        } else {
            a[i] = m0;
            a[n-i-1] = b[i] - m0;
        }
    }

    cout << a[0];
    for (int i = 1; i < n; ++i) cout << " " << a[i];
    cout << endl;
    return 0;
}