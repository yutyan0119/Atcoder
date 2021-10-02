#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, sum =0, avg;
  cin >> N;
  vector <int> scores(N);
  for (int i = 0; i < N; i++)
  {
    cin >> scores.at(i) ;
    sum += scores.at(i) ;
  }
  avg = sum/N;
  for (int i = 0; i < N; i++)
  {
    cout << abs(avg - scores.at(i)) << endl;
  }
  
}