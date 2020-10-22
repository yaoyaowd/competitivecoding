#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 300010;
const int inf = 1e8;
const int mod = 1000000007;

int main() {
  freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int minc = 27;
  std::string s;
  cin >> s;
  for (int i = 0; i < s.length(); ++i) {
  	int v = s[i] - 'a';
  	if (v <= minc || i == 0) {
  		minc = v;
  		cout << "Mike" << endl;
  	} else {
  		cout << "Ann" << endl;
  	}
  }

  return 0;
}
