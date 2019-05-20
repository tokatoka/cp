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


signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  ll l;
  cin >> l;
  long r;
  for(r = 1; r <= 19; r++){
    if(l < pow(2,r)){
      break;
    }
  }
  r--;
  vector<vector<ll>> ans;
  for(ll i = 1 ; i <= r ; i++){
    ans.push_back({i,i+1,0});
    ans.push_back({i,i+1,static_cast<ll>(pow(2,i-1))});
  }


  for(ll i = r ; i >= 1; i--){
    if(l - pow(2,i-1) >= pow(2,r) ){
      ans.push_back({i,r+1,l-static_cast<ll>(pow(2,i-1))});
      l -= pow(2,i-1);
    }
  }
  cout << r+1 << ' ' << ans.size() << "\n";
  for(auto each_ans : ans){
    cout << each_ans[0] << " " << each_ans[1] << " " << each_ans[2] << "\n";
  }

  return 0;
}
