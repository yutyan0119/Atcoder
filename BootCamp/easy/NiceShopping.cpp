#include <bits/stdc++.h>
using namespace std;
int main(){
  int A, B, M;
  cin >> A >> B >> M;
  int a[A+1], b[B+1], x[M+1], y[M+1], c[M+1];
  for (int i = 1 ; i < A+1; i++){
    cin >> a[i];
  }
  for (int i =1; i< B+1; i++){
    cin >> b[i];
  }
  for (int i = 1; i < M+1 ; i++){
    cin >> x[i] >> y[i] >> c[i];
  }
  int mina = *min_element(a+1,a+A+1);
  int minb = *min_element(b+1,b+B+1);
  int ans = mina+minb;
  for (int i = 1; i < M+1; i++)
  {
    int tmp = a[x[i]]+b[y[i]] -c[i];
    if (ans > tmp){
      ans = tmp;
    }
  }
  cout << ans << endl;
}