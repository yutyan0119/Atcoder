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

#define rep(i1, s, e) for (int i1 = s; i1 < e; i1++)

typedef long long ll;

/* ---------------------------------------------------*/

const ll mod = 10007;

vector<vector<ll>> mul_mat(vector<vector<ll>> mat, vector<vector<ll>> mat2) {
  vector<vector<ll>> res(3, vector<ll>(3, 0));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        res[i][j] += mat[i][k] * mat2[k][j];
        res[i][j] %= mod;
      }
    }
  }
  return res;
}

vector<vector<ll>> powmod_mat(vector<vector<ll>> m, ll n) {
  vector<vector<ll>> res;
  if (n == 1) {
    return m;
  } else if (n == 2) {
    res = mul_mat(m, m);
    return res;
  } else if (n % 2 == 0) {
    res = powmod_mat(powmod_mat(m, n / 2), 2);
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        res[i][j] %= mod;
      }
    }
    return res;
  } else {
    res = mul_mat(powmod_mat(powmod_mat(m, n / 2), 2), m);
    return res;
  }
}

int main() {
  ll n;
  cin >> n;
  n--;
  vector<vector<ll>> mat = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
  ll ans = 0;
  if (n == 0 || n == 1) {
    cout << 0 << endl;
    return 0;
  } else if (n == 2) {
    cout << 1 << endl;
    return 0;
  }
  auto k = powmod_mat(mat, n - 2);
  ans = k.at(0).at(0);
  cout << ans << endl;
  return 0;
}