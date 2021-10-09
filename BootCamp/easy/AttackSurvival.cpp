#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, K, Q;
  cin >> N >> K >> Q;
  int A[Q];
  vector <int> B(N,0);
  for(int i = 0 ; i < Q ; i ++){
    cin >> A[i];
  }
  vector <string> ans(N,"No");
  for (int i = 0; i < Q; i++)
  {
    B[A[i]-1] ++;
  }
  for (int i =0 ; i < N ; i++){
    if (Q - B[i] < K){
      ans[i] = "Yes";
    }
  }
  for (int i = 0 ; i < N ; i++){
    cout << ans[i] << endl;
  }
}
