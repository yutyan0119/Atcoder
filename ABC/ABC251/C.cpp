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
  ll N;
  cin >> N;
  set<string> S;
  vector<pair<ll, ll>> T;
  for (ll i = 0; i < N; i++) {
    string s;
    ll t;
    cin >> s >> t;
    if (S.find(s) == S.end()) {
      S.insert(s);
      T.push_back(make_pair(t, i));
    }
  }
  sort(T.begin(), T.end(), [](auto const& l, auto const& r) {
    if (l.first != r.first) {
      return l.first > r.first;
    } else {
      return l.second < r.second;
    }
  });
  cout << T[0].second + 1 << endl;
}
