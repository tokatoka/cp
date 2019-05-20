#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main(){
  string S;
  cin >> S;
  int c1 = 0, c2 = 0;
  for(int i=0;i<S.size();i++){
    if(S[i] == '0'){
      c1++;
    }
    else{
      c2++;
    }
  }
  int maxv,minv;
  minv = min(c1,c2);
  cout << 2 * minv << endl;
}
