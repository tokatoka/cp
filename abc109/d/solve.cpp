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
#define szt size_t
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
  vector<vector<int>> d(H,vector<int>(W,0));
  for(int i = 0 ; i < H ; i++){
    for(int j = 0 ; j < W ; j++){
      cin >> d[i][j];
    }
  }
  vector<tuple<szt,szt,szt,szt>> ret;
  for(szt i = 0 ; i < H; i++){
    for(szt j= 0 ; j < W; j++){
      if(d[i][j] % 2 == 0){
        continue;
      }
      if(i == H-1 && j == W-1){
        continue;
      }
      szt ni = i;
      szt nj = j;
      if(j+1 == W){
        ni++;
      }
      else{
        nj++;
      }
      ret.emplace_back(i+1,j+1,ni+1,nj+1);
      d[i][j]--;
      d[ni][nj]++;
    }
  }

  cout << ret.size() << endl;
  for(auto i : ret){
    szt A,B,C,D;
    tie(A,B,C,D) = i;
    cout << A << " " << B << " " << C << " "<< D << endl;
  }

  return 0;
}
