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
#define size_t szt
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

signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int x1,y1,x2,y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int x3;
  int x4;
  int y3;
  int y4;

  x3 = x2 + (-1) * (y2 - y1);
  y3 = y2 + (x2 - x1);
  cout << x3 << " " << y3 << " ";
  x4 = x3 + (-1) * (y3 - y2);
  y4 = y3 + (x3 - x2);
  cout << x4 << " " << y4 << endl;

  return 0;
}
