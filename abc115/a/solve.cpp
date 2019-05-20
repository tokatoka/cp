#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int D;
int main(){
  cin >> D;
  if(D==25){
    cout << "Christmas" << endl;
  }
  else if(D == 24){
    cout << "Christmas Eve" << endl;
  }
  else if(D == 23){
    cout << "Christmas Eve Eve" << endl;
  }
  else{
    cout << "Christmas Eve Eve Eve" << endl;
  }
  return 0;
}
