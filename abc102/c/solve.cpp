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
#define int long long
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
vector<ll> A;
signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> N;
  A.resize(N);
  rep(i,N){
    cin >> A[i];
  }
  rep(i,N){
    A[i] = A[i] - (i + 1);
  }
  sort(A.begin(),A.end());
  ll ret = 0;
  ll length = A.size();
  if(length % 2 == 0){
    rep(i,N){
      ret += abs(A[i] - A[length/2]);
    }
  }
  else{
    rep(i,N){
      ret += abs(A[i] - A[(length-1)/2]);
    }
  }

  cout << ret << endl;
  return 0;
}
