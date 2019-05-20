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

//shorter types
using namespace std;
using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<long long>;
using vs = std::vector<string>;
using Pi = pair<int,int>;
using Pll = pair<ll,ll>;
using vPi = vector<Pi>;
using vPll = vector<Pll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvs = vector<vector<string>>;
template<class T>
using vec = vector<T>;

//frequent functions
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
struct UnionFind{
  vector<int> par;
  UnionFind(int n) : par(n,-1) {}
  void init(int n) {par.assign(n,-1);}
  int root(int x){
    if(par[x] < 0) return x;
    else return par[x] = root(par[x]);
  }
  bool issame(int x,int y){
    return root(x) == root(y);
  }
  bool merge(int x,int y){
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (par[x] > par[y]){
      swap(x,y);
    }
    par[x] += par[y];
    par[y] = x;
    return true;
  }
  int size(int x){
    return -par[root(x)];
  }
};


int N,M;
signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> N >> M;
  vi P(N);
  rep(i,N){
    cin >> P[i];
  }
  UnionFind tree(N);
  rep(i,M){
    int x,y;
    cin >> x >> y;
    tree.merge(x-1,y-1);
  }
  int cnt = 0;
  rep(i,N){
    if(tree.issame(i,P[i]-1)){
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
