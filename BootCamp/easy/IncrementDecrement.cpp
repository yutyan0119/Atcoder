#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, x = 0;
  string S;
  cin >> N >> S;
  int ans[N+1];
  ans[0] = 0;
  for (int i = 0; i < N; i++)
  {
    if(S.at(i) == 'I'){
      x++;
    }
    else x--;
    ans [i+1] = x;
  }
  cout << *max_element(ans,ans+N+1) << endl;
}
