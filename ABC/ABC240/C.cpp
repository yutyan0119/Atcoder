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
  ll N, X;
  cin >> N >> X;
  vector<ll> a(N);
  vector<ll> b(N);
  vector<set<ll>> position(N + 1);
  position[0].insert(0);
  for (int i = 0; i < N; i++) {
    cin >> a[i] >> b[i];
    for (auto x : position[i]) {
      position[i + 1].insert(x + a[i]);
      position[i + 1].insert(x + b[i]);
    }
  }
  if (position[N].find(X) != position[N].end()) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}