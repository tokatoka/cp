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

int N;
string S;
vector<int> s_to_e;
vector<int> s_to_w;
signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> N;
  cin >> S;
  s_to_e.resize(N+1);
  s_to_w.resize(N+1);
  s_to_e[0] = 0;
  s_to_w[0] = 0;
  rep(i,N){
    if(S[i] == 'E'){
      s_to_e[i+1] = s_to_e[i] + 1;
      s_to_w[i+1] = s_to_w[i];
    }
    else{
      s_to_w[i+1] = s_to_w[i] + 1;
      s_to_e[i+1] = s_to_e[i];
    }
  }
  // s0 = 0
  // s1 = a1
  // s2 = a1 + a2
  // s3 = a1 + a2 + a3
  int ret = INF;
  for(int i = 0 ; i < N ; i++){
    //traverse thru leaders
    int cand = 0;
    cand = s_to_w[i] + s_to_e[N] - s_to_e[i+1];
    ret = min(ret,cand);
  }

  cout << ret << endl;
  return 0;
}
