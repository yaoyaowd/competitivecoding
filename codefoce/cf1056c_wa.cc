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
int m;
vector<pair<int, int> > a;
int pp[2010];
int power[2010];
bool check[2010];
int t;

int pc(int& st) {
    for (int i = st; i <= n + n; ++i)
        if (pp[i] != 0 && !check[i]) {
            st = i;
            int u = i, v = pp[i];
            if (power[u] > power[v])
                return u;
            else
                return v;
        }
    return -1;
}

void diy(int k) {
    int left = n + n;
    if (k != -1) left -= 1;

    while (k != -1 && pp[k] != 0) {
        check[k] = true;
        check[pp[k]] = true;
        printf("%d\n", pp[k]);
        left--;
        fflush(stdout);
        if (left > 0) {
            scanf("%d", &k);
            left--;
        }
    }
    if (k != -1) check[k] = true;

    sort(a.begin(), a.end());

    int st = 1;
    int pair_choice = pc(st);
    while (pair_choice != -1) {
        check[pair_choice] = true;
        printf("%d\n", pair_choice);
        left--;
        fflush(stdout);
        if (left > 0) {
            scanf("%d", &k);
            left--;
            check[k] = true;
        }
        pair_choice = pc(st);
    }

    for (int i = n + n - 1; i >= 0; i--) {
        if (!check[a[i].second]) {
            check[a[i].second] = true;
            printf("%d\n", a[i].second);
            left--;
            fflush(stdout);
            if (left > 0) {
                scanf("%d", &k);
                left--;
                check[k] = true;
            }
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    memset(check, 0, sizeof(check));
    for (int i = 0; i < n + n; ++i) {
        int p;
        scanf("%d", &p);
        power[i+1] = p;
        a.pb(mp(p, i+1));
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        pp[x] = y;
        pp[y] = x;
    }
    scanf("%d", &t);
    if (t == 1) {
        diy(-1);
    } else {
        int x;
        scanf("%d", &x);
        diy(x);
    }
    return 0;
}