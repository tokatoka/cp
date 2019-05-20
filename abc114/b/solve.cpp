#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
string S;
int main(){
  cin >> S;
  int ret = 1000;
  
  int l = S.length();
  for(int i=0;i<l-2;i++){
    int cand = (S[i] - '0') * 100 + (S[i+1] - '0') * 10 + (S[i+2] - '0');
    ret = min(ret,abs(cand - 753));
  }
  cout << ret << endl;

  return 0;
}
