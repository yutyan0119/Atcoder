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
  string A;
  string B;
  cin >> A >> B;
  ll Bnum = stoll(B);
  string x;
  if (Bnum%2 == 0) {
    string B2 = to_string(Bnum/2);
    x += B2 + '0' + A;
    cout << x << endl;
    return 0;
  }
  else {
    string B2 = to_string(Bnum*10/2);
    x += B2 + '0' + A;
    cout << x << endl;
    return 0;
  }
}