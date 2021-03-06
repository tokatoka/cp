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

string S,T;
signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> S >> T;
  bool ok = true;
  map<char,char> ma, ima;
  for(int i = 0 ; i < S.size() ; i++){
    char s = S[i];
    char t = T[i];
    if(ma.count(s)){
      if(ma[s] != t){
        ok = false;
      }
    }
    if(ima.count(t)){
      if(ima[t] != s){
        ok = false;
      }
    }
    ma[s] = t;
    ima[t] = s;
  }
  if(ok){
    puts("Yes");
  }
  else{
    puts("No");
  }
  return 0;
}
