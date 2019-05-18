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
#include <assert.h>

#define pb push_back
#define mp make_pair
#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)
#define EPS 1e-6
#define INF 1000000010
#define pi acos(-1.0)
#define mod 1000000007
// #define mod 998244353
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 301000;
const ll inf = (ll)(1e18+7);

using namespace std;

int n;
string s;

bool check(string s) {
  for (int i = 0; i < s.length() - 1; ++i)
    if (abs(s[i] - s[i + 1]) == 1)
      return false;
  return true;
}

int main() {
  // freopen("in.txt", "r", stdin);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    string odd;
    string even;
    for (int j = 0; j < s.length(); ++j) {
      if (s[j] % 2 == 0) {
        odd += s[j];
      } else {
        even += s[j];
      }
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    if (check(odd + even)) {
      cout << odd + even << endl;
    } else if (check(even + odd)) {
      cout << even + odd << endl;
    } else {
      cout << "No answer" << endl;
    }
  }
}