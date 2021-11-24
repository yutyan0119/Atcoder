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
  vector<pair<ll, ll>> Stars(N);
  int basex;
  cin >> basex;
  int basey;
  cin >> basey;
  Stars[0].first = Stars[0].second = 0;
  for (int i = 1; i < N; i++) {
    ll x, y;
    cin >> x >> y;
    Stars[i].first = x - basex;
    Stars[i].second = y - basey;
  }
  int M;
  cin >> M;
  vector<pair<ll, ll>> StarPics(M);
  map<pair<ll, ll>, bool> Picture;
  for (int i = 0; i < M; i++) {
    ll x, y;
    cin >> x >> y;
    StarPics[i].first = x;
    StarPics[i].second = y;
    Picture[{x, y}] = true;
  }
  bool can;
  for (int i = 0; i < M; i++) {
    ll x1 = StarPics[i].first;
    ll y1 = StarPics[i].second;
    can = true;
    for (int j = 1; j < N; j++) {
      if (Picture.find({x1 + Stars[j].first, y1 + Stars[j].second}) !=
          Picture.end()) {
        continue;
      } else {
        can = false;
        break;
      }
    }
    if (can) {
      cout << x1 - basex << " " << y1 - basey << endl;
      return 0;
    }
  }
}