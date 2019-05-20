#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int MAX_DIGIT = 50;
template<class T> inline bool chmax(T& a, T b){
  if(a < b){
    a = b;
    return 1;
  }
  return 0;
}
long long dp[100][2];
vector<long long> A;
int main(){
  int N = 0;
  long long K = 0;
  cin >> N >> K;
  A.resize(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  memset(dp,-1,sizeof(dp));
  dp[0][0] = 0;

  for(int d=0;d<MAX_DIGIT;d++){
    long long mask = 1LL << (MAX_DIGIT - d - 1);
    int num = 0;
    for(int i=0;i<N;i++){
      if(A[i] & mask) num++;
    }
    long long cost0 = mask * (num);
    long long cost1 = mask * (N - num);

    if(dp[d][1] != -1){
      chmax(dp[d+1][1],dp[d][1]+max(cost0,cost1));
    }
    if(dp[d][0] != -1){
      if(K & mask){
        chmax(dp[d+1][1],dp[d][0] + cost0);
      }
    }
    if(dp[d][0] != -1){
      if(K & mask){
        chmax(dp[d+1][0],dp[d][0] + cost1);
      }
      else{
        chmax(dp[d+1][0],dp[d][0] + cost0);
      }
    }
  }

  cout << max(dp[MAX_DIGIT][0],dp[MAX_DIGIT][1]) << endl;

}
