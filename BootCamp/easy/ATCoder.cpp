#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >> S;
  int N = (int)(S.size());
  bool A[N];
  for (int i=0 ; i<N ; i++){
    if (S.at(i) == 'A' || S.at(i) == 'T' || S.at(i) == 'G' || S.at(i) == 'C'){
      A[i] = true;
    }
    else A[i] = false;
  }
  int maxcount = 0, count =0;
  for (int i = 0; i < N; i++)
  { if (A[i]==1){
      count ++;
    }
    else count =0;
    if (count > maxcount){
      maxcount = count;
    }
  }
  cout << maxcount << endl;
}