#include<iostream>
#include<vector>


using namespace std;

int main(){
  int N,M,C;
  cin >> N >> M >> C;

  vector<int> B(M);
  vector<vector<int>> A(N,vector<int>(M,0));
  for(int i=0;i<M;i++){
    cin >> B[i];
  }


  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >> A[i][j];
    }
  }
  int ans = 0;
  for(int i=0;i<N;i++){
    int total = C;
    for(int j=0;j<M;j++){
      total = total + A[i][j] * B[j];
    }

    if(total > 0){
      ans++;
    }
  }


  cout << ans << endl;
  return 0;
}
