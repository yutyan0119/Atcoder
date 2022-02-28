#include <bits/stdc++.h>
using namespace std;

template <typename T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

template <typename T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

#define rep(i, s, e) for (int i = s; i < e; i++)

typedef long long ll;

struct UnionFind {
  vector<int> par, siz;
  UnionFind(int n) {
    par.assign(n, -1);
    siz.assign(n, 1);
  }
  int root(int x) {
    if (par[x] == -1)
      return x;
    else
      return par[x] = root(par[x]);
  }

  bool issame(int x, int y) { return root(x) == root(y); }

  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (siz[x] < siz[y]) {
      swap(x, y);
    }
    par[y] = x;
    siz[x] += siz[y];
    return true;
  }

  int size(int x) { return siz[x]; }
};

/* ---------------------------------------------------*/
ll mod = 1e9 + 7;

ll modinv(ll a, ll m) {
  ll b = m, u = 1, v = 0;  // ax+b(m)y=1となるxを求める。
  while (b) {
    ll t = a / b;
    a -= t * b;  // aをbの倍数分引く
    swap(a, b);  // aとbを交換
    u -= t * v;  // uをvの倍数分引く
    swap(u, v);  // uとvを交換
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}

ll modinv2(ll a, ll p) {
  if (p == 1)
    return a % mod;
  else if (p == 2)
    return (a * a) % mod;
  else if (p % 2 == 0)
    return modinv2(modinv2(a, p / 2) % mod, 2);
  else
    return modinv2(modinv2(a, p / 2) % mod, 2) * a % mod;
}

ll kaijomod(ll a) {
  if (a == 1 || a == 0) return 1;
  return kaijomod(a - 1) * a % mod;
}

int main() {
  int W, H;
  cin >> W >> H;
  //求めるのは(W+H-2)!/(W-1)!(H-1)!->(W-1)!の逆元と(H-1)!の逆元を求めて(W+H-2)!かけてmod取る
  //案1:p=1e9+7が素数だからおとなしくp-2乗して求める（easy）
  //案2:pは当然素数で(H-1)や(W-1)とは互いに素なのでユークリッドの互除法を使う
  ll w_1 = kaijomod(W - 1);
  ll h_1 = kaijomod(H - 1);
  ll w_h_2 = kaijomod(W + H - 2) % mod;
  w_1 = modinv(w_1, mod) % mod;
  h_1 = modinv(h_1, mod) % mod;
  cout << (w_h_2 * w_1) % mod * h_1 % mod << endl;
}