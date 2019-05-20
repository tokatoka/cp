#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

unsigned long F(unsigned long v){
  if(v%2 == 1){
    if((v-1)%4 == 0){
      return 0;
    }
    else{
      return 1;
    }
  }
  else{
    return F(v-1) ^ v;
  }
}

int main(){
  unsigned long A,B;
  cin >> A >> B;
  cout << (F(A-1) ^ F(B)) << endl;
  return 0;
}
