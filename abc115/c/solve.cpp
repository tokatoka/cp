#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define ll long long
using namespace std;
int N,K;
vector<ll> h;
int main(){
  cin >> N >> K;
  h.resize(N);
  for(int i = 0;i<N;i++){
    cin >> h[i];
  }

  sort(h.begin(),h.end());
  ll ans = 1000000000;
  for(int i = 0;i<N;i++){
    int l = i;
    int r = i + (K-1);
    if(r >= N){
      break;
    }
    ans = min(ans,h[r] - h[l]);
  }
  cout << ans << endl;
}
