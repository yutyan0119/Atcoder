#include <bits/stdc++.h>

#include <iostream>
using namespace std;

template <typename T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

template <typename T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

#define rep(i, s, e) for (int i = s; i < e; i++)
typedef long long ll;

/* ---------------------------------------------------*/


long long  a[10010];
long long  b[10010];
long long  c[10010];
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	} 
	for(int i=1;i<=n;i++){
		cin >> b[i];
	}
	c[0]=1;
	for(int i=0;i<=b[n]+1;i++){
		for(int j=1;j<=n;j++){
			if(i >= a[j] && i <=b[j]) c[j] = (c[j] + c[j-1])%998244353;
		}
	}
	cout << c[n] << endl; 
}