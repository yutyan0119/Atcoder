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
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll N;
  cin >> N;
  string S;
  cin >> S;
  for (ll i = 0; i + 1 < S.size(); i++) {
    if (S.at(i) == S.at(i + 1) && S.at(i) == 'B') {
      if (i + 1 < S.size()) {
        S = S.substr(0, i) + 'A' + S.substr(i + 2);
      } else {
        S = S.substr(0, i) + 'A';
      }
      i--;
    } else if (S.at(i) == 'B' && S.at(i + 1) == 'A') {
      if (i + 1 < S.size()) {
        S = S.substr(0, i) + "AB" + S.substr(i + 2);
      } else {
        S = S.substr(0, i) + "AB";
      }
      i--;
    }
  }
  cout << S << "\n";
}