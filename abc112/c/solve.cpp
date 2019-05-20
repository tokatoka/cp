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
vector<vector<int>> d;
signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> N;
  for(int n = 0; n < N ; n++ ){
    int x,y,h;
    cin >> x >> y >> h;
    d.push_back({x,y,h});
  }
  for(int cx = 0 ; cx <= 100 ; cx++ ){
    for(int cy = 0 ; cy <= 100 ; cy++ ){
      for(int i = 0 ; i < N ; i++){
        if(d[i][2] <= 0){
          continue;
        }
        int h = d[i][2] + abs(cx - d[i][0]) + abs(cy - d[i][1]);
        //check validity
        bool is_valid = true;
        for(int n = 0 ; n < N ; n++){
          if(max(h - abs(cx - d[n][0]) - abs(cy - d[n][1]),0) != d[n][2]){
            is_valid = false;
            break;
          }
        }
        if(is_valid == true){
          cout << cx << " " << cy << " " << h << endl;
          return 0;
        }
      }
    }
  }

  return 0;
}
