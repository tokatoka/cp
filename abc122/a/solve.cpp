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
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;

signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  char b;
  cin >> b;

  if(b == 'A'){
    cout << 'T' << endl;
  }
  else if(b == 'T'){
    cout << 'A' << endl;
  }
  else if(b == 'G'){
    cout << 'C' << endl;
  }
  else{
    cout << 'G' << endl;
  }

  return 0;
}
