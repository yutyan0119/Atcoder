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
  ll N;
  cin >> N;
  ll D;
  cin >> D;
  vector<pair<ll, ll>> L(N);
  for (int i = 0; i < N; i++) {
    cin >> L.at(i).second >>
        L.at(i).first;  // 1個目を右端にして右端でソートすることにします。
  }
  ll count = 0;
  sort(L.begin(), L.end());
  for (int i = 0; i < N; i++) {
    ll baseR = L.at(i).first;
    ll minL;
    for (int j = i; j < N && L.at(j).second - baseR < D; j++) {
      minL = j;
    }
    i = minL;
    count++;
  }
  cout << count << endl;
}