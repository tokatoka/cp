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

int N,M;
signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> N >> M;
  vector<ll> a[3];
  rep(i,N){
    rep(j,3){
      ll num; cin >> num;
      a[j].push_back(num);
    }
  }
  ll ret = 0;
  for(int bit = 0 ; bit < (1 << 3) ; bit++){
    vector<ll> b;
    for(int i = 0 ; i < N ; i++){
      ll tmp = 0;
      for(int j = 0 ; j < 3 ; j++){
        if(bit & (1 << j)){
          tmp += a[j][i];
        }
        else{
          tmp -= a[j][i];
        }
      }
      
      b.push_back(tmp);
    }
    sort(b.begin(),b.end(),greater<ll>());
    ll sum = 0;
    for(int i = 0 ; i < M ; i++){
      sum += b[i];
    }
    ret = max(ret,sum);
  }
  cout << ret << endl;
  return 0;
}
