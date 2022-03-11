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
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }
  vector<int> ap = A;
  vector<int> bp = B;
  sort(ap.begin(), ap.end());
  sort(bp.begin(), bp.end());
  if (ap != bp) {
    cout << "No"
         << "\n";
    return 0;
  }
  for (int i = 0; i < N ; i++) {
    for (int j = i; j < N ; j++) {
      if (A == B) {
        cout << "Yes"
             << "\n";
        return 0;
      }
      if (B[i] == A[j]) {
        rotate(A.begin() + i, A.begin() + j, A.end());
        break;
      }
      if (j == N -1) {
        cout << "No"
             << "\n";
        return 0;
      }
    }
  }
  cout << "Yes"
       << "\n";
}