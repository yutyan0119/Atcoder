#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >> S;
  int ans = 1000;
  for(int i=0; i < (int)(S.size())-2 ; i++){
    int X = (S[i] - '0')*100 + (S[i+1] - '0')*10 + (S[i+2] - '0');
    int tmp = abs(753 - X);
    ans = min (ans, tmp);
  }
  cout << ans << endl;
}
