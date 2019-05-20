#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long N,A,B,C,D,E;
int main(){
  cin >> N >> A >> B >> C >> D >> E;
  vector<long long> data(5,0);
  data[0] = A;
  data[1] = B;
  data[2] = C;
  data[3] = D;
  data[4] = E;

  int min_idx = min_element(data.begin(),data.end()) - data.begin();
  long long min_v = data[min_idx];
  long long ret = 0;
  ret = 4 + (N + min_v - 1) / min_v;
  cout << ret << endl;
}
