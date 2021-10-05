#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, M, X;
  cin >> N >> M >> X;
  int A[M];
  for (int i = 0; i < M; i++)
  {
    cin >> A[i];
  }
  int cost1 = 0;
  int cost2 = 0;

  for (int i = X; i < N + 1; i++){
    for (int j = 0; j < M; j++){
      if (A[j] == i) cost1 ++;
    }
  }

  for (int i = 0; i < X+1; i++){
    for (int j = 0; j < M; j++){
      if (A[j] == i) cost2 ++;
    }
  }

  int ans;
  if (cost1 < cost2) {
    ans = cost1;
  }
  else ans = cost2;
  cout << ans << endl;
}