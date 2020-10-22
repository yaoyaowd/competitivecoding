#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 200010;
const int inf = 1e8;
const int mod = 1000000007;

vector<int> a[200010];
int n;
int b[2];

void dfs(int u, int fa, int depth) {
    b[depth % 2] += 1;
    for (int v : a[u])
        if (v != fa) {
            dfs(v, u, depth + 1);
        }
}

int main() {
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    b[0] = 0;
    b[1] = 0;
    dfs(1, 0, 0);

    cout << std::min(b[0], b[1]) - 1 << endl;

    return 0;
}
