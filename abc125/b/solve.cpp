#include<iostream>
#include<vector>
#include<string>

using namespace std;
int N;
vector<int> V;
vector<int> C;
vector<int> D;
int main(){
  cin >> N;
  V.resize(N);
  C.resize(N);
  D.resize(N);
  for(int i = 0;i<N;i++){
    cin >> V[i];
  }
  for(int i = 0;i<N;i++){
    cin >> C[i];
  }
  
  for(int i = 0;i<N;i++){
    D[i] = V[i] - C[i];
  }

  int ret = 0;
  for(int i = 0; i < N; i++){
    if(D[i] > 0){
      ret = ret+D[i];
    }
  }

  cout << ret << endl;
  return 0;
}


