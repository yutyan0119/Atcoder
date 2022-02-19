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
  ll x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  ll dx[4] = {1, 2, -1, -2};
  ll dyp[4] = {2, 1, -2, -1};
  ll dym[4] = {-2, -1, 2, 1};
  bool exit = false;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (x1 + dx[i] == x2 + dx[j] && y1 + dyp[i] == y2 + dyp[j]) {
        exit = true;
        break;
      }
      if (x1 + dx[i] == x2 + dx[j] && y1 + dym[i] == y2 + dym[j]) {
        exit = true;
        break;
      }
      if (x1 + dx[i] == x2 + dx[j] && y1 + dym[i] == y2 + dyp[j]){
        exit = true;
        break;
      }
      if (x1 + dx[i] == x2 + dx[j] && y1 + dyp[i] == y2 + dym[j]){
        exit = true;
        break;
      }
    }
  }
  if (exit) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}