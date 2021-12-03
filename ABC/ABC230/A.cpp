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
    ll ac = -1;
    ll wa = N;
    while (abs(wa-ac) >1){
      ll mid = (ac+wa)/2;
      if(L.at(mid).second - baseR < D){
        ac = mid;
      }else {
        wa = mid;
      }
    }
    i = ac;
    count++;
  }
  cout << count << endl;
}