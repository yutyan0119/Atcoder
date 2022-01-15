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
  ll N, Q;
  cin >> N >> Q;
  vector<ll> A(N);
  map<ll,vector<ll>> array;
  for (ll i = 0; i < N; i++) {
    cin >> A[i];
    A[i];
    array[A[i]].push_back(i);
  }
  vector<ll> ans(Q);
  for (ll i = 0; i < Q; i++) {
    ll x;
    cin >> x;
    ll k;
    cin >> k;
    if (array[x].size() >= k) {
      ans[i] = array[x][k - 1]+1;
    } else {
      ans[i] = -1;
    }
  }
  for (ll i = 0; i < Q; i++) {
    cout << ans[i] << endl;
  }
}