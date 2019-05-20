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
#include<assert.h>

//macros and consts
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define accm accumulate
#define F first
#define S second
#define INF 1e9
#define mINF -1e9
#define endl "\n"

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
class Cpmath{
  public:
    template<typename T>
    static T gcd(T a, T b){
      if (a == 0) 
        return b; 
      return gcd(b % a, a); 
    }
    template<typename T>
    static T findGCD(vector<T> &arr, size_t n){
      T result = arr[0]; 
      for (size_t i = 1; i < n; i++) 
        result = gcd(arr[i], result); 
      return result; 
    }
    template<typename T>
    static bool is_prime(T n){
      if(n == 1){
        return false;
      }
      for(size_t i = 2 ; i <= pow(n,0.5) ; i++){
        if(n % i == 0){
          return false;
        }
      }
      return true;
    }
    static ll fact(ll n){
      if(n == 0){
        return 1LL;
      }
      else{
        return n * fact(n - 1);
      }
    }
    static ll permutation(int n, int r){
      assert(n >= r);
      ll ret = 1;
      for(int i = n ; i > n - r ; i--){
        ret *= i;
      }
      return ret;
    }
};

class NCR{
  private:
    static const int MAX = 210000;
    static const int MOD = 998244353;
    ll fac[MAX],finv[MAX],inv[MAX];
  public:
    void COMinit(){
      fac[0] = fac[1] = 1;
      finv[0] = finv[1] = 1;
      inv[1] = 1;
      for(int i = 2 ; i < MAX ; i++){
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
      }
    }
    ll COM(int n,int k){
      if(n < k) return 0;
      if(n < 0 || k < 0){
        return 0;
      }
      return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
    }
};
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
template<typename InputIt,typename T>
inline bool argexist(InputIt first,InputIt last,const T& x){
  if(std::find(first,last,x) != last){
    return true;
  }
  else{
    return false;
  }
}
template<typename InputIt,typename T>
inline int argfind(InputIt first, InputIt last, const T& x){
  auto it = find(first,last,x);
  return distance(first,it);
}
template<typename InputIt>
inline int argmax(InputIt first, InputIt last) {
    auto it = max_element(first, last);
    return distance(first, it);
}
template<typename InputIt>
inline int argmin(InputIt first, InputIt last) {
    auto it = min_element(first, last);
    return distance(first, it);
}
// you need sort before using this func
template<typename T>
inline void UNIQ(T& c) {
    c.erase(unique(begin(c), end(c)), end(c));
}
template<typename T>
inline T POP_BACK(vector<T>& que) {
    T x = que.back(); que.pop_back();
    return x;
}
template<typename T>
inline T POP_BACK(deque<T>& que) {
    T x = que.back(); que.pop_back();
    return x;
}
template<typename T>
inline T POP_FRONT(deque<T>& que) {
    T x = que.front(); que.pop_front();
    return x;
}
template<typename T, typename C>
inline T POP(stack<T,C>& stk) {
    T x = stk.top(); stk.pop();
    return x;
}
template<typename T, typename C>
inline T POP(queue<T,C>& que) {
    T x = que.front(); que.pop();
    return x;
}
template<typename T, typename Cont, typename Cmp>
inline T POP(priority_queue<T,Cont,Cmp>& que) {
    T x = que.top(); que.pop();
    return x;
}
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

int N;
vi A;
signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> N;
  A.eb(0);
  REP(i,N){
    int in;
    cin >> in;
    A.eb(in);
  }
  A.eb(0);
  ll sum = 0LL;
  REP(i,N+2){
    sum += abs(A[i] - A[i-1]);
  }
  FOR(i,1,N+1){
    cout << sum + abs(A[i+1] - A[i-1]) - abs(A[i] - A[i-1]) - abs(A[i+1] - A[i]) << endl;
  }
  return 0;
}
