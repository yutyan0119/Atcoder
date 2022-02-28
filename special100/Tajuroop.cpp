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

ll modkaijo(ll a) {
  ll res = 1;
  for (ll i = 1; i <= a; i++) {
    res *= i;
    res %= mod;
  }
  return res;
}

ll modinv(ll a, ll p) {
  if (p == 0)
    return 1;
  else if (p == 1)
    return a % mod;
  else if (p == 2)
    return a * a % mod;
  else if (p % 2 == 0)
    return modinv(modinv(a, p / 2), 2) % mod;
  else
    return modinv(modinv(a, p / 2), 2) % mod * a % mod;
}

int main() {
  ll n, k;
  cin >> n >> k;
  ll n_k = modkaijo(n + k - 1) % mod;
  n = modinv(modkaijo(n - 1) % mod, mod - 2) % mod;
  k = modinv(modkaijo(k) % mod, mod - 2) % mod;
  cout << (n_k * n) % mod * k % mod << endl;
}