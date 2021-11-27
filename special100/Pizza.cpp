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
  ll d;
  cin >> d;  // 1周の距離
  int n;
  cin >> n;  //店舗数
  int m;
  cin >> m;  //注文数
  ll Distance[n];
  Distance[0] = 0;
  ll ans = 0;
  for (int i = 1; i < n; i++) {
    cin >> Distance[i];
  }
  sort(Distance, Distance + n);
  ll address[m];
  for (int i = 0; i < m; i++) {
    cin >> address[i];
    ll x = address[i];
    int wa = -1;
    int ac = n;
    while (ac - wa > 1) {
      int mid = (ac + wa) / 2;
      if (Distance[mid] >= x) {
        ac = mid;
      } else if (Distance[mid] < x) {
        wa = mid;
      }
    }  // ac, addresより上のdistance, wa addressより下のdistance
    ll kyori;
    if (ac == n) {
      kyori = min(abs(d - x), abs(x - Distance[ac - 1]));
    } else if (ac == 0) {
      kyori = 0;
    } else {
      kyori = min(abs(x - Distance[ac]), abs(x - Distance[ac - 1]));
    }
    ans += kyori;
  }
  cout << ans << endl;
}