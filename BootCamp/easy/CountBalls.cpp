#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll N,A,B;
  cin >> N >> A >> B;
  ll x = N / (A+B) ;
  ll ans = A*x + min(A, N%(A+B));
  cout << ans << endl;
}