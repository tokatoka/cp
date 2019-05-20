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
int N,T;
vector<pair<int,int>> p;
bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
    return i.second < j.second;
}
signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> N >> T;
  for(int n = 0; n < N ; n++){
    int c,t;
    cin >> c >> t;
    if(t > T){
      continue;
    }
    p.emplace_back(make_pair(c,t));
  }
  sort(p.begin(),p.end());
  if(p.size() == 0){
    cout << "TLE" << endl;
  }
  else{
    cout << p[0].first << endl;
  }

}
