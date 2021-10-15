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
  string A;
  string B;
  cin >> A >> B;
  if (A.size() > B.size()) {
    cout << "GREATER" << endl;
  } else if (A.size() < B.size()) {
    cout << "LESS" << endl;
  } else {
    for (int i = 0; i < (int)A.size(); i++) {
      if (A == B) {
        cout << "EQUAL" << endl;
        return 0;
      } else if (A.at(i) > B.at(i)) {
        cout << "GREATER" << endl;
        return 0;
      } else if (A.at(i) < B.at(i)) {
        cout << "LESS" << endl;
        return 0;
      } else
        continue;
    }
  }
}