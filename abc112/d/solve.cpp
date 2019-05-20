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
vector<long long> calc_divisor(long long n){
  vector<long long> res;
  for(long long i = 1LL;i * i <= n; i++){
    if(n % i == 0){
      res.push_back(i);
      long long j = n / i;
      if(j != i){
        res.push_back(j);
      }
    }
  }
  sort(res.begin(),res.end());
  return res;
}


int N,M;
signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> N >> M;
  vector<ll> divisor = calc_divisor(M);
  long long res = 1;
  for(auto d : divisor){
    if( d * N <= M ){
      res = max(res,d);
    }
  }
  cout << res << endl;
  return 0;
}
