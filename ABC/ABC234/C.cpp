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

const ll mod = 998244353;

int main() {
  ll K;
  cin >> K;
  vector<char> ans;
  bool exist = false;
  for (ll i = 0; i <= 63; i++) {
    if (K & 1LL << (63 - i)) {
      ans.push_back('2');
      exist = true;
    } else if (exist) {
      ans.push_back('0');
    } else {
      continue;
    }
  }
  for (ll i = 0; i < ans.size(); i++) {
    cout << ans[i];
  }
  cout << "\n";
}
