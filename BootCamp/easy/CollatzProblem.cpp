#include <bits/stdc++.h>
using namespace std;
int collatz(int n){
  return (n%2 ==0) ? n/2 : 3*n+1;
}

int main(){
  int s;
  cin >> s;
  int maxm = 1000000;
  int a[maxm];
  int ans=maxm;
  int tmpans ;
  a[0] = s;
  for (int i = 1 ; i<maxm;i++){
    a[i] = collatz(a[i-1]);
    for (int j = 0; j < i; j++)
    {
      if (a[i] == a[j]){
        ans = i;
        break;
      }
    }
  }
  cout << ans+1 << endl;
}
