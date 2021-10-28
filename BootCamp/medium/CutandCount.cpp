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
  string S;
  cin >> N >> S;
  int max = 0;
  for (int i = 0; i < N; i++) {
    int count = 0;
    bool Xexist[27]={false};
    bool Yexist[27]={false};
    string X = S.substr(0, i);
    string Y = S.substr(i, N - i);
    for (int j = 0; j < 27; j++)
    {
      for (int k = 0; k < i; k++)
      {
        if(X[k]=='a'+j){
          Xexist[j] = 1;
        }
      }
      for (int k = 0; k < N-i; k++)
      {
        if(Y[k] == 'a'+j){
          Yexist[j] = 1;
        }
      }
      if (Xexist[j]&&Yexist[j]){
        ++count;
      }
    }
    chmax(max,count);
  }
  cout << max << endl;
}