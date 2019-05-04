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
vector<vector<int> > a;
vector<int> c;
int ans[maxn];

int count_subtrees(int u, int f) {
    int siz = 0;
    bool is_leaf = true;
    for (int i = 0; i < a[u].size(); ++i) {
        int v = a[u][i];
        if (v != f) {
            is_leaf = false;
            siz += count_subtrees(v, u);
        }
    }
    if (is_leaf) {
        c.pb(1);
        return 1;
    } else {
        c.pb(siz);
        return siz;
    }
}

int main(){
    cin >> n;
    a.resize(n + 1);
    for (int i = 0; i < n-1; ++i) {
        int u;
        cin >> u;
        a[u].pb(i+2);
        a[i+2].pb(u);
    }
    count_subtrees(1, 0);
    sort(c.begin(), c.end());
    int cur = 0;
    int id = 0;
    for (int i = 1; i <= n; ++i) {
        while (id < i) {
            cur += 1;
            while (id < n && c[id] <= cur) id += 1; 
        }
        ans[i] = cur;
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
    cout << endl;
    return 0;
}