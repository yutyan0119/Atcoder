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
  ll Q;
  cin >> Q;
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  ll addnum = 0;
  for (ll i = 0; i < Q; i++) {
    ll query;
    cin >> query;
    if (query == 1) {
      ll x;
      cin >> x;
      pq.push(x - addnum);
    }
    if (query == 2) {
      ll x;
      cin >> x;
      addnum += x;
    }
    if (query == 3) {
      cout << pq.top() + addnum << endl;
      pq.pop();
    }
  }
}