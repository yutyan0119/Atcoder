#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector <int> P(N);
  vector <int> Q(N);
  vector <int> R(N);
  for (int i = 0 ; i<N; i++){
    cin >> P[i] ;
    R[i] = i+1;
  }
  for (int i = 0 ; i<N; i++){
    cin >> Q[i] ;
    R[i] = i+1;
  }
  int a = 0;
  int b = 0;

  do {
    if (equal( P.begin(), P.end(), R.begin() )){
      a++;
      break;
    }
    for (int i = 0 ; i<N; i ++){
    }
    a++;
  } while (next_permutation(R.begin(),R.end()));
  
  for (int i=0; i<N;i++){
    R[i] = i+1;
  }
  do {
    if (equal(Q.begin(), Q.end(), R.begin())){
      b++;
      break;
    }
    b++;
  } while (next_permutation(R.begin(),R.end()));
  std::cout << abs(a-b) << endl;
}