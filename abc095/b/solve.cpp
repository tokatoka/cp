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

//macros and consts
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(),(a).end()
#define vecuni(a) (a).erase(unique((a).begin(),(a).end()),(a).end())
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define accm accumulate
#define F first
#define S second
#define INF 1e9
#define mINF -1e9

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
bool is_prime(int n){
  if(n == 1){
    return false;
  }
  for(int i = 2 ; i <= pow(n,0.5) ; i++){
    if(n % i == 0){
      return false;
    }
  }
  return true;
}
struct SegmentTree{
  private:
    int n;
    vector<int> node;
  public:
    SegmentTree(vector<int> v){
      int sz = v.size();
      n = 1;
      while(n < sz) n *= 2;
      node.resize(2 * n - 1 , INF);
      for(int i = 0 ; i < sz ; i++){
        node[i + n - 1] = v[i];
      }
      for(int i = n - 2 ; i >= 0 ; i--){
        node[i] = min(node[2*i+1],node[2*i+2]);
      }
    }
    void update(int x, int val){
      x += (n - 1);
      node[x] = val;
      while(x > 0){
        x = (x - 1) / 2;
        node[x] = min(node[2*x+1],node[2*x+2]);
      }
    }
    int getmin(int a, int b , int k = 0, int l = 0, int r = -1){
      if(r < 0){
        r = n;
      }
      if(r <= a || b <= l){
        return INF;
      }
      if(a <= l && r <= b){
        return node[k];
      }
      int vl = getmin(a,b,2*k+1,l,(l+r)/2);
      int vr = getmin(a,b,2*k+2,(l+r)/2,r);
      return min(vl,vr);
    }
};

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

int N,X;
vi m;
signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> N >> X;
  m.resize(N);
  rep(i,N){
    cin >> m[i];
  }
  int ret = N;
  X = X - accumulate(all(m),0);
  sort(all(m));
  ret += (X/m[0]);
  cout << ret << endl;
  return 0;
}
