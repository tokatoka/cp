#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int A,B;
  cin >> A >> B;
  int ret = 0;
  if(A >= B){
    ret = ret + A;
    A = A - 1;
  }
  else{
    ret = ret + B;
    B = B - 1;
  }

  if(A >= B){
    ret = ret + A;
    A = A - 1;
  }
  else{
    ret = ret + B;
    B = B - 1;
  }
  cout << ret << endl;
}
