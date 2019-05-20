#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
using namespace std;


int main(){
  string S;
  cin >> S;
  string m;
  m = S.substr(5,2);
  int m_int = stoi(m);
  if(m_int<=4){
    cout << "Heisei";
  }
  else{
    cout << "TBD";
  }
  cout << endl;
}
