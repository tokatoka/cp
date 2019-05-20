#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int N;
vector<int> p;
int main(){
  cin >> N;
  p.resize(N);
  for(int i=0;i<N;i++){
    cin >> p[i];
  }
  sort(p.begin(),p.end(),greater<int>());
  int ans = 0;
  for(int i = 0;i<N;i++){
    if(i==0){
      ans += p[i]/2;
    }
    else{
      ans += p[i];
    }
  }
  cout << ans << endl;
  return 0;
}
