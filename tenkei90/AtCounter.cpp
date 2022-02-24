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
int N;
string S;
ll mod = 1e9 + 7;
string At = "atcoder";

int main() {
  cin >> N >> S;
  vector<vector<ll>> dp(N, vector<ll>(7, 0));
  if (S.at(0) == 'a') dp[0][0] = 1;
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < 7; j++) {
      dp[i][j] = dp[i - 1][j];
      if (S.at(i) == At.at(j)) {
        if (j != 0) {
          dp[i][j] = dp[i - 1][j] % mod + dp[i - 1][j - 1] % mod;
          dp[i][j] %= mod;
        } else {
          dp[i][0] = dp[i - 1][0] % mod + 1;
          dp[i][0] %= mod;
        }
      }
    }
  }
  cout << dp[N - 1][6] << endl;
}