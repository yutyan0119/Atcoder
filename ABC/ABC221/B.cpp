#include <bits/stdc++.h>
using namespace std;
int main(){
 string S,T;
 cin >> S >> T;
 bool can = true;
 int count = 0;
 int c = (int)(S.size());
 for (int i = 0; i < c; i++){
   if (S.at(i) != T.at(i)) {
     if (i != 0){
       if (!(S.at(i) == T.at(i-1) && S.at(i-1) == T.at(i))){
        can = false;
      }
      else {
        can = true;
        count ++;
      }
     }
   }
 }
 if (can && count <=1){
   cout << "Yes" << endl;
 }
 else {
   cout << "No" << endl;
 }
}