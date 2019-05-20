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

int N,C;
signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> N >> C;
  vector<vector<int>> D(C,vector<int>(C,0));
  for(int i = 0 ; i < C ; i++){
    for(int j = 0 ; j < C ; j++){
      int d;
      cin >> d;
      D[i][j] = d;
    }
  }
  vector<vector<int>> fi(N,vector<int>(N,0));
  for(int i = 0 ; i < N ; i++){
    for(int j = 0 ; j < N ; j++){
      cin >> fi[i][j];
      fi[i][j]--;
    }
  }
  vector<vector<int>> cost(3,vector<int>(C,0));
  for(int c = 0 ; c < C; c++){
    for(int i = 0 ; i < N; i++){
      for(int j = 0 ; j < N ; j++){
        cost[(i+j) % 3][c] += D[fi[i][j]][c];
      }
    }
  }

  int res = 1<<30;
  int c[3];
  for (c[0] = 0; c[0] < C; ++c[0]) {
    for (c[1] = 0; c[1] < C; ++c[1]) {
      if (c[1] == c[0]) continue;
      for (c[2] = 0; c[2] < C; ++c[2]) {
        if (c[2] == c[0] || c[2] == c[1]) continue;
        int tmp = 0;
        for (int it = 0; it < 3; ++it) tmp += cost[it][c[it]];
        res = min(res, tmp);
      }
    }
  }
  cout << res << endl;
  return 0;
}
