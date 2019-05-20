#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#define int long long
using namespace std;
int N;
vector<int> A;
vector<int> B;
signed main(){
  cin >> N;
  A.resize(N);
  B.resize(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
    if(A[i] < 0){
      B[i] = -A[i];
    }
    else{
      B[i] = A[i];
    }
  }
  int check = 0;
  for(int i=0;i<N;i++){
    if(A[i] < 0){
      check++;
    }
  }
  if(check % 2 == 0){
    cout << accumulate(B.begin(),B.end(),0LL);
  }
  else{
    int minElement = 10000000000LL;
    for(int i = 0;i < N;i++){
      minElement = min(B[i],minElement);
    }
    cout << accumulate(B.begin(),B.end(),0LL) - 2 * minElement << endl;
  }

}
