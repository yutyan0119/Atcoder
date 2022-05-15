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

int main() {
  ll N;
  cin >> N;
  ll K;
  vector<ll> score(K + 1, 0);
  vector<bool> half(N, false);
  vector<bool> full(N, false);
  vector<pair<ll, ll>> A(N);
  vector<pair<ll, ll>> B(N);
  for (ll i = 0; i < N; i++) {
    ll a, b;
    cin >> a >> b;
    A[i] = make_pair(a, i);
    B[i] = make_pair(b, i);
  }
  sort(A.rbegin(), A.rend());
  sort(B.rbegin(), B.rend());
  for (ll i = 1; i <= K; i++)
  {
    
  }
  
}