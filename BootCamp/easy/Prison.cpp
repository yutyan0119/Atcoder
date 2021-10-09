#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, M;
  cin >> N >> M;
  int L[M],R[M];
  for (int i = 0; i < M; i++)
  {
    cin >> L[i] >> R[i];
  }
  int maxL = *max_element(L,L+M);
  int minR = *min_element(R,R+M);
  cout << max((minR - maxL+1), 0 ) << endl;    
}
