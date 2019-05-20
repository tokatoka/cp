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
string s;
vector<ll> typ(3,0);
signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> N;
  ll ret = 0;
  for(int i = 0 ; i < N ; i++){
    cin >> s;
    if(s[0] == 'B' && s[s.size() - 1] == 'A'){
      typ[0]++; //typ[0] B???A
    }
    else if(s[s.size() - 1] == 'A'){
      typ[1]++; //typ[1] ????A
    }
    else if(s[0] == 'B'){
      typ[2]++; //typ[2] B????
    }
    for(int j = 0 ; j < s.size() - 1 ; j++){
      if(s[j] == 'A' && s[j+1] == 'B'){
        ret++;
      }
    }
  }
  
  ll add = min(typ[0]+typ[1],typ[0]+typ[2]);
  if(typ[2] == typ[1]){
    if(typ[1] == 0){
      ret = ret + add - 1;
    }
    else{
      ret = ret + add;
    }
  }
  else{
    ret = ret + add;
  }


  cout << ret << endl;

  return 0;
}
