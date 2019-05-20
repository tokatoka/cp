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

int n;
vector<int> v;
vector<int> counter1(200000,0);
vector<int> counter2(200000,0);
vector<int> counter3(200000,0);
vector<int> counter4(200000,0);
signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> n;
  v.resize(n);
  rep(i,n){
    cin >> v[i];
  }

  for(int i = 0 ; i < n ; i = i + 2){
    counter1[v[i]]++;
  }
  int max_itm1 = *max_element(counter1.begin(),counter1.end());
  int max_itm_idx = max_element(counter1.begin(),counter1.end()) - counter1.begin();
  for(int i = 1 ; i < n ; i = i + 2){
    if(v[i] == max_itm_idx){
      continue;
    }
    counter2[v[i]]++;
  }
  int max_itm2 = *max_element(counter2.begin(),counter2.end());
  int cand1 = n - max_itm1 - max_itm2;


  for(int i = 1 ; i < n ; i = i + 2){
    counter3[v[i]]++;
  }
  int max_itm3 = *max_element(counter3.begin(),counter3.end());
  int max_itm_idx3 = max_element(counter3.begin(),counter3.end()) - counter3.begin();
  for(int i = 0 ; i < n ; i = i + 2){
    if(v[i] == max_itm_idx3){
      continue;
    }
    counter4[v[i]]++;
  }
  int max_itm4 = *max_element(counter4.begin(),counter4.end());

  int cand2 = n - max_itm3 - max_itm4;

  cout << min(cand1,cand2) << endl;


  return 0;
}
