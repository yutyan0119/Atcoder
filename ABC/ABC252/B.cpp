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

typedef long long ll;

/* ---------------------------------------------------*/

int main() {
  int N, K;
  cin >> N >> K;
  int A[N];
  vector<int> B(K);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  int maxA = *max_element(A, A + N);
  cout << *max_element(A, A + N);
  for (int i = 0; i < K; i++) {
    cin >> B[i];
    A[B[i] - 1] = -1;
  }
  cout << *max_element(A, A + N);
  if (*max_element(A, A + N) != maxA) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}