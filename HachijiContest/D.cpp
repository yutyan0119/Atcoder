#include <bits/stdc++.h>
using namespace std;

template <typename T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <typename T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;
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
  ll N, X;
  cin >> N >> X;
  vector<vector<ll>> P(N);
  vector<vector<ll>> Q(N);
  vector<bool> complete(N);
  vector<ll> K(N);
  vector<ll> T(N);
  vector<ll> stack;
  for (ll i = 0; i < N; i++) {
    cin >> T[i] >> K[i];
    if (K[i] == 0) {
      stack.push_back(K[i]);
    }
    for (ll j = 0; j < K[i]; j++) {
      ll p;
      cin >> p;
      p--;
      P[i].push_back(p);
      Q[p].push_back(i);
    }
  }
  ll now_time = 0;
  ll completetask = 0;
  while (now_time <= X + 0.5 || !stack.empty()) {
    ll pretime = now_time;
    ll plustime = 0;
    while (!stack.empty()) {
      ll x = stack.back();
      stack.pop_back();
      for (auto y : Q[x]) {
        K[y]--;
        if (K[y] == 0) stack.push_back(y);
      }
    }
  }
}
}