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
const ll mod = (ll)1e9 + 7;

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
  vector<ll> a(N, 0);
  vector<ll> c(Q, 0);
  ll res = 0;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < Q; i++) {
    cin >> c[i];
    c[i]--;
  }
  vector<ll> root2(N, 0);
  for (int i = 1; i < N; i++) {
    root2[i] = powmod(a[i - 1], a[i]);
    // cout << root2[i] << endl;
  }
  vector<ll> root(N,0);
  for (int i = 1; i < N; i++) {
    root[i] = (root[i-1] + root2[i]) % mod;
    // cout << root[i] << "\n";
  }
  res = root[c[0]] % mod;
  for (int i = 1; i < Q; i++) {
    ll x = min(c[i - 1], c[i]);
    ll y = max(c[i - 1], c[i]);
    res += (root[y] - root[x] + mod * 2) % mod;
    res %= mod;
  }
  res += root[c[Q - 1]] % mod;
  cout << res % mod << "\n";
}