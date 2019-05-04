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
#define mod 1000000007
// #define mod 998244353
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 301000;
const ll inf = (ll)(1e18+7);

using namespace std;

int t;
int n;
string s;

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cin >> n;
    cin >> s;
    cout << "Case #" << i << ": ";
    for (int j = 0; j < n + n - 2; ++j) {
      if (s[j] == 'E') {
        cout << "S";
      } else {
        cout << "E";
      }
    }
    cout << endl;
  }
}