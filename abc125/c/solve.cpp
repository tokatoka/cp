#include<iostream>
#include<vector>
#include<string>
int N;
using namespace std;
vector<int> A;
vector<int> B;
vector<int> C;


int gcd(int a,int b)
{
  if (a % b == 0){
    return b;
  }
  else{
    return gcd(b , a % b);
  }
}

int main(){
  cin >> N;
  A.resize(N);
  B.resize(N);
  C.resize(N);

  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  B[0] = A[0];
  for(int i=1;i<N;i++){
    B[i] = gcd(B[i-1],A[i]);
  }
  C[N-1] = A[N-1];
  for(int i=N-2;i>=0;i--){
    C[i] = gcd(A[i],C[i+1]);
  }

  int ans = max(C[1],B[N-2]);
  for(int i=1;i<N-1;i++){
    ans = max(ans,gcd(B[i-1],C[i+1]));
  }
  cout << ans << endl;
  return 0;
}


