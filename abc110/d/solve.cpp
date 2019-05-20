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

const int MOD = 1000000007;
const int MAX = 210000;
ll fac[MAX];
ll finv[MAX];
ll inv[MAX];
void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++){
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

long long COM(int n, int k){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

vector<pair<ll,ll>> factorize(ll n){
  vector<pair<ll,ll>> ret;
  for(ll p = 2 ; p * p <= n; p++){
    if(n % p != 0){
      continue;
    }
    int num = 0;
    while(n % p == 0){
      n = n / p;
      num++;
    }
    ret.emplace_back(make_pair(p,num));
  }
  
  if(n != 1){
    ret.emplace_back(make_pair(n,1));//if prime it self
  }  
  return ret;
}


signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  COMinit();
  int N,M;
  cin >> N >> M;
  vector<pair<ll,ll>> fac_result = factorize(M);
  ll ret = 1;
  for(auto pa : fac_result){
    int num = pa.second;
    ll tmp = COM(num + N - 1, N - 1);
    ret = (ret * tmp) % MOD;
  }
  cout << ret << endl;

  return 0;
}
