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
#define INF 1e9
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(),(a).end()
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
vector<long long> A;
vector<long long> sum;

int main() {
    cin >> N; 
    A.resize(N); sum.resize(N+1); sum[0] = 0;
    for (int i = 0; i < N; ++i) cin >> A[i], sum[i+1] = sum[i] + A[i];

    long long res = 1LL<<60;
    for (int i = 0; i <= N; ++i) {
        int low = 0, high = i;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (sum[mid] >= sum[i] - sum[mid]) high = mid;
            else low = mid;
        }
        long long P = sum[low], Q = sum[i] - sum[low];
        long long P2 = sum[high], Q2 = sum[i] - sum[high];
        long long left_min = min(P, Q), left_max = max(P, Q);
        if (abs(P2-Q2) < abs(P-Q)) left_min = min(P2, Q2), left_max = max(P2, Q2);

        low = i, high = N;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (sum[mid] - sum[i] >= sum[N] - sum[mid]) high = mid;
            else low = mid;
        }
        long long R = sum[low] - sum[i], S = sum[N] - sum[low];
        long long R2 = sum[high] - sum[i], S2 = sum[N] - sum[high];
        long long right_min = min(R, S), right_max = max(R, S);
        if (abs(R2-S2) < abs(R-S)) right_min = min(R2, S2), right_max = max(R2, S2);

        long long tmp = max(left_max, right_max) - min(left_min, right_min);
        res = min(res, tmp);
    }
    cout << res << endl;
}
