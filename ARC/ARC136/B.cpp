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
  map<int,int> a;
  map<int,int> b;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    a[A[i]]++;
  }
  for (int i = 0; i < N; i++) {
    cin >> B[i];
    b[B[i]] ++;
    if (a.find(B[i]) == a.end() || a[B[i]] <= 0) {
      cout << "No"
           << "\n";
      return 0;
    } else {
      a[B[i]]--;
    }
  }
  for (int i = 0; i < N; i++) {
    if (b.find(A[i]) == b.end() || b[A[i]] <= 0) {
      cout << "No"
           << "\n";
      return 0;
    }
    else {
      b[A[i]] --;
    }
  }
  for (int i = 0; i < N - 2; i++) {
    for (int j = i; j < N - 2; j++) {
      if (A == B) {
        cout << "Yes"
             << "\n";
        return 0;
      }
      if (B[i] == A[j]) {
        rotate(A.begin() + i, A.begin() + j, A.end());
        break;
      }
      if (j == N - 3) {
        cout << "No"
             << "\n";
        return 0;
      }
    }
  }
  cout << "No"
       << "\n";
}