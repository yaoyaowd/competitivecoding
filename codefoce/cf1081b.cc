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
#define maxn 100010
#define maxk 101
#define maxm 500010
#define maxq 500010
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n;
vector<int> a;
vector<vector<int>> b;
vector<int> ans;

int main(){
    scanf("%d", &n);
    a.resize(n);
    b.resize(n);
    ans.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        b[a[i]].pb(i);
    }

    bool has_ans = true;
    int c = 1;
    for (int i = 0; i < n; ++i) {
        if (b[i].size() >= 0) {
            int st = 0;
            while (b[i].size() > st) {
                has_ans &= (b[i].size() >= n-i);
                if (!has_ans) break;

                for (int j = st; j < st + n - i; ++j) ans[b[i][j]] = c;
                c++;
                st += n-i;
            }
            if (!has_ans) break;
        }
    }
    for (int i = 0; i < n; ++i) if (ans[i] == 0) has_ans = false;

    if (!has_ans) {
        cout << "Impossible" << endl;
    } else {
        cout << "Possible" << endl;
        for (int i = 0; i < n; ++i) {
            if (i > 0) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}