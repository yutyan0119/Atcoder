#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  double v[N];
  for (int i = 0; i < N ; i++){
    cin >> v[i];
  }
  sort(v, v+N);
  double value = (v[0]+v[1])/2;
  if (N>2){
    for (int i = 2; i < N; i++)
    {
      value = (v[i]+value)/2;
    }
  }
  cout << value << endl;
}