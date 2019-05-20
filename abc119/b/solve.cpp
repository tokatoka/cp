#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
  int N;
  cin >> N;
  double ret = 0;
  for(int i=0;i<N;i++){
    string x,u;
    cin >> x >> u;
    double v = 0;
    if(u == "JPY"){
      v = stod(x);
    }
    else{
      v = stod(x) * 380000;
    }
    ret += v;
  }
  cout << setprecision(10) << ret << endl;
}
