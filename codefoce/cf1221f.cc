#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 500010;
const ll inf = 1e18;
const ll mod = 1000000007;

ll lazy[4 * maxn];
pair<ll, int> mx[4 * maxn];

void push_down(int p) {
  lazy[p << 1] += lazy[p];
  mx[p << 1].first += lazy[p];
  lazy[p + p + 1] += lazy[p];
  mx[p + p + 1].first += lazy[p];
  lazy[p] = 0;
}

void build(int p, int l, int r) {
  if (r - l == 1) {
    mx[p].second = 1;
    return;
  }
  int mid = (l + r) >> 1;
  build(p + p, l, mid);
  build(p + p + 1, mid, r);
  mx[p] = max(mx[p * 2], mx[p * 2 + 1]);
}

void range_add(int p, int l, int r, int x, int y, ll c) {
  if (l >= y || r <= x)
    return;
  if (l >= x && r <= y) {
    lazy[p] += c;
    mx[p].first += c;
    return;
  }
  int mid = (l + r) >> 1;
  push_down(p);
  range_add(p + p, l, mid, x, y, c);
  range_add(p + p + 1, mid, r, x, y, c);
  mx[p] = max(mx[p * 2], mx[p * 2 + 1]);
}

pair<ll, int> range_max(int p, int l, int r, int x, int y) {
  if (l >= y || r <= x)
    return {-inf, 0};
  if (l >= x && r <= y) {
    return mx[p];
  }
  int mid = (l + r) >> 1;
  push_down(p);
  return max(range_max(p + p, l, mid, x, y), range_max(p + p + 1, mid, r, x, y));
}

int main() {
  freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<int> x(n), y(n), c(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i] >> c[i];
    if (x[i] > y[i]) {
      swap(x[i], y[i]);
    }
  }

  vector<int> vx = x, vy = y;
  sort(vx.begin(), vx.end());
  sort(vy.begin(), vy.end());
  vx.resize(unique(vx.begin(),vx.end())-vx.begin());
  vy.resize(unique(vy.begin(),vy.end())-vy.begin());
  vector<vector<int>> yi(vy.size());
  for (int i = 0; i < n; ++i) {
    x[i]=lower_bound(vx.begin(),vx.end(),x[i])-vx.begin();
    y[i]=lower_bound(vy.begin(),vy.end(),y[i])-vy.begin();
    yi[y[i]].push_back(i);
  }

  build(1, 0, vx.size());
  for (int i = 0; i < vx.size(); ++i)
    range_add(1, 0, vx.size(), i, i + 1, vx[i]);

   LL ans=0;
    int l=2e9,r=l;
    for(int i=0;i<vy.size();++i){
        for(int j:yi[i]){
            rangeAdd(1,0,vx.size(),0,x[j]+1,c[j]);
        }
        auto res=rangeMax(1,0,vx.size(),0,upper_bound(vx.begin(),vx.end(),vy[i])-vx.begin());
        if(res.first-vy[i]>ans){
            ans=res.first-vy[i];
            l=vx[res.second];
            r=vy[i];
        }
    }
    cout<<ans<<endl;
    cout<<l<<' '<<l<<' '<<r<<' '<<r<<endl;
  return 0;
}
