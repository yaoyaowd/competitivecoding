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
int r, c;

int main() {
  freopen("in.txt", "r", stdin);
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cin >> r >> c;
    cout << "Case #" << i << ":" << endl;
    for (int x = 0; x < r + r + 1; ++x) {
    for (int y = 0; y < c + c + 1; ++y)
      if (x<2 && y <2) cout << ".";
      else if (x%2 == 0) {
        if (y%2 == 0) cout << "+";
        else cout << "-";
      } else {
          if (y % 2 ==0) cout <<"|";
          else cout << ".";
      }
      cout << endl;
    }
  }
}
