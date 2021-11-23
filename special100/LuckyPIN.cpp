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
  string S;
  cin >> S;
  set<string> A;
  int ans = 0;
  for (int i = 0; i < 1000; i++) {
    string p = to_string(i);
    int n = (int)p.size();
    char v[3];
    for (int j = 0; j < 3 - n; j++) {
      v[j] = '0';
    }
    for (int j = 3 - n; j < 3; j++) {
      v[j] = p.at(j + n - 3);
    }
    int p1 = -1, p2 = -1, p3 = -1;

    for (int j = 0; j < N - 2; j++) {
      if (S.at(j) == v[0]) {
        p1 = j;
        break;
      }
    }
    if (p1 == -1) continue;
    for (int j = p1 + 1; j < N - 1; j++) {
      if (S.at(j) == v[1]) {
        p2 = j;
        break;
      }
    }
    if (p2 == -1) continue;
    for (int j = p2 + 1; j < N; j++) {
      if (S.at(j) == v[2]) {
        p3 = j;
        break;
      }
    }
    if (p3 == -1) continue;
    ans++;
  }
  cout << ans << endl;
}