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
  int N, M;
  cin >> N >> M;
  map<ll, int> A;
  vector<ll> B(M);
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (A.find(a) != A.end()) {
      A[a]++;
    } else {
      A[a] = 1;
    }
  }
  for (int i = 0; i < M; i++) {
    cin >> B[i];
    if (A.find(B[i]) == A.end()) {
      cout << "No"
           << "\n";
      return 0;
    } else if (A[B[i]] <= 0) {
      cout << "No"
           << "\n";
      return 0;
    } else {
      A[B[i]]--;
    }
  }
  cout << "Yes"
       << "\n";
}