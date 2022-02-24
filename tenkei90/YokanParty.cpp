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
ll N, L, K;
vector<ll> yokan;

bool solve(ll mid) {
  ll count = 0, pre = 0;
  for (ll i = 0; i <= N; i++) {
    if (yokan[i] - pre >= mid && L - yokan[i] >= mid) {
      count++;
      pre = yokan[i];
    }
  }
  if (count >= K) return true;
  return false;
}

int main() {
  cin >> N >> L >> K;
  yokan.assign(N, 0);
  for (ll i = 0; i < N; i++) {
    cin >> yokan[i];
  }

  ll wa = L + 1;
  ll ac = -1;

  while (wa - ac > 1) {
    ll mid = (wa + ac) / 2;
    if (solve(mid))
      ac = mid;
    else
      wa = mid;
  }
  cout << ac << endl;
}