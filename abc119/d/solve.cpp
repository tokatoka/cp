#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int A,B,Q;
vector<long long> s;
vector<long long> t;
vector<long long> x;
void chmin(long long &a, long long b) { if (a > b) a = b; }
template<class T> int former(const vector<T> &v, T x){
  return upper_bound(v.begin(),v.end(),x) - v.begin() - 1;
}
template<class T> int latter(const vector<T> &v, T x){
  return lower_bound(v.begin(),v.end(),x) - v.begin();
}
const long long INF = 1LL << 58;
int main(){
  cin >> A >> B >> Q;
  s.resize(A);
  t.resize(B);
  x.resize(Q);
  for(int i = 0;i<A;i++){
    cin >> s[i];
  }
  for(int i = 0;i<B;i++){
    cin >> t[i];
  }
  for(int i = 0;i<Q;i++){
    cin >> x[i];
  }
  s.push_back(INF);
  s.push_back(-INF);
  t.push_back(INF);
  t.push_back(-INF);
  sort(s.begin(),s.end());
  sort(t.begin(),t.end());

  
  for(int i=0;i<Q;i++){
    long long pos = x[i];
    long long res = INF;
    for(int j = 0;j<2;j++){
      long long first = (j? s[former(s,pos)] : s[latter(s,pos)]);
      for(int k = 0;k<2;k++){
        long long second = (k? t[former(t,first)] : t[latter(t,first)]);
        chmin(res,abs(pos-first)+abs(first-second));
      }
    }

    for(int j=0;j<2;j++){
      long long first = (j? t[former(t,pos)] : t[latter(t,pos)]);
      for(int k=0;k<2;k++){
        long long second = (k? s[former(s,first)] : s[latter(s,first)]);
        chmin(res,abs(pos-first) + abs(first-second));
      }
    }
    cout << res << endl;
  }
}
