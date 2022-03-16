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

void EighttoTen(string& S) {
  string base = S;
  ll ans = 0;
  int n = base.size();
  for (int i = 0; i < n; i++) {
    ans += (base.at(i) - '0') * (ll)pow(8, n - i - 1);
  }
  S = to_string(ans);
}

void TentoNine(string& S) {
  ll num = stoll(S);
  S.clear();
  while (num) {
    S.insert(S.begin(), num % 9 + '0');
    num /= 9;
  }
}

void EighttoFive(string& S) {
  for (int i = 0; i < S.size(); i++) {
    if (S.at(i) == '8') {
      S.at(i) = '5';
    }
  }
}

int main() {
  string N;
  int K;
  cin >> N >> K;
  if (N == "0") {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < K; i++) {
    EighttoTen(N);
    TentoNine(N);
    EighttoFive(N);
  }
  cout << N << endl;
}