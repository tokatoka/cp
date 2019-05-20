#include<iostream>
#include<vector>
using namespace std;

int main(){
  int N,M;
  cin >> N >> M;
  vector<int> food;
  food.resize(M);
  for(int i = 0;i < N;i++){
    int K;
    cin >> K;
    for(int j = 0;j<K;j++){
      int input;
      cin >> input;
      food[input-1]++;
    }
  }
  int ret = 0;
  for(int i=0;i<M;i++){
    if(food[i] == N){
      ret++;
    }
  }
  cout << ret << endl;
}



