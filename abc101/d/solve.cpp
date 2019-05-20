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

ll S(ll n){
  ll ret = 0;
  while(n > 0){
    ret += n%10;
    n /= 10;
  }
  return ret;
}
double f(ll n){
  return ((double)(n)/(double)S(n));
}
ll K;
vector<ll> res;
signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> K;
  ll base = 1;
  for(int i = 0 ; i < 15 ; i++){
    for(int j = 1 ; j < 150 ; j++){
      res.push_back(base * (j+1) - 1);
    }
    base *= 10;
  }
  sort(res.begin(),res.end());
  res.erase(unique(res.begin(),res.end()),res.end());

  for(ll i = 0 ; i < res.size(); i++){
    for(ll j = i+1 ; j < res.size(); j++){
      if(f(res[i]) > f(res[j])){
        res.erase(res.begin() + i--);
        break;
      }
    }
  }

  for(ll i = 0 ; i < K ; i++){
    cout << res[i] << endl;
  }
  return 0;
}
