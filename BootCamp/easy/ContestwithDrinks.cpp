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
  int N;
  cin >> N;
  int T[N];
  for (int i = 0; i < N; i++) {
    cin >> T[i];
  }
  int M;
  cin >> M;
  vector<pair<int, int>> D(M);
  for (int i = 0; i < M; i++) {
    cin >> D[i].first >> D[i].second;
  }
  for (int i = 0; i < M; i++)
  { int time = 0;
    for (int j = 0; j < N; j++)
    {
      if (j == D[i].first-1){
        time += D[i].second;
      }
      else{
        time += T[j];
      }
    }
    cout << time << endl;
  }
  
}