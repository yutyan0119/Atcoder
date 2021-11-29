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

int main() {
  int N;
  cin >> N;
  vector<ll> H(N), S(N);
  for (int i = 0; i < N; i++) {
    cin >> H[i] >> S[i];
  }
  ll l = 0;
  ll r = 1e15;
  while (r - l > 1) {
    ll mid = (l + r) / 2;
    bool ok = true;
    vector<ll> t(N, 0);
    for (int i = 0; i < N; i++) {
      if (mid < H[i]) {
        ok = false;
      } else {
        t[i] = (mid - H[i]) / S[i];
      }
    }
    sort(t.begin(), t.end());
    for (int j = 0; j < N; j++) {
      if (t[j] < j) {  // iはその風船が最も早く割られる秒数を示している
        ok = false;  //それよりt[i]が小さければ無理。
      }
    }
    if (ok) {
      r = mid;  //行けるときは、もっと上を探りたい
    } else {
      l = mid;  //無理なときはちょっと下げてあげる
    }
  }
  cout << r << endl;
}