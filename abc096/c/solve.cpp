//includes
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

//macros
#define INF 1e9
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(),(a).end()
#define vecuni(a) (a).erase(unique((a).begin(),(a).end()),(a).end())
#define pb push_back
#define mp make_pair
#define eb emplace_back

//shorter types
using namespace std;
using ll = long long;
using vi = std::vector<int>;
using vc = std::vector<char>;
using vll = std::vector<long long>;
using vs = std::vector<string>;
using Pi = pair<int,int>;
using Pll = pair<ll,ll>;
using vPi = vector<Pi>;
using vPll = vector<Pll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvc = vector<vector<char>>;
using vvs = vector<vector<string>>;
using pqgi = priority_queue<int,vector<int>,greater<int>>;
using pqsi = priority_queue<int,vector<int>,less<int>>;
using pqgll = priority_queue<int,vector<int>,greater<int>>;
using pssll = priority_queue<int,vector<int>,less<int>>;
template<class T>
using vec = vector<T>;

//frequent functions and datas
int gcd(int a, int b){
  if (a == 0) 
    return b; 
  return gcd(b % a, a); 
}
int findGCD(vector<int> &arr, int n){
  int result = arr[0]; 
  for (int i = 1; i < n; i++) 
    result = gcd(arr[i], result); 
  return result; 
}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
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
//end

int H,W;
signed main(){
  cin >> H;
  cin >> W;
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  vvc s(H,vc(W,'0'));
  rep(i,H){
    rep(j,W){
      char in;
      cin >> in;
      s[i][j] = in;
    }
  }
  bool possible = true;
  rep(i,H){
    rep(j,W){
      if(s[i][j] == '#'){
        bool ok = false;
        rep(d,4){
          if(i + dy[d] < 0 || i + dy[d] >= H){
            continue;
          }
          if(j + dx[d] < 0 || j + dx[d] >= W){
            continue;
          }
          if(s[i + dy[d]][j + dx[d]] == '#'){
            ok = true;
            break;
          }
        }
        if(!ok){
          possible = false;
          break;
        }
      }
    }
  }

  cout << ((possible)?"Yes":"No") << endl;
  return 0;
}
