#include <bits/stdc++.h>
using namespace std;
int main(){
  long long H;
  cin >> H;
  long long ans = 0;
  long long i = 1;
  while (true)
  {
    if (H>1){
      H /= 2;
      ans += i;
      i *= 2;
    }else {
      ans += i;
      break;
    }
  }
  cout << ans << endl;
}