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
  int n, q, c = 0;
  cin >> n;
  vector<int> S(n);
  for (int i = 0; i < n; i++) {
    cin >> S.at(i);
  }
  cin >> q;
  vector <int> T(q);
  for (int i = 0; i < q; i++) {
    cin >> T.at(i);
  }
  for (int i = 0; i < q; i++) {
    int x = T.at(i);
    int wa = -1;
    int ac = n;
    while (abs(ac - wa) > 1) {  //ｒより大きいレンジでは常に条件を満たす
      int mid = (wa+ac) / 2;
      if (x <= S.at(mid)) {
        ac = mid;
      } else if (x > S.at(mid)) {
        wa = mid;
      }
    }
    if (ac < n && S.at(ac) == x) {
      c ++;
    }
  }
  cout << c << endl;
}