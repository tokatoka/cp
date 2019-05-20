#include<iostream>
#include<string>
#include<vector>

using namespace std;
int N,M;
vector<int> A;
const string MINUSINF = "-";
void chmax(string &a, string b){
  if(a == MINUSINF){
    a = b;
  }
  else if(a.size() < b.size()){
    a = b;
  }
  else if(a.size() == b.size()){
    if(a < b){
      a = b;
    }
  }
}
long long match[10] = {2,5,5,4,5,6,3,7,6};
string dp[11000];
int main(){
  cin >> N >> M;
  A.resize(M);
  for(int i=0;i<M;i++){
    cin >> A[i];
  }
  for(int i=0;i<11000;i++){
    dp[i] = MINUSINF;
  }
  dp[0] = "";

  for(int i=0;i<=N;i++){
    if(dp[i] == MINUSINF){
      continue;
    }
    for(auto itr = A.begin();itr != A.end(); itr++){
      chmax(dp[i+match[*itr-1]],dp[i]+(char)('0'+*itr));
    }
  }
  cout << dp[N] << endl;

}
