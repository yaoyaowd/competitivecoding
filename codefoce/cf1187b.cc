#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 7;

int n,t;
string s;
string name;
int nc[26];
int a[maxn][26];

void prepare() {
    memset(a, 0, sizeof(a));
    for (int i = 0; i < s.length(); ++i) {
        if (i > 0) {
            for (int j = 0; j < 26; ++j)
                a[i][j] = a[i - 1][j];
        }
        a[i][s[i] - 'a'] += 1;
    }
}

int solve() {
    memset(nc, 0, sizeof(nc));
    for (int i = 0; i < name.length(); ++i)
        nc[name[i]-'a']++;
    int l = 0, r = n - 1;
    while (l < r) {
        int m = (l + r) / 2;
        bool suc = true;
        for (int j = 0; j < 26; ++j)
            if (a[m][j] < nc[j]) {
                suc = false;
            }
        if (!suc)
            l = m + 1;
        else
            r = m;
    }
    return l + 1;
}

int main(int argc, char* argv[]) {
    cin >> n;
    cin >> s;
    prepare();
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> name;
        cout << solve() << endl;
    }
    return 0;
}