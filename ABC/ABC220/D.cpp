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
  ll N = pow(2, 20);
  set<ll> A;
  vector<pair<ll, ll>> B;
  int Q;
  cin >> Q;
  vector<ll> x(Q), t(Q);
  for (int i = 0; i < Q; i++) {
    cin >> t[i] >> x[i];
  }
  for (int i = 0; i < Q; i++) {
    if (t[i] == 1) {
      ll h = x[i];
      ll modN = h % N;
      while (A.find(modN) != A.end()) {
        h++;
        modN = h % N;
      }
      A.insert(modN);
      B.push_back({modN, x[i]});
    }
    if (t[i] == 2) {
      ll modN = x[i] %N;
      if (A.find(modN) != A.end()) {
        for (ll j = 0; j < (int)B.size(); j++) {
          if (B[j].first == modN) {
            cout << B[j].second << endl;
          }
        }
      } else {
        cout << -1 << endl;
      }
    }
  }
}