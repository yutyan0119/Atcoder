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

/* ---------------------------------------------------*/

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  long long price = a * x + b * y;
  int slicea = x;
  int sliceb = y;
  int slicec = 0;
  for (int i = 0; slicec <= max(x, y) * 2; i++) {
    slicea--;
    sliceb--;
    slicec += 2;
    long long tmprice = a * ((slicea>0)?slicea : 0) + b * ((sliceb>0)?sliceb : 0) + c * slicec;
    chmin(price, tmprice);
  }
  cout << price << endl;
}