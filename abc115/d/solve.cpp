#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
#define ll long long
ll f(int,ll);
int N;
ll X;
vector<ll> a;
vector<ll> p;
int main(){
  cin >> N >> X;
  a.resize(N);
  p.resize(N);
  a[0] = 1;
  p[0] = 1;
  for(int i=1;i<N;i++){
    a[i] = a[i-1] * 2 + 3;
    p[i] = p[i-1] * 2 + 1;
  }

  cout << f(N,X) << endl;
  return 0;
}


ll f(int N,ll X){
  if(N==0){
    if(X<=0){
      return 0;
    }
    else{
      return 1;
    }
  }
  else if(X<=(1 + a[N-1])){
    return f(N-1,X-1);
  }
  else{
    return p[N-1] + 1 + f(N-1,X-2-a[N-1]);
  }
}
