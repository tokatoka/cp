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

int N;
vector<pair<ll,ll>> pos;
signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> N;
  pos.resize(N);
  for(int n = 0 ; n < N ; n++){
    cin >> pos[n].first >> pos[n].second;
  }

  int parity1 = (abs(pos[0].first) + abs(pos[0].second)) % 2; 
  for(int i = 0 ; i < N ; i++){
    int parity2 = (abs(pos[i].first) + abs(pos[i].second)) % 2;
    pos[i] = make_pair(pos[i].first + pos[i].second,pos[i].first - pos[i].second);
    if(parity2 != parity1){
      cout << "-1" << endl;
      return 0;
    }
  }

  vector<ll> d;
  for(int i = 30; i >= 0 ; i--){
    d.push_back(1LL << i);
  }
  if(parity1 % 2 == 0){
    d.push_back(1);
  }
  cout << d.size() << endl;
  for(int j = 0 ; j < d.size() ; j++){
    cout << d[j] << " ";
  }
  cout << endl;

  for(int i = 0; i < N ; i++){
    int xdir,ydir;
    long long xsum = 0;
    long long ysum = 0;
    for(int j = 0 ; j < (int)d.size() ; j++){
      if (xsum <= pos[i].first) xdir = 1, xsum += d[j];
      else xdir = -1, xsum -= d[j];
      if (ysum <= pos[i].second) ydir = 1, ysum += d[j];
      else ydir = -1, ysum -= d[j];
      
      if (xdir == 1 && ydir == 1) cout << "R";
      else if (xdir == 1 && ydir == -1) cout << "U";
      else if (xdir == -1 && ydir == -1) cout << "L";
      else cout << "D";
    }
    cout << endl;
  }

  return 0;
}
#
