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

#define rep(i1, s, e) for (int i1 = s; i1 < e; i1++)

/* ---------------------------------------------------*/

int main() {
  int N;
  cin >> N;
  set<vector<int>> S;
  for (int i = 0; i < N; i++) {
    int L;
    cin >> L;
    vector<int> a(L);
    for (int j = 0; j < L; j++) {
      cin >> a[j];
    }
    S.insert(a);
  }
  cout << S.size() << endl;
}