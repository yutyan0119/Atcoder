#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, A, B;
  int aw=0, bw=0;
  string S;
  cin >> N >> A >> B >> S;
  for (int i = 0; i < N; i++)
  {
    if (S.at(i) == 'c'){
      cout << "No" << endl;
    }
    else {
      if (S.at(i) == 'a'){
        if (aw + bw < A+B){
          cout << "Yes" << endl;
          aw ++;
        }
        else cout << "No" << endl;
      }
      if (S.at(i) == 'b'){
        if (aw + bw < A+B && bw < B){
          cout << "Yes" << endl;
          bw ++;
        }
        else cout << "No" << endl;
      }
    }
  }
  
}