#include <bits/stdc++.h>
using namespace std;
int main () {
  int N, count=0, check;
  bool shift=true;
  cin >> N;
  vector <int> a(N);
  
  for (int i = 0; i < N; i++)
  {
    cin >> a.at(i);
  }
  while (shift)
  { 
    check =0;
    for (int i =0 ; i < N ; i++){
    if (a.at(i) %2 == 0){
      a.at(i) = a.at(i)/2;
      check ++;
    }else{
      shift = false;
    }
    if (check == N){
      count +=1;
    }
  }
  }
  cout << count << endl;
}