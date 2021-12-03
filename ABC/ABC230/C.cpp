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
  ll N, A, B, P, Q, R, S;
  cin >> N >> A >> B >> P >> Q >> R >> S;
  ll minkline = max(1 - A, 1 - B);
  ll maxkline = min(N - A, N - B);
  ll minkpair = max(1 - A, B - N);
  ll maxkpair = min(N - A, B - 1);
  for (int i = 0; i < Q-P+1; i++)
  {
    for (int j = 0; j < S-R+1; j++)
    {
      ll y = P+i;
      ll x = R+j;
      if (y-A == x -B && minkline <= y-A && y-A <= maxkline){
        cout << "#";
      }
      else if (y-A == B-x && minkpair <= y-A  && y-A <= maxkpair){
        cout << "#";
      }else {
        cout <<".";
      }
    }
    cout << endl;
  }
  return 0;
}