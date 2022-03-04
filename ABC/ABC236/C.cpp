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
  vector<string> S(N);
  vector<vector<int>> map(N, vector<int>(N));
  vector<vector<int>> yoko(N, vector<int>(N - 5));
  vector<vector<int>> tate(N - 5, vector<int>(N));
  vector<vector<int>> lnaname(N, vector<int>(N));
  vector<vector<int>> rnaname(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    cin >> S[i];
    for (int j = 0; j < N; j++) {
      if (S[i].at(j) == '#') {
        map[i][j] = 1;
      } else {
        map[i][j] = 0;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= N - 6; j++) {
      yoko[i][j] = 0;
      for (int h = 0; h < 6; h++) {
        yoko[i][j] += map[i][j + h];
      }
      if (yoko.at(i).at(j) >= 4) {
        cout << "Yes"
             << "\n";
        return 0;
      }
    }
  }
  for (int i = 0; i <= N - 6; i++) {
    for (int j = 0; j < N; j++) {
      tate[i][j] = 0;
      for (int h = 0; h < 6; h++) {
        tate[i][j] += map[i + h][j];
      }
      if (tate[i][j] >= 4) {
        cout << "Yes"
             << "\n";
        return 0;
      }
    }
  }
  for (int i = 0; i <= N - 6; i++) {
    for (int j = 0; j <= N - 6; j++) {
      lnaname[i][j] = 0;
      for (int h = 0; h < 6; h++) {
        lnaname[i][j] += map[i + h][j + h];
      }
      if (lnaname[i][j] >= 4) {
        cout << "Yes"
             << "\n";
        return 0;
      }
    }
  }
  for (int i = 0; i <= N - 6; i++) {
    for (int j = 5; j < N; j++) {
      rnaname[i][j] = 0;
      for (int h = 0; h < 6; h++) {
        rnaname[i][j] += map[i + h][j - h];
      }
      if (rnaname[i][j] >= 4) {
        cout << "Yes"
             << "\n";
        return 0;
      }
    }
  }
  cout << "No"
       << "\n";
}
