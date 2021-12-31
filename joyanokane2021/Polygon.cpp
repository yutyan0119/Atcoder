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
  vector<int> L(N);
  for (int i = 0; i < N; i++) {
    cin >> L[i];
  }
  int maxL = *max_element(L.begin(), L.end());
  int sum = 0;
  bool exist = false;
  for (int i = 0; i < N; i++) {
    if (L[i] == maxL&& exist == false) {
      exist = true;
      continue;
    }
    sum += L[i];
  }
  if (maxL < sum) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}