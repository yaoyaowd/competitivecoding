#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 3e5 + 7;
const int mod = 998244353;

int n, root = 1;
vector<vector<pair<int, int>>> g;
vector<vector<int>> leaves;
vector<bool> visited;
vector<int> pr;
vector<vector<int>> ops;

void dfs1(int u) {
    visited[u] = true;
    for (auto it : g[u])
        if (!visited[it.first]) {
            pr[it.first] = u;
            dfs1(it.first);
            leaves[u].push_back(leaves[it.first][0]);
        }
    if (leaves[u].size() == 0) {
        leaves[u].push_back(u);
    }
}

void add_path(int v, int x) {
    if (leaves[v].size() == 1) {
        ops.push_back({root, v, x});
        return;
    }
    ops.push_back({root, leaves[v][0], x / 2});
    ops.push_back({root, leaves[v][1], x / 2});
    ops.push_back({leaves[v][0], leaves[v][1], -x / 2});
}

void add_edge(int v, int x) {
    if (pr[v] == root) {
        add_path(v, x);
        return;
    }
    add_path(v, x);
    add_path(pr[v], -x);
}

void dfs2(int u) {
    visited[u] = true;
    for (auto it : g[u])
        if (!visited[it.first]) {
            add_edge(it.first, it.second);
            dfs2(it.first);
        }
}

int main(int argc, char* argv[]) {
    freopen("in.txt", "r", stdin);
    cin >> n;
    g.resize(n + 1);
    leaves.resize(n + 1);
    visited.resize(n + 1);
    pr.resize(n + 1);

    int u, v, val;
    if (n == 2) {
        cin >> u >> v >> val;
        cout << "YES" << endl << 1 << endl;
        cout << u << " " << v << " " << val;
        return 0;
    }

    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v >> val;
        g[u].push_back(make_pair(v, val));
        g[v].push_back(make_pair(u, val));
    }

    for (int i = 1; i <= n; ++i)
        if (g[i].size() == 2) {
            cout <<"NO" << endl;
            return 0;
        }

    cout << "YES" << endl;
    while (g[root].size() != 1)
        root++;

    dfs1(root);
    visited = vector<bool>(n + 1);
    dfs2(root);
    cout << ops.size() << endl;
    for (int i = 0; i < ops.size(); ++i) {
        cout << ops[i][0] << " " << ops[i][1] << " " << ops[i][2] << endl;
    }
    return 0;
}