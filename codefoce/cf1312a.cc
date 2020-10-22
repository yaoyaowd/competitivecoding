#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 300010;
const ll inf = 1e18;
const ll mod = 1000000007;

int t, m;
int n;
vector<int> a;

int main() {
  freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  for (int i = 0; i < t; ++i) {
  	cin >> n >> m;
  	if (n % m == 0) {
  		cout << "YES" << endl;
  	} else {
  		cout << "NO" << endl;
  	}
  }
  return 0;
}
