#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
  int A,B,C;
  cin >> A >> B >> C;

  int v1 = B / A;
  if(v1 >= C){
    cout << C << endl;
  }
  else{
    cout << v1;
  }
}
