#include<iostream>
#include<numeric>
#include<vector>
using namespace std;

long long gcd(long long a,long long b){
  if(a == 0){
    return b;
  }
  return gcd(b % a,a);
}

long long findGCD(vector<long long> &arr, int n){ 
  long long result = arr[0]; 
  for (int i = 1; i < n; i++) 
    result = gcd(arr[i], result);
  return result; 
}

vector<long long> A;
int N;
int main(){
  cin >> N;
  A.resize(N);

  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  cout << findGCD(A,N) << endl;
}
