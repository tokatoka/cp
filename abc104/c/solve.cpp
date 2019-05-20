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

int D;
ll G;
vector<ll> p,c;
signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> D >> G;
  p.resize(D);
  c.resize(D);
  rep(i,D){
    cin >> p[i] >> c[i];
  }

  ll ret = 1 << 29;
  for(int bit = 0 ; bit < (1 << D) ; bit++){
    ll sum = 0;
    ll num = 0;
    rep(i,D){
      if(bit & (1 << i)){
        sum += c[i] + p[i] * 100 * (i+1);
        num += p[i];
      }
    }
    if(sum >= G){
      ret = min(ret,num);
    }
    else{
      for(int i = D-1; i>= 0; i--){
        if(bit & (1 << i)){
          continue;
        }
        for(int j = 0 ; j < p[i]; j++){
          if(sum >= G){
            break;
          }
          sum += 100 * (i+1);
          num++;
        }
      }
      ret = min(ret,num);
    }
  }
  cout << ret << endl;
  return 0;
}
