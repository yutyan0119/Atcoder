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

ll powmod(ll a, ll b) {
  if (b == 0) {
    return 1;
  }
  if (b == 1) {
    return a % mod;
  }
  if (b == 2) {
    return a * a % mod;
  }
  if (b % 2 == 0) {
    return powmod(powmod(a, b / 2) % mod, 2) % mod;
  }
  if (b % 2 == 1) {
    return (powmod(powmod(a, b / 2) % mod, 2) * a) % mod;
  }
  return 0;
}

int main() {
  ll N, Q;
  cin >> N >> Q;
  vector<ll> a(N + 1, 0);
  vector<ll> c(Q + 2, 0);
  ll res = 0;
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }
  c[0] = 1;
  c[Q + 1] = 1;
  for (int i = 1; i <= Q; i++) {
    cin >> c[i];
  }
  vector<ll> root(N + 1, 0);  // root[i]は1から街iに行くのに必要な距離

  for (int h = 2; h <= N; h++) {
    ll e = a[h - 1];
    ll f = a[h];
    root[h] = root[h - 1] + powmod(e, f);
    root[h] %= mod;
  }

  for (int i = 1; i <= Q + 1; i++) {
    res += (abs(root[c[i]] - root[c[i - 1]]) + mod * 2) % mod;
    res %= mod;
  }
  cout << res << "\n";
}