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

int N,M;
vector<ll> A;

signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> N >> M;
  A.resize(N);
  rep(i,N){
    cin >> A[i];
  }

  map<ll,ll>nums;
  ll sum = 0;
  nums[sum]++;
  rep(i,N){
    sum += A[i];
    nums[sum % M]++;
  }
  ll ret = 0;
  for(auto it : nums){
    ret += it.second * (it.second - 1 ) / 2;
  }
  cout << ret << endl;

  return 0;
}
