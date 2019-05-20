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

int H,W;
signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> H >> W;
  char d[H][W];
  for(int i = 0 ; i < H ; i++){
    for(int j = 0 ; j < W ; j++){
      cin >> d[i][j];
    }
  }


  for(int i = 0 ; i < H ; i++){
    bool can_del = true;
    for(int j = 0 ; j < W ; j++){
      if(d[i][j] == '#'){
        can_del = false;
        break;
      }
    }
    if(can_del){
      for(int j = 0 ; j < W ; j++){
        d[i][j] = '*';
      }
    }
  }

  for(int j = 0; j < W ; j++){
    bool can_del = true;
    for(int i = 0 ; i < H ; i++){
      if(d[i][j] == '#'){
        can_del = false;
        break;
      }
    }
    if(can_del){
      for(int i = 0 ; i < H ; i++){
        d[i][j] = '*';
      }
    }
  }

  for(int i = 0 ; i < H ; i++){
    bool line_empty = true;
    for(int j = 0 ; j < W ; j++){
      if(d[i][j] != '*'){
        cout << d[i][j];
        line_empty = false;
      }
    }
    if(!line_empty) cout << endl;
  }

  return 0;
}
