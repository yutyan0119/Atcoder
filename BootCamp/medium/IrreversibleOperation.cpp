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
  string S;
  cin >> S;
  ll count = 0;
  ll wcount = 0;
  ll firstB = -1;
  for (ll i = 0; i < (ll)S.size() - 1; i++) {
    if (S.at(i) == 'B') {
      firstB = i;
      break;
    }
  }
  if (firstB == -1) {
    cout << 0 << endl;
    return 0;
  }

  for (ll i = firstB + 1; i < (ll)S.size(); i++) {
    if (S.at(i) == 'W') {
      count += i - wcount - firstB;
      wcount++;
    }
  }
  cout << count << endl;
}