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
#define maxn 200010
#define maxk 101
#define maxm 500010
#define maxq 500010
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int t;
int k;
string a, b, s;
int tt[30];
int c[30];
int stt[30];
int tc[30];
int check[26*26*26 + 1];
vector<int> checkp;

void init() {
    cin >> k;
    cin >> s;
    cin >> a;
    cin >> b;
}

void solve2() {
    char ans[27] = "abcdefghijklmnopqrstuvwxyz";
    if (b >= a) {
        printf("YES\n");
        ans[s[0]-'a'] = a[0];
        ans[a[0]-'a'] = s[0];
        ans[k] = '\0';
        printf("%s\n", ans);
    } else {
        printf("NO\n");
    }
}

void solve() {
    if (s.length() == 1) {
        solve2();
        return;
    }
    checkp.clear();
    checkp.reserve(26*26*26);
    memset(check, 0, sizeof(check));
    for (int i = 0; i < s.length(); ++i) {
        int x=(s[i]-'a')*26*26+(a[i]-'a')*26+(b[i]-'a');
        if (check[x]==0) {check[x] = 1;
            checkp.pb(i);}
    }

    for (int i =0; i < 30; ++i) tt[i] = -1;
    for (int i = 0; i <30; ++i) stt[i] = -1;
    memset(c, 0, sizeof(c));

    bool ans = false;
    bool no_ans = false;
    int minc = 0;
    for (int ii =0; ii < checkp.size(); ++ii) {
        int i = checkp[ii];
        if (ans) {
            if (tt[s[i]-'a'] == -1) {
                for (int j = minc; j < k; ++j)
                    if (c[j] == 0) {
                        c[j] = 1;
                        tt[s[i]-'a'] = j;
                        minc = j;
                        break;
                    }
            }
        } else {
            bool has_choice = false;
            if (tt[s[i]-'a'] == -1) {
                for (int j = a[i] - 'a'; j < k; ++j)
                    if (c[j] == 0) {
                        c[j] = 1;
                        tt[s[i]-'a'] = j;
                        has_choice = true;
                        if (j > a[i]-'a') ans = true;
                        break;
                    }
            } else if (tt[s[i]-'a'] > a[i]-'a') {
                ans = true;
                has_choice = true;
            } else if (tt[s[i]-'a'] == a[i]-'a') {
                has_choice = true;
            }

            if (!has_choice) {
                int last = -1;
                int change = 0;
                for (int j = 0; j < k; ++j) {
                    if (stt[j] > last) {
                        memset(tc, 0, sizeof(tc));
                        for (int x = 0; x < k; ++x)
                            if (stt[x] < stt[j] && stt[x] != -1) {
                                tc[tt[x]] = 1;
                            }
                        for (int x = tt[j] + 1; x<k; ++x)
                            if (tc[x] == 0) {
                                last = stt[j];
                                change = x;
                                break;
                            }
                    }
                }

                if (last == -1) {
                    no_ans = true;
                    break;
                }

                ans = true;
                memset(c, 0, sizeof(c));
                for (int j = 0; j < k; ++j) {
                    if (stt[j] != -1 && stt[j] < last) {
                        c[tt[j]] = 1;
                    } else if (stt[j] == last) {
                        tt[j] = change;
                        c[change] = 1;
                    } else if (stt[j] > last) {
                        c[tt[j]] = 0;
                        tt[j] = -1;
                    }
                }
                c[change] = 1;
                ii = last; // recalculate with ans = true.
            }
        }

        if (stt[s[i]-'a'] == -1) {
            stt[s[i]-'a'] = ii;
        }
    }

    if (no_ans) {
        printf("NO\n");
        return;
    }
    ans = true;
    for (int ii = 0; ii < checkp.size(); ++ii) {
        int i = checkp[ii];
        if (tt[s[i]-'a'] > b[i]-'a') {
            printf("NO\n");
            ans = false;
            return;
        } else if (tt[s[i]-'a'] < b[i]-'a') {
            break;
        }
    }
    char anst[27];
    if (ans) {
        printf("YES\n");
        for (int i = 0; i < k; ++i) {
            if (tt[i] == -1)
                for (int j = minc; j < k; ++j)
                    if (c[j] == 0) {
                        tt[i] = j;
                        c[j] =1;
                        minc = j;
                        break;
                    }
            anst[i] = tt[i] + 'a';
        }
        anst[k] = '\0';
        printf("%s\n", anst);
    }
}

int main(){
    cin >> t;
    while (t > 0) {
        t--;
        init();
        solve();
    }
    return 0;
}