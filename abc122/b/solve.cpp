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
string S;

signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> S;
  int max = 0;
  int len = S.length();


  for(int i = 0; i < len ; i++ ){
    int tmp = 0;
    if(S[i] != 'A' && S[i] != 'T' && S[i] != 'G' && S[i] != 'C'){
      continue;
    }
    else{
      tmp++;
      for(auto j = i+1; j < len; j++){
        if(S[j] != 'A' && S[j] != 'T' && S[j] != 'G' && S[j] != 'C'){
          break;
        }
        tmp++;
      }
    }
    chmax(max,tmp);
  }
  cout << max << endl;

  return 0;
}
