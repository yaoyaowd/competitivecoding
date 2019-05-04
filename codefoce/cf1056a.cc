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
map<int, int> a;

int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int r;
        cin >> r;
        for (int j = 0; j < r; ++j) {
            int x;
            cin >> x;
            if (a.find(x) == a.end()) {
                a[x] = 1;
            } else {
                a[x] = a[x] + 1;
            }
        }
    }
    for (auto it : a) {
        if (it.second == n) cout << it.first << " ";
    }
    cout << endl;
    return 0;
}