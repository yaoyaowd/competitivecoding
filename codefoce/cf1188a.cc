#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 7;

int n;
int d[maxn];

int main(int argc, char* argv[]) {
    freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        d[u]++;
        d[v]++;
    }
    for (int i = 1; i <= n; ++i)
        if (d[i] == 2) {
            cout <<"NO" << endl;
            return 0;
        }
    cout <<"YES"<<endl;
    return 0;
}