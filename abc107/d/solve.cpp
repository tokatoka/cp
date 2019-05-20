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
#define repr(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
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
template<class T>
long long inversion(vector<T> &a) {
  int n = a.size();
  if (n <= 1)return 0;
  ll cnt = 0;
  vector<T> b(a.begin(), a.begin() + n / 2);
  vector<T> c(a.begin() + n / 2, a.end());
 
  cnt += inversion(b);
  cnt += inversion(c);
 
  int ai = 0, bi = 0, ci = 0;
 
  while (ai < n) {
    if (bi < b.size() && (ci == c.size() || b[bi] <= c[ci])) {
      a[ai] = b[bi];
      bi++;
    }
    else {
      cnt += n / 2 - bi;
      a[ai] = c[ci];
      ci++;
    }
    ai++;
  }
  return cnt;
}
 
long long count(vector<int> a, int k) {
    vector<int> b(N);
    vector<int> c(N + 1);
    vector<int> d(N + 1);
    rep(i, N) {
        if (a[i] <= k) b[i] = 1;
        else           b[i] = 0;
        c[i + 1] = c[i] + b[i];
        d[i + 1] = 2 * c[i + 1] - i;
    }
    c[0] = 0;
    d[0] = 0;
    repr(i, 1, N + 1){
        c[i] = c[i - 1] + b[i - 1];
        d[i] = 2 * c[i] - i;
    }
    reverse(all(d));
    return inversion(d);
}
 
 
int main(void) {
  cin >> N;
  vector<int> a(N);
  rep(i,N){
    cin >> a[i];
  }
 
  int ok = INF, ng = 0;
  while (ok - ng > 1) {
    int m = ng + (ok - ng) / 2;
    if (count(a, m) > (ll)N*(N + 1) / 4) {
      ok = m;
    }
    else {
      ng = m;
    }
  }
  cout << ok << endl;
}

