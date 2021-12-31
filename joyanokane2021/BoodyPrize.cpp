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
  vector<pair<int, int>> A(N);
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A[i].first = a;
    A[i].second = i + 1;
  }
  sort(A.begin(), A.end());
  cout << A[N - 2].second << endl;
}