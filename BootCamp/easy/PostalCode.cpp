#include <bits/stdc++.h>
using namespace std;
int main(){
  int A, B;
  string S;
  cin >> A >> B >> S;
  string ans = "Yes";
  string a = S.substr(0,A);
  char hai = S.at(A);
  string b = S.substr(A+1,B);
  if (hai != '-') ans = "No";
  for (int i = 0; i < (int)a.size(); i++){
    if (! (0<=a.at(i)-'0' && a.at(i)-'0'<=9) ){
      ans = "No";
    }
  }
  for (int i = 0; i < (int)b.size(); i++){
    if (! (0<=b.at(i)-'0' && b.at(i)-'0'<=9) ){
      ans = "No";
    }
  }
  cout << ans << endl;
}
