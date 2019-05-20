#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,M;
vector<int> X;
vector<int> Y;

int main(){
  cin >> N >> M;
  X.resize(M);
  for(int i=0;i<M;i++){
    cin >> X[i];
  }
  sort(X.begin(),X.end());
  for(int i=M-1;i>0;i--){
    Y.push_back(X[i]-X[i-1]);
  }
  sort(Y.begin(),Y.end());
  if(N >= M){
    cout << "0" << endl;
  }
  else{
    long long sum = 0;
    for(int i = 0; i < (M-N) ; i++){
      sum += Y[i];
    }
    cout << sum << endl;
  }
}
