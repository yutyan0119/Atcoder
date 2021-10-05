#include <bits/stdc++.h>
using namespace std;
int main(){
  int K, N;
  cin >> K >> N;
  int A[N];
  for (int i =0 ; i <N ; i++){
    cin >> A[i] ;
  }
  int maxdistance = (K-A[N-1]) + A[0];
  for (int i = 0; i < N-1; i++)
  {
    int distance = A[i+1] - A[i];
    if (distance > maxdistance) maxdistance = distance;
  }
  cout << K - maxdistance << endl;
}