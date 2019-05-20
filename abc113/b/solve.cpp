#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int N;
int T,A;
vector<int> H;
int main(){
  cin >> N;
  cin >> T >> A;
  H.resize(N);
  for(int i = 0;i<N;i++){
    cin >> H[i];
  }
  double mindiff = 100000000.0;
  double diff = 0.0;
  int idx = 0;

  for(int n=0;n<N;n++){
    diff = abs((double)T - (double)H[n] * 0.006 - (double)A);
    if(diff < mindiff){
      mindiff = diff;
      idx = n;
    }
  }


  cout << (idx+1) << endl;

  return 0;
}


