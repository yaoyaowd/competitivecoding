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
#define maxn 400010
#define mod 998244353
typedef long long ll;
typedef unsigned long long ull;
const ll inf = (ll)(1e18+7);

using namespace std;

int w, h;
vector<string> a;

bool check(int x, int y) {
  a[x][y] = '.';
  for (int i = x - 1; i >= 0; --i)
    if (a[i][y] == '*')
      a[i][y] = '.';
    else
      break;
  for (int i = x + 1; i < h; ++i)
    if (a[i][y] == '*')
      a[i][y] = '.';
    else
      break;
  for (int j = y - 1; j >= 0; --j)
    if (a[x][j] == '*')
      a[x][j] = '.';
    else
      break;
  for (int j = y + 1; j < w; ++j)
    if (a[x][j] == '*')
      a[x][j] = '.';
    else
      break;
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j)
      if (a[i][j] != '.') {
        return false;
      }
  return true;
}

int main()
{
  cin >> h >> w;
  a.resize(h);
  for (int i = 0; i < h; ++i)
    cin >> a[i];
  for (int i = 1; i < h - 1; ++i)
    for (int j = 1; j < w - 1; ++j)
      if (a[i][j] == '*' && a[i-1][j] == '*' && a[i+1][j] == '*' && a[i][j-1] == '*' && a[i][j + 1] == '*') {
        if (check(i, j)) {
          cout << "YES" << endl;
          return 0;
        } else {
          cout << "NO" << endl;
          return 0;
        }
      }
  cout << "NO" << endl;
  return 0;
}
