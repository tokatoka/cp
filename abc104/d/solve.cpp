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
#include<numeric>
#define INF 1e9
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(),(a).end()
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename T1, typename T2> ostream& operator<<(ostream& s, const pair<T1, T2>& p) {return s << "(" << p.first << ", " << p.second << ")";}
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << "\t";
  }
  return s;
}

template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) {
  s << vv[i] << endl;
  }
  return s;
}
const int MOD = 1000000007;
void add(ll &a , ll b){
  a += b;
  if(a >= MOD){
    a -= MOD;
  }
}
string S;
ll dp[210000][5];
signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> S;
  dp[0][0] = 1;
  for(int i = 0 ; i < S.size(); i++){
    for(int j = 0 ; j < 5 ; j++){
      if(S[i] != '?'){
        add(dp[i+1][j] , dp[i][j]);
      }
      else{
        add(dp[i+1][j], dp[i][j] * 3 % MOD);
      }
    }
    if(S[i] == 'A' || S[i] == '?'){
      add(dp[i+1][1],dp[i][0]);
    }
    if(S[i] == 'B' || S[i] == '?'){
      add(dp[i+1][2],dp[i][1]);
    }
    if(S[i] == 'C' || S[i] == '?'){
      add(dp[i+1][3],dp[i][2]);
    }
  }

  cout << dp[S.size()][3] << endl;
  return 0;
}
