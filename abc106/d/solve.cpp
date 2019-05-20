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

int N,M,Q;
vector<int> L;
vector<int> R;
vector<vector<int>> X(510,vector<int>(510,0));
vector<vector<int>> C(510,vector<int>(510,0));
signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> N >> M >> Q;
  L.resize(M);
  R.resize(M);
  for(int i = 0 ; i < M ; i++){
    cin >> L[i] >> R[i];
    X[L[i]][R[i]]++;
  }
  for(int i = 1; i <= N ; i++){
    for(int j = 1; j <= N; j++){
      C[i][j] = C[i][j-1] + X[i][j];
    }
  }
  for(int i = 1; i <= Q; i++){
    int p,q;
    cin >> p >> q;
    int s = 0;
    for(int j = p ; j <= q; j++){
      s += C[j][q] - C[j][p-1];
    }

    cout << s << endl;
  }

  return 0;
}
