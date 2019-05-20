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
vector<int> memo(100010,0);
int get(int n){
  if(n < 0){
    return INF;
  }
  else{
    return memo[n];
  }
}

signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> N;
  memo[0] = 0;
  memo[1] = 1;
  int i = 2;
  while(true){
    memo[i] = min({get(i-1)+1,get(i-6)+1,get(i-36)+1,get(i-216)+1,get(i-1296)+1,
        get(i-7776)+1,get(i-46656)+1,get(i-9)+1,get(i-81)+1,get(i-729)+1,get(i-6561)+1,get(i-59049)+1});
    i++;
    if(i > 100000){
      break;
    }
  }
  cout << memo[N] << endl;
  return 0;
}
