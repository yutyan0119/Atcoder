#include <bits/stdc++.h>
using namespace std;
int main(){
  long H,W;
  cin >> H >> W;
  long count =0;

  if (H ==1 || W ==1){
    count =1;
  }
  else {
    count = (H*W+1)/2;
  }
  cout << count << endl;
}