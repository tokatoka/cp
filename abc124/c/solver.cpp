#include<iostream>
#include<string>
using namespace std;
int main(){
  string s;

  cin >> s;
  int cand1 = 0;
  int cand2 = 0;
  int len = s.length();
  // cand1 for 1.....
  // cand2 for 0.....
  // now for cand1
  for(int i=0;i<len;i++){
    if(i%2 == 0){
      if(s[i] != '1'){
        cand1++;
      }
    }
    else{
      if(s[i] != '0'){
        cand1++;
      }
    }
  }
  for(int i=0;i<len;i++){
    if(i%2 == 0){
      if(s[i] != '0'){
        cand2++;
      }
    }
    else{
      if(s[i] != '1'){
        cand2++;
      }
    }
  }

  if(cand1 <= cand2){
    cout << cand1 << endl;
  }
  else{
    cout << cand2 << endl;
  }
  return 0;
}
