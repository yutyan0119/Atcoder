#include <bits/stdc++.h>
using namespace std;

template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

#define rep(i, s, e) for(int i = s; i <e ; i++)

/* ---------------------------------------------------*/
int janken(char x, char y){
  if ((x == 'G' && y == 'C')||(x == 'C' && y == 'P')||(x == 'P' && y == 'G')){
    return 2;
  }
  else if(x ==y) return 1;
  else return 0;
}

int main() {
  int N, M;
  cin >> N >> M;
  char A[2*N][M];
  vector <pair<int, int>> B(2*N);
  
  rep(i,0,2*N){
    rep(j,0,M){
      cin >>A[i][j];
      B[i].first = 0;
      B[i].second = -i;
    }
  }

  for (int i = 0; i < M; i++)
  {
    for (int j = 1; j < N+1; j++)
    {
      char x = A[-B[2*j-2].second][i];
      char y = A[-B[2*j-1].second][i];
      if (janken(x,y) == 2) B[2*j-2].first ++;
      if (janken(x,y) == 0) B[2*j-1].first ++; 
    }
    sort(B.begin(),B.end());
  }
  for (int i = 2*N-1; i >= 0; i--)
  {
    cout << -B[i].second+1 << endl;
  }
}
