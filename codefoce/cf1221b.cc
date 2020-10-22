#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1000010;
const ll mod = 1000000007;

int n;
vector<int> a;

int main() {
  freopen("in.txt", "r", stdin);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      if ((i + j) % 2 == 0) cout << "W";
      else cout << "B";
    cout << endl;
  }
  return 0;
}
