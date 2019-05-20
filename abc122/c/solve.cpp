#include<iostream>
#include<vector>
#include<set>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<map>
#include<queue>
#include<iomanip>
#define INF 1e9
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;

int N,Q;
string S;
vector<int> accum;
signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> N >> Q;
  cin >> S;
  accum.resize(N);
  fill(accum.begin(),accum.end(),0);
  for(int i = 0; i < N-1; i++){
    if(S[i] == 'A' && S[i+1] == 'C'){
      accum[i + 1] = accum[i] + 1;
    }
    else{
      accum[i + 1] = accum[i];
    }
  }
  for(int i = 0; i < Q; i++){
    int l,r;
    cin >> l >> r;
    l--;r--;
    cout << accum[r] - accum[l] << endl;
  }

  return 0;
}
