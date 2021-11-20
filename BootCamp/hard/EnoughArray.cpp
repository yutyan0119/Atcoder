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

/* ---------------------------------------------------*/

vector<ll> a(100010);
vector<ll> sum(100010);

ll get(int l, int r) {
  ll res = sum[r];
  if (0 < l) {
    res -= sum[l - 1];
  }
  return res;
}

int main() {
  ll N, K;
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  sum[0] = a[0];
  ll count = 0;
  for (int i = 1; i < N; i++) {
    sum[i] = sum[i - 1] + a[i];
  }
  int R = 0;
  for (int L = 0; L < N; L++) {
    chmax (R,L);
    while (R < N && get(L, R) < K) {
      R++;
    }
    count += N - R;
  }
  cout << count << endl;
}