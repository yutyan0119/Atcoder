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

ll ans = 0;
vector<ll> num;
ll N, P, Q;

void dfs(vector<ll> a, ll index) {
  num.push_back(a[index]);
  if (num.size() == 5) {
    ll tmp = 1;
    for (auto x : num) {
      tmp *= x;
      tmp %= P;
    }
    if (tmp == Q) {
      ans++;
    }
    return;
  } else {
    int size = num.size();
    for (int i = index + 1; i <= N - (5 - size); i++) {
      dfs(a, i);
      num.pop_back();
    }
  }
}

int main() {
  cin >> N >> P >> Q;
  vector<ll> a(N);
  for (ll i = 0; i < N; i++) {
    cin >> a[i];
  }
  // for (ll i = 0; i <= N - 5; i++) {
  //   dfs(a, i);
  //   num.pop_back();
  // }
  for (ll i = 0; i < N; i++) {
    for (ll j = i + 1; j < N; j++) {
      for (ll k = j + 1; k < N; k++) {
        for (ll l = k + 1; l < N; l++) {
          for (ll m = l + 1; m < N; m++) {
            ll tmp = 1;
            tmp *= a[i];
            tmp %= P;
            tmp *= a[j];
            tmp %= P;
            tmp *= a[k];
            tmp %= P;
            tmp *= a[l];
            tmp %= P;
            tmp *= a[m];
            tmp %= P;
            if (tmp % P == Q) ans++;
          }
        }
      }
    }
  }

  cout << ans << endl;
}