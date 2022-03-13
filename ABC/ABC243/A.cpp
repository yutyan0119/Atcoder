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
  int V, A, B, C;
  cin >> V >> A >> B >> C;
  vector<int> use = {A, B, C};
  vector<char> name = {'F', 'M', 'T'};
  bool con = true;
  while (con) {
    for (int i = 0; i < 3; i++) {
      V -= use[i];
      if (V < 0) {
        cout << name[i] << endl;
        con = false;
        break;
      }
    }
  }
}